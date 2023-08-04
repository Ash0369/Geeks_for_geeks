void rev(int ele,stack<int>&st)
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }
    int x=st.top();
    st.pop();
    rev(ele,st);
    st.push(x);
}
class Solution
{
public:
    void Reverse(stack<int> &st)
    {
        if(st.size()==0)
        {
            return;
        }
        int ele=st.top();
        st.pop();
        Reverse(st);
        rev(ele,st);
    }
};
