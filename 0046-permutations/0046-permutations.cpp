class Solution {
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, int start) {
        
        // Base case
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        // Try every possible element at current position
        for (int i = start; i < nums.size(); i++) {
            
            // Choose
            swap(nums[start], nums[i]);

            // Explore
            backtrack(nums, result, start + 1);

            // Backtrack
            swap(nums[start], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        backtrack(nums, result, 0);

        return result;
    }
};