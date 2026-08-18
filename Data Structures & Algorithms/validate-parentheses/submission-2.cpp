class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s){
            if(i=='{' || i=='(' || i=='['){
                st.push(i);
            }
            else if(i==']'){
                if(st.size()==0)
                    return 0;
                if(st.top()!='[') 
                    return 0;
                else
                    st.pop();
            }
            else if(i=='}'){
                if(st.size()==0)
                    return 0;
                if(st.top()!='{') 
                    return 0;
                else
                    st.pop();
            }
            else {
                if(st.size()==0)
                    return 0;
                if(st.top()!='(') 
                    return 0;
                else
                    st.pop();
            }
        }
        return st.size()>0?0:1;
    }
};
