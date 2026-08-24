class Solution {
public:
    bool isValid(string s, int n){
        int l=0;
        for(auto i:s){
            if(i=='(')
                l+=1;
            else
                l-=1;
            if(l<0)
                return 0;
        }
        if(l!=0) return 0;
        return 1;
    }
    void rec(int n, vector<string> &v, string &s, int l, int r){
        if(l==r && l==n){
            v.push_back(s);
            return;
        }
        if(l<n){
            s+='(';
            rec(n,v,s,l+1,r);
            s.pop_back();
        }
        if(r<l){
            s+=')';
            rec(n,v,s,l,r+1);
            s.pop_back();
        }
}
    vector<string> generateParenthesis(int n) {
        stack<char> st;
        vector<string> v;
        string s;
        rec(n,v,s,0,0);
        return v;

    }
};
