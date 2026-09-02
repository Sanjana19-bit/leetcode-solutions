class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;

        for (int i = 0; i < numRows; i++) {
            vector<int> a(i + 1);

            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    a[j] = 1;
                else
                    a[j] = v[i - 1][j] + v[i - 1][j - 1];
            }

            v.push_back(a);
        }

        return v;
    }
};