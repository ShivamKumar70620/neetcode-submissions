class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        
        vector<int> v;
        // cout<<left.size()<<" "<<right.size()<<endl;
        for(auto i:ast){
            while(!v.empty() && i<0 && v.back()>0){
                int diff = i + v.back();
                if(diff>0){
                    i = 0;
                }
                else if(diff<0){
                    v.pop_back();
                }
                else{
                    i = 0;
                    v.pop_back();
                }
            }
            if(i!=0) v.push_back(i);
        }
            
        return v;
    }
};