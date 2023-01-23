class Solution 
{
  public:
    string removePair(string s) 
    {
        int n=s.size();
        stack<char>st;
        map<char,int>dp;
        string ans="";
        for(int i=0;i<n;i++)
        {
           char c=s[i];
           if(i<n && s[i]!=s[i+1])
           {
               if(!st.empty() && st.top()==c)
               {
                   st.pop();
                   continue;
               }
               st.push(c);
           }
           else
           {
               i++;
           }
          
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        if(ans.size()==0)
        {
            return "-1";
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
