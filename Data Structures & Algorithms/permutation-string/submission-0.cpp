class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        int arr[26] = {0};
        if(m>n)
            return 0;
        int c = 0;
        for(auto i:s1){
            int ind = i - 'a';
            if(++arr[ind] == 1)
                ++c;
        }
        int i=0;
        
        while(i<n){
            int ind = s2[i] - 'a';
            if(--arr[ind] == 0){
                --c;
            }
            if(i>=m){
                int l = s2[i-m] - 'a';
                if(++arr[l]==1)
                    ++c;
            }
           
            if(c==0)
                return 1;
            i++;
        }
        return 0;
    }
};
