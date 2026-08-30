class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n / rows;

        string ans;

        // Start from every column in the first row
        for (int col = 0; col < cols; col++) {

            int r = 0;
            int c = col;

            // Move diagonally down-right
            while (r < rows && c < cols) {
                ans += encodedText[r * cols + c];

                r++;
                c++;
            }
        }

        // Remove extra spaces at the end
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};