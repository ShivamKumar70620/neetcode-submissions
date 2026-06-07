class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0,n=strs.size();
        string ans = "";
        while(true){
            if(i>strs[0].size())
                break;
            char x = strs[0][i];
            for(auto j:strs){
                if(j.size()<=i || j[i]!=x)
                    return ans;
            }
            ans +=x;
            i++;
        }
        return ans;
    }

};