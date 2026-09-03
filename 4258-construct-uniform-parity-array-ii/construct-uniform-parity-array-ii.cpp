class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool res1 = false, res2 = false;
        int mini = *min_element(nums1.begin(), nums1.end());

        if(mini % 2 == 1) res1 = true;

        int count = 0;
        for(int n : nums1) {
            if(n % 2 == 0) count++;
        }

        res2 = count == (nums1.size());

        return res1 || res2;
    }
};