class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int count = 0;
        sort(begin(nums), end(nums));
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] == nums[i]) count++;
        }
        return count;
    }
};