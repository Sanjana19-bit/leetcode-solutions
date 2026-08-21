class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long totalSum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                totalSum += grid[i][j];
            }
        }
        if (totalSum % 2 != 0) {
            return false;
        }

        long long prefixSum = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                prefixSum += grid[i][j];
            }

            if (prefixSum * 2 == totalSum) {
                return true;
            }
        }

        prefixSum = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                prefixSum += grid[i][j];
            }

            if (prefixSum * 2 == totalSum) {
                return true;
            }
        }

        return false;
    }
};