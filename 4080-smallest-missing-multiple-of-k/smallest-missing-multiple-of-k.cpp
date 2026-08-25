class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int, bool> mp;

        for(int n : nums) {
            mp[n] = true;
        }

        int size = nums.size();
        vector<int> res = nums;
        sort(begin(res), end(res));
        int maxi = res[size - 1];

        for(int i = 1; i <= maxi + 1; i++) {
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