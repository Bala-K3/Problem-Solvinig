class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 1;
        while(j < nums.size()) {
            if(!nums[i] && nums[j]) {
                swap(nums[i], nums[j]);
                i++, j++;
            } else if(!nums[i] && !nums[j]) {
                j++;
            } else if(nums[i] && !nums[j]){
                i++;
            } else {
                i++, j++;
                
            }
        }
    }
};