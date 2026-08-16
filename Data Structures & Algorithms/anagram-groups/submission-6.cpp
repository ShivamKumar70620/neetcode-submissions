class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        map<string,vector<string>> mp; 
        for(auto i:strs){
            vector<int> temp(26,0);
            for(auto j:i){
                temp[j-'a']++;
            }
            string st = to_string(temp[0]);
            for(int j=1;j<26;j++) 
                st+= ','+to_string(temp[j]);
            mp[st].push_back(i);
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
