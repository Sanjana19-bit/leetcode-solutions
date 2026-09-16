class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;

        int N = n + k - 1;
        int R = 2 * k;

        long long ans = 1;

        // Calculate C(N, R)
        for (int i = 1; i <= R; i++) {
            ans = ans * (N - R + i) % MOD;
            ans = ans * modInverse(i, MOD) % MOD;
        }

        return ans;
    }

private:
    long long modInverse(long long a, long long mod) {
        return power(a, mod - 2, mod);
    }

    long long power(long long a, long long b, long long mod) {
        long long result = 1;

        while (b > 0) {
            if (b & 1)
                result = result * a % mod;

            a = a * a % mod;
            b >>= 1;
        }

        return result;
    }
};