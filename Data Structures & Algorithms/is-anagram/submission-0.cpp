class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length())
            return false;
        int n = s.length();
        vector<int> us(26,0);
        for(int i=0;i<n;i++){
            us[s[i]-'a']++;
            us[t[i]-'a']--;
        }
        for(auto i:us){
            if(i!=0)
                return false;
        }
        return true;
    }
};
