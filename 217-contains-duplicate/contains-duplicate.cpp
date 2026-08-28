class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for(int n : nums) {
            mp[n]++;
        }
        for(const auto &m : mp) {
            if(m.second > 1) return true;
        }
        return false;
    }
};