class Solution {
public:
    vector<string> getNextComb(string &str){
        vector<string> v;
        for(int i=0;i<4;i++){
            char od = str[i];
            str[i] = (od=='0')?'9':(char)(od-1);
            v.push_back(str);
            str[i] = (od=='9')?'0':(char)(od+1);
            v.push_back(str);
            str[i] = od;
        }
        return v;
    }
    int openLock(vector<string>& deadends, string target) {
        map<string,int> mp;
        queue<string> q;
        q.push("0000");
        for(auto i:deadends){
            mp[i] = 1;
        }
        if(mp.find("0000")!=mp.end())
            return -1;
        if(target=="0000")
            return 0;
        mp["0000"] = 1;
        int steps = 0;
        while(!q.empty()){
            ++steps;
            int size = q.size();
            for(int i=0;i<size;i++){
                string top = q.front();
                q.pop();
                for(auto str: getNextComb(top)){
                    if(str==target)
                        return steps;
                    if(mp.find(str)==mp.end()){
                        q.push(str);
                        mp[str] = 1;
                    }
                    
                }
            }
        }
        
        return -1;
    }
};