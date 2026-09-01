class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 1;
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            ans[i] = p;
            p *= nums[i];
        }
        p = 1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans[i] *= p;
            p *= nums[i];
        }
        return ans;
    }
};