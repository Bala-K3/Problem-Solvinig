class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,int>up;
        for(int i=0;i<strs.size();i++)
        {
            string s = strs[i];

            sort(s.begin(),s.end());
            if(up.find(s) == up.end())
            {
                up[s] = res.size();
                res.push_back({});
            }
            res[up[s]].push_back(strs[i]);
        }
        return res;
    }
};