#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // Calculates the minimum length needed to satisfy required factors
    int minLen(int c2, int c3, int c5, int c7) {
        int d9 = c3 / 2; c3 %= 2;
        int d8 = c2 / 3; c2 %= 3;
        int d6 = 0, d4 = 0, d3 = c3, d2 = c2;
        if (d3 == 1 && d2 == 1) { d6 = 1; d3 = 0; d2 = 0; }
        if (d2 == 2) { d4 = 1; d2 = 0; }
        return c7 + c5 + d9 + d8 + d6 + d4 + d3 + d2;
    }

    void addDigitFactors(char d, int& c2, int& c3, int& c5, int& c7, int sign) {
        int v = d - '0';
        while (v % 2 == 0 && v > 0) { c2 += sign; v /= 2; }
        while (v % 3 == 0 && v > 0) { c3 += sign; v /= 3; }
        if (v == 5) c5 += sign;
        if (v == 7) c7 += sign;
    }

    // Digit-by-digit greedy construction from left to right for minimum suffix
    string getMinSuffix(int c2, int c3, int c5, int c7, int target_len) {
        string res = "";
        for (int i = 0; i < target_len; i++) {
            int rem_len = target_len - 1 - i;
            for (int d = 1; d <= 9; d++) {
                int next_c2 = c2, next_c3 = c3, next_c5 = c5, next_c7 = c7;
                addDigitFactors('0' + d, next_c2, next_c3, next_c5, next_c7, -1);
                next_c2 = max(0, next_c2); next_c3 = max(0, next_c3);
                next_c5 = max(0, next_c5); next_c7 = max(0, next_c7);

                if (minLen(next_c2, next_c3, next_c5, next_c7) <= rem_len) {
                    res += to_string(d);
                    c2 = next_c2; c3 = next_c3; c5 = next_c5; c7 = next_c7;
                    break;
                }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        long long temp_t = t;
        while (temp_t % 2 == 0) { c2++; temp_t /= 2; }
        while (temp_t % 3 == 0) { c3++; temp_t /= 3; }
        while (temp_t % 5 == 0) { c5++; temp_t /= 5; }
        while (temp_t % 7 == 0) { c7++; temp_t /= 7; }

        if (temp_t > 1) return "-1"; // Unreachable prime factors

        int n = num.length();
        vector<int> p2(n + 1, 0), p3(n + 1, 0), p5(n + 1, 0), p7(n + 1, 0);
        int first_zero = n;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
            p2[i + 1] = p2[i]; p3[i + 1] = p3[i]; 
            p5[i + 1] = p5[i]; p7[i + 1] = p7[i];
            addDigitFactors(num[i], p2[i + 1], p3[i + 1], p5[i + 1], p7[i + 1], 1);
        }

        // Check if num itself works
        if (first_zero == n && p2[n] >= c2 && p3[n] >= c3 && p5[n] >= c5 && p7[n] >= c7) {
            return num;
        }

        // Try keeping prefix of length i
        for (int i = first_zero; i >= 0; i--) {
            int cur_c2 = max(0, c2 - (i > 0 ? p2[i] : 0));
            int cur_c3 = max(0, c3 - (i > 0 ? p3[i] : 0));
            int cur_c5 = max(0, c5 - (i > 0 ? p5[i] : 0));
            int cur_c7 = max(0, c7 - (i > 0 ? p7[i] : 0));

            int start_digit = (i < n) ? (num[i] - '0' + 1) : 1;

            for (int d = start_digit; d <= 9; d++) {
                int rem_c2 = cur_c2, rem_c3 = cur_c3, rem_c5 = cur_c5, rem_c7 = cur_c7;
                addDigitFactors('0' + d, rem_c2, rem_c3, rem_c5, rem_c7, -1);
                rem_c2 = max(0, rem_c2); rem_c3 = max(0, rem_c3);
                rem_c5 = max(0, rem_c5); rem_c7 = max(0, rem_c7);

                int req_len = minLen(rem_c2, rem_c3, rem_c5, rem_c7);
                int available_len = n - 1 - i;

                if (available_len >= req_len) {
                    string ans = num.substr(0, i);
                    ans += to_string(d);
                    ans += getMinSuffix(rem_c2, rem_c3, rem_c5, rem_c7, available_len);
                    return ans;
                }
            }
        }

        // If no number of length n works, construct smallest number of length max(n + 1, req_len)
        int req_len = minLen(c2, c3, c5, c7);
        int total_len = max(n + 1, req_len);
        return getMinSuffix(c2, c3, c5, c7, total_len);
    }
};