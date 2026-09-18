class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n), last(26, -1);

        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<string> ans;
        int prevEnd = -1;

        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';

            if (first[ch] != i)
                continue;

            int end = last[ch];
            bool valid = true;

            for (int j = i; j <= end; ++j) {
                int c = s[j] - 'a';

                // This character occurs before our proposed start.
                if (first[c] < i) {
                    valid = false;
                    break;
                }

                end = max(end, last[c]);
            }

            if (!valid)
                continue;

            if (i > prevEnd) {
                
                ans.push_back(s.substr(i, end - i + 1));
            } else {
                
                ans.back() = s.substr(i, end - i + 1);
            }

            prevEnd = end;
        }

        return ans;
    }
};