class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};

        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        for (int a = 1; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                for (int c = 0; c <= 8; c += 2) {

                    freq[a]--;
                    freq[b]--;

                    if (freq[a] >= 0 && freq[b] >= 0 && freq[c] > 0) {
                        ans++;
                    }

                    freq[a]++;
                    freq[b]++;
                }
            }
        }

        return ans;
    }
};