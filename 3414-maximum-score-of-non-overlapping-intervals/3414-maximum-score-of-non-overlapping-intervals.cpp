class Solution {
public:
    vector<vector<int>> a;
    vector<int> starts;
    vector<vector<pair<long long, vector<int>>>> dp;

    pair<long long, vector<int>> solve(int i, int k) {
        if (i == a.size() || k == 4) {
            return {0, {}};
        }

        if (dp[i][k].first != -1) {
            return dp[i][k];
        }

        // Don't take current interval
        auto skip = solve(i + 1, k);

        // Take current interval
        int next = upper_bound(
            starts.begin(),
            starts.end(),
            a[i][1]
        ) - starts.begin();

        auto nxt = solve(next, k + 1);

        long long takeScore = a[i][2] + nxt.first;

        vector<int> takeIndices = nxt.second;
        takeIndices.push_back(a[i][3]);

        sort(takeIndices.begin(), takeIndices.end());

        pair<long long, vector<int>> take = {
            takeScore,
            takeIndices
        };

        if (take.first > skip.first) {
            dp[i][k] = take;
        }
        else if (take.first < skip.first) {
            dp[i][k] = skip;
        }
        else {
            if (take.second < skip.second)
                dp[i][k] = take;
            else
                dp[i][k] = skip;
        }

        return dp[i][k];
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        a.clear();

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        starts.clear();

        for (auto &x : a) {
            starts.push_back(x[0]);
        }

        dp.assign(
            n,
            vector<pair<long long, vector<int>>>(
                4,
                {-1, {}}
            )
        );

        return solve(0, 0).second;
    }
};