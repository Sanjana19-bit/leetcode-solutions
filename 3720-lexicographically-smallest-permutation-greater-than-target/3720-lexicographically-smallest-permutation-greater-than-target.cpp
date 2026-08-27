class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};

        for (char c : s)
            cnt[c - 'a']++;

        string ans = "";

        for (int i = 0; i < target.size(); i++) {
            int x = target[i] - 'a';

            // Try to put target[i]
            if (cnt[x] > 0) {
                ans += target[i];
                cnt[x]--;
                continue;
            }

            // Cannot continue matching target.
            // Find the smallest character > target[i]
            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    ans += char('a' + c);
                    cnt[c]--;

                    // Fill rest with smallest characters
                    for (int k = 0; k < 26; k++) {
                        while (cnt[k] > 0) {
                            ans += char('a' + k);
                            cnt[k]--;
                        }
                    }

                    return ans;
                }
            }

            // No bigger character here.
            // We need to backtrack.
            break;
        }

        // Backtrack over already matched characters
        while (!ans.empty()) {
            char last = ans.back();
            ans.pop_back();

            cnt[last - 'a']++;

            int x = last - 'a';

            // Find smallest character bigger than last
            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    ans += char('a' + c);
                    cnt[c]--;

                    // Fill remaining characters
                    for (int k = 0; k < 26; k++) {
                        while (cnt[k] > 0) {
                            ans += char('a' + k);
                            cnt[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};