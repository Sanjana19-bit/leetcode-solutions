#include <vector>
#include <algorithm>

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
       
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int max_val = 0;
        for (int num : nums) {
            max_val = std::max(max_val, num);
        }

        
        int max_xor_limit = 1;
        while (max_xor_limit <= max_val) {
            max_xor_limit <<= 1;
        }

        
        std::vector<bool> seen_pairs(max_xor_limit, false);
        std::vector<bool> seen_triplets(max_xor_limit, false);

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                seen_pairs[nums[i] ^ nums[j]] = true;
            }
        }
        for (int p = 0; p < max_xor_limit; ++p) {
            if (seen_pairs[p]) {
                for (int num : nums) {
                    seen_triplets[p ^ num] = true;
                }
            }
        }
        int unique_triplets_count = 0;
        for (int t = 0; t < max_xor_limit; ++t) {
            if (seen_triplets[t]) {
                unique_triplets_count++;
            }
        }

        return unique_triplets_count;
    }
};
