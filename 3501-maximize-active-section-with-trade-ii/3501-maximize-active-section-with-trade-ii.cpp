class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int ones = count(s.begin(), s.end(), '1');

        vector<pair<int,int>> zeroGroups; // {start, length}
        vector<int> zeroGroupIndex(n, -1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0')
                    zeroGroups.back().second++;
                else
                    zeroGroups.push_back({i, 1});
            }
            zeroGroupIndex[i] = zeroGroups.empty() ? -1 : (int)zeroGroups.size() - 1;
        }

        int q = queries.size();
        vector<int> ans(q, ones);
        if (zeroGroups.empty()) return ans;

        int m = zeroGroups.size();
        vector<int> merge(max(m - 1, 0));
        for (int i = 0; i + 1 < m; ++i)
            merge[i] = zeroGroups[i].second + zeroGroups[i + 1].second;

        int LOG = merge.empty() ? 1 : (32 - __builtin_clz(merge.size())) + 1;
        vector<vector<int>> sp(LOG, vector<int>(merge.size(), 0));
        if (!merge.empty()) {
            sp[0] = merge;
            for (int k = 1; k < LOG; ++k)
                for (int j = 0; j + (1 << k) <= (int)merge.size(); ++j)
                    sp[k][j] = max(sp[k-1][j], sp[k-1][j + (1 << (k-1))]);
        }
        auto rangeMax = [&](int l, int r) { // inclusive, l<=r, valid indices
            int len = r - l + 1;
            int k = 31 - __builtin_clz(len);
            return max(sp[k][l], sp[k][r - (1 << k) + 1]);
        };

        for (int idx = 0; idx < q; ++idx) {
            int l = queries[idx][0], r = queries[idx][1];

            int left = (zeroGroupIndex[l] == -1) ? -1 :
                (zeroGroups[zeroGroupIndex[l]].second - (l - zeroGroups[zeroGroupIndex[l]].first));
            int right = (zeroGroupIndex[r] == -1) ? -1 :
                (r - zeroGroups[zeroGroupIndex[r]].first + 1);

            int endGroupForR = (s[r] == '1') ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1;
            int startAdj = zeroGroupIndex[l] + 1;
            int endAdj = endGroupForR - 1;

            int best = ones;

            if (s[l] == '0' && s[r] == '0' && zeroGroupIndex[l] + 1 == zeroGroupIndex[r]) {
                best = max(best, ones + left + right);
            } else if (startAdj <= endAdj) {
                best = max(best, ones + rangeMax(startAdj, endAdj));
            }

            if (s[l] == '0' && zeroGroupIndex[l] + 1 <= endGroupForR)
                best = max(best, ones + left + zeroGroups[zeroGroupIndex[l] + 1].second);

            if (s[r] == '0' && zeroGroupIndex[l] < zeroGroupIndex[r] - 1)
                best = max(best, ones + right + zeroGroups[zeroGroupIndex[r] - 1].second);

            ans[idx] = best;
        }

        return ans;
    }
};