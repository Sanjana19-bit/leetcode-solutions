class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s(nums.begin(),nums.end());
        int n = nums.size();
        int mx = nums[0];
        for(int i=1; i<n; i++){
            mx = max(mx,nums[i]);
        }
        for(int i=1; i<=mx/2; i++){
            if(s.find(k*i)==s.end())
            return k*i;
        }
        return (mx/k + 1)*k;;
    }
};