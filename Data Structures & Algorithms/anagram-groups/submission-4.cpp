class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        map<vector<int>,vector<string>> mp; 
        for(auto i:strs){
            vector<int> temp(26,0);
            for(auto j:i){
                temp[j-'a']++;
            }
            mp[temp].push_back(i);
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
