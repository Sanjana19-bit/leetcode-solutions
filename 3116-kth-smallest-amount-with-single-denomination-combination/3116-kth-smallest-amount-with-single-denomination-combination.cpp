class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countNumbers(long long x, vector<int>& coins) {

        int n = coins.size();
        long long count = 0;

        // All non-empty subsets
        for (int mask = 1; mask < (1 << n); mask++) {

            long long L = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    bits++;

                    L = lcm(L, coins[i]);

                    if (L > x)
                        break;
                }
            }

            if (L > x)
                continue;

            long long ways = x / L;

            // Odd number of elements -> add
            if (bits % 2 == 1)
                count += ways;

            // Even number of elements -> subtract
            else
                count -= ways;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long left = 1;

        long long right = 1LL * k * (*min_element(coins.begin(), coins.end()));

        while (left < right) {

            long long mid = left + (right - left) / 2;

            if (countNumbers(mid, coins) >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};