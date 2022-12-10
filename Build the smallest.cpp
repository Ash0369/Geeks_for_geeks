string buildLowestNumber(string num, int k)
{
    string ans="";
    stack<char>st;
    for(int i=0;i<num.size();i++)
    {
        while(!st.empty() && st.top()>num[i] && k>0)
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    
    while(!st.empty() && k>0)
    {
        st.pop();
        k--;
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    while(ans.size()>=0 && ans[ans.size()-1]=='0')
    {
        ans.pop_back();
    }
    reverse(ans.begin(),ans.end());
    
    if(ans.size()==0)
    {
        ans.push_back('0');
    }
    return ans;
}
