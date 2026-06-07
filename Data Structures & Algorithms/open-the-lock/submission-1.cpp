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
        unordered_set<string> mp;
        queue<string> q;
        q.push("0000");
        for(auto i:deadends){
            mp.insert(i);
        }
        if(mp.count("0000"))
            return -1;
        if(target=="0000")
            return 0;
        mp.insert("0000");
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
                    if(!mp.count(str)){
                        q.push(str);
                        mp.insert(str);
                    }
                    
                }
            }
        }
        
        return -1;
    }
};