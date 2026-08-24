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
    void rec(int n, vector<string> &v, string s){
        if(s.size()==2*n){
            if(isValid(s,n)) v.push_back(s);
            return;
        }
        rec(n,v,s+'(');
        rec(n,v,s+')');
}
    vector<string> generateParenthesis(int n) {
        stack<char> st;
        vector<string> v;
        rec(n,v,"");
        return v;

    }
};
