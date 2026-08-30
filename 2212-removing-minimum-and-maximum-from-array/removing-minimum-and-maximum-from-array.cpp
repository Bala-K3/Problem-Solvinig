class Solution {
public:
    int minimumElement(vector<int> &nums)  {
        int mini = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < mini) {
                mini = nums[i];
            }
        }

        return mini;
    }
    int maximumElement(vector<int> &nums)  {
        int maxi = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
            }
        }

        return maxi;
    }

    int minimumDeletions(vector<int>& nums) {
        int mini = minimumElement(nums);
        int maxi = maximumElement(nums);
        int minIndex = 0, maxIndex = 0, n = nums.size();

        for(int i = 0; i < nums.size(); i++) {
            if(mini == nums[i]) minIndex = i;
            if(maxi == nums[i]) maxIndex = i;
        }

        if(minIndex > maxIndex) swap(minIndex, maxIndex);

        int left = maxIndex + 1, right = n - minIndex, both = (minIndex + 1) + (n - maxIndex);

        return min({left, right, both});
    }
};