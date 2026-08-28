class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        int cnt[26] = {};

        for (char c : s)
            cnt[c - 'a']++;

        // Check whether a palindrome is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Characters available for left half
        int half[26];

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        // Construct palindrome from left half
        auto build = [&](const string& left) {
            string ans = left;

            if (n % 2)
                ans += mid;

            for (int i = m - 1; i >= 0; i--)
                ans += left[i];

            return ans;
        };

        string t = target.substr(0, m);

        /*
            Try to construct target's left half exactly.
        */
        int rem[26];

        for (int i = 0; i < 26; i++)
            rem[i] = half[i];

        bool possible = true;

        for (char c : t) {
            int x = c - 'a';

            if (rem[x] == 0) {
                possible = false;
                break;
            }

            rem[x]--;
        }

        /*
            If target's left half can be formed,
            check the palindrome made from it.
        */
        if (possible) {
            string candidate = build(t);

            if (candidate > target)
                return candidate;
        }

        /*
            Now we need the smallest permutation of the
            half-characters that is STRICTLY greater than t.

            We find it exactly like "next permutation",
            but using frequency counts.
        */

        // Start again from the original half counts.
        for (int i = 0; i < 26; i++)
            rem[i] = half[i];

        // Match target prefix as far as possible.
        int i = 0;

        while (i < m && rem[t[i] - 'a'] > 0) {
            rem[t[i] - 'a']--;
            i++;
        }

        /*
            If we couldn't match t[i], first try to make
            THIS position bigger.
        */
        if (i < m) {
            int cur = t[i] - 'a';

            for (int c = cur + 1; c < 26; c++) {
                if (rem[c] == 0)
                    continue;

                string left = t.substr(0, i);
                left += char('a' + c);

                rem[c]--;

                // Smallest possible suffix
                for (int k = 0; k < 26; k++) {
                    while (rem[k] > 0) {
                        left += char('a' + k);
                        rem[k]--;
                    }
                }

                return build(left);
            }
        }

        /*
            Current position couldn't be made bigger.
            Backtrack through the already matched prefix.

            Example:
                target left = "ab"
                available  = "ab"

            We first try:
                a -> b
            giving "ba".
        */
        for (int j = i - 1; j >= 0; j--) {

            // Restore t[j]
            rem[t[j] - 'a']++;

            int cur = t[j] - 'a';

            // Smallest character > t[j]
            for (int c = cur + 1; c < 26; c++) {

                if (rem[c] == 0)
                    continue;

                string left = t.substr(0, j);
                left += char('a' + c);

                rem[c]--;

                // Fill remaining characters in sorted order
                for (int k = 0; k < 26; k++) {
                    while (rem[k] > 0) {
                        left += char('a' + k);
                        rem[k]--;
                    }
                }

                return build(left);
            }
        }

        return "";
    }
};