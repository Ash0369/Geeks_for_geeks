bool f(stack<char>&st)
{
    string s;
    while(st.size()>0 && s.size()<4)
    {
        s.push_back(st.top());
        st.pop();
    }
    if(s.size()==4 && s=="keeg")
    {
        return true;
    }
    while(s.size()>0)
    {
        st.push(s.back());
        s.pop_back();
    }
    return false;
}
class Solution {
  public:
    int makeStringEmpty(string s) {
        stack<char>st;
        int ans=0;
        for(auto x:s)
        {
            st.push(x);
            if(f(st))
            {
                ans++;
            }
        }
        while(!st.empty())
        {
            if(f(st))
            {
                ans++;
            }
            else{
                break;
            }
        }
        if(st.size()>0)
        {
            return -1;
        }
        return ans;
    }
};
