class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(vector<int>& piles, int i, int M) {
        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        for (int x = 1; x <= min(2 * M, n - i); x++) {
            int opponent = solve(piles, i + x, max(M, x));

            // Total stones remaining - opponent best score
            int current = suffix[i] - opponent;

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(piles, 0, 1);
    }
};