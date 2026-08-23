class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, ' ');

        char c = 'a';

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (c > 'z')
                    return "";

                for (int j = i; j < n; j++) {
                    if (lcp[i][j] > 0)
                        s[j] = c;
                }

                c++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int common = 0;

                while (i + common < n &&
                       j + common < n &&
                       s[i + common] == s[j + common]) {
                    common++;
                }

                if (common != lcp[i][j])
                    return "";
            }
        }

        return s;
    }
};