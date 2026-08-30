class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        vector<pair<int, int>> trackIndex;
        for(int ind = 0; ind < nums.size(); ind++) {
            trackIndex.push_back({nums[ind], ind});
        }
        sort(begin(trackIndex), end(trackIndex));
        while(i < j) {
            int sum = trackIndex[i].first + trackIndex[j].first;
            if(sum == target) {
                return {trackIndex[i].second, trackIndex[j].second};
            } else if(sum > target) {
                j--;
            } else {
                i++;
            }
        }
        return {};
    }
};