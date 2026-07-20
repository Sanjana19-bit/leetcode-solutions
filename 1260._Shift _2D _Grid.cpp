#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        // Total number of elements
        int total = m * n;

        // Extra shifts are unnecessary
        k = k % total;

        vector<vector<int>> result(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Convert 2D index to 1D index
                int oldIndex = i * n + j;

                // Find new position after k shifts
                int newIndex = (oldIndex + k) % total;

                // Convert 1D index back to 2D index
                int newRow = newIndex / n;
                int newCol = newIndex % n;

                result[newRow][newCol] = grid[i][j];
            }
        }

        return result;
    }
};


int main() {

    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int k = 1;

    Solution obj;

    vector<vector<int>> result = obj.shiftGrid(grid, k);

    // Print the result
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}