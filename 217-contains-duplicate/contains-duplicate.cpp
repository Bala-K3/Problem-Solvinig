class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int i = 0, j = 1;

        while(i < nums.size() && j < nums.size()) {
            if(nums[i] == nums[j]) return true;
            i++, j++;
        }
        // if(nums[i] == nums[j]) return true;
        return false;
    }
};