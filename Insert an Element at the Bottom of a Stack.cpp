class Solution{
public:
    stack<int> insertAtBottom(stack<int> st,int x){
        stack<int>st1;
        while(st.size()>0)
        {
            st1.push(st.top());
            st.pop();
        }
        st1.push(x);
        while(st1.size()>0)
        {
            st.push(st1.top());
            st1.pop();
        }
        return st;
    }
};
