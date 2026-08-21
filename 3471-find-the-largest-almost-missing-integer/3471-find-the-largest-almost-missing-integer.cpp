class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1: k = 1
        if (k == 1) {
            int freq[51] = {0};

            for (int x : nums) {
                freq[x]++;
            }

            int ans = -1;

            for (int x = 0; x <= 50; x++) {
                if (freq[x] == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        // Case 2: k = n
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 3: 1 < k < n
        int ans = -1;

        // Check first element
        bool firstUnique = true;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[0]) {
                firstUnique = false;
                break;
            }
        }

        if (firstUnique) {
            ans = max(ans, nums[0]);
        }
        bool lastUnique = true;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[n - 1]) {
                lastUnique = false;
                break;
            }
        }

        if (lastUnique) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};