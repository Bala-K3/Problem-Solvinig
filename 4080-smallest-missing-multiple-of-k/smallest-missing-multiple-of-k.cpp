class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int, bool> mp;

        for(int n : nums) {
            mp[n] = true;
        }


        for(int i = 1; i <= 101; i++) {
            int c = i * k;
            mp[c];
        }

        for(const auto& pair : mp) {
            if(!pair.second) {
                return pair.first;
            }
        }

        return k;
    }
};