class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]] = i;
        }
        for(int i=1;i<words.size();i++){
            string x = words[i-1],y=words[i];
            // cout<<x<<" "<<y<<endl;
            bool flag = false;
            for(int j=0;j<min(x.size(),y.size());j++){
                // cout<<x[j]<<" "<<y[j]<<endl;
                if(mp[x[j]]!=mp[y[j]])
                {
                    if(mp[x[j]]<mp[y[j]]){
                        flag = true;
                        break;
                    }
                    else
                        return false;
                }
            }
            // cout<<flag<<endl;
            if(flag)
                continue;
            if(x.size()>y.size())
                return 0;
        }
        return 1;
    
    }
};