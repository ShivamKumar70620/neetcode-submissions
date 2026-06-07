class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> mp;
        int n = s.size();
        if(n==0)
            return 0;
        int i=0,mx = 0;
        for(int j=0;j<n;j++){
            while(mp.find(s[j])!=mp.end()){
                mp.erase(s[i]);
                i++;
            }
            mp.insert(s[j]);
            mx = max(mx,j-i+1);
            
        }
        
        return mx;
    }
};
