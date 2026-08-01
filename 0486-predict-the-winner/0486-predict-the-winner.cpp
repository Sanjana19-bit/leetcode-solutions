class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: only one number is available
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        // Fill DP table
        for (int len = 2; len <= n; len++) {

            for (int left = 0; left + len - 1 < n; left++) {

                int right = left + len - 1;

                
                int takeLeft = nums[left] - dp[left + 1][right];

               
                int takeRight = nums[right] - dp[left][right - 1];

             
                dp[left][right] = max(takeLeft, takeRight);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};