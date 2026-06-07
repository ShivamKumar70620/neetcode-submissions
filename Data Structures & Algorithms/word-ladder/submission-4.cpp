class Solution {
public:
    bool checkWords(string word, string target){
        int c = 0;
        for(int i=0;i<word.size();i++){
            if(word[i]!=target[i])
                c+=1;
            if(c>1)
                return false;
        }
        if(c>1)
            return false;
        return true;
    }
    int ladderLength(string bW, string eW, vector<string>& wordList) {
        int n = wordList.size();
        if(bW.size()!=eW.size())
            return 0;
        int ind = -1;
        for(int i=0;i<n;i++){
            if(eW==wordList[i])
            {
                ind = i;
                break;
            }
        }
        if(ind==-1)
            return 0;
        if(bW.size()==1 || checkWords(bW,eW))
            return 2;
        vector<int> adj[n];
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                string x = wordList[i];
                string y = wordList[j];
                if(i!=j && checkWords(x,y) && bW!=x && bW!=y && bW.size()==x.size() && bW.size()==y.size())
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        queue<int> q;
        q.push(ind);
        int steps = 2;
        while(!q.empty()){
            if(adj[q.front()].size()==0)
                return 0;
            steps++;
            int size = q.size();
            for(int i=0;i<size;i++){
                int front = q.front();
                q.pop();
                vis[front] = true;
                for(auto j:adj[front]){
                    // cout<<wordList[j]<<" "<<steps<<endl;
                    if(checkWords(bW,wordList[j]))
                        return steps;
                    if(!vis[j]){
                        q.push(j);
                    }
                }
            }
        }
        return 0;
        
    }
};
