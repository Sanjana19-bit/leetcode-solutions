class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {

        int rows = mat.size();
        int cols = mat[0].size();

        k %= cols;

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                int newCol;

                if (i % 2 == 0) {
                   
                    newCol = (j + k) % cols;
                }
                else {
        
                    newCol = (j - k + cols) % cols;
                }

                if (mat[i][j] != mat[i][newCol])
                    return false;
            }
        }

        return true;
    }
};