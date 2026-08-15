class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return 0;
        int n=s2.size();
        vector<int> v1(26,0),v2(26,0);
        for(int i=0;i<s1.size();i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        int m = 0;
        for(int i=0;i<26;i++){
            if(v1[i]==v2[i]) m++;
        }
        int i=0,j=s1.size();
        while(j<n){
            if(m==26)
                return 1;
            int ind = s2[j]-'a';
            v2[ind]++;
            if(v1[ind]==v2[ind])
                m++;
            else if(v1[ind] + 1 == v2[ind])
                m--;
            j++;
            ind = s2[i] - 'a';
            v2[ind]--;
            if(v1[ind]==v2[ind])
                m++;
            else if(v1[ind]-1==v2[ind])
                m--;
            i++;
        }
        return m==26;
    }
};
