class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26,0);
        int i=0,j=0,n=s.size();
        int mx = 0,ans=0;
        while(j<n){
            v[s[j]-'A']++;
            mx = max(mx,v[s[j]-'A']);
            while((j-i+1)-mx>k){
                v[s[i]-'A']--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
