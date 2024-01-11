class Solution {
  public:
    string removeKdigits(string s, int k)
    {
        int i=0;
        int n=s.size();
        while(i<n)
        {
            int cnt=0;
            int j=i;
            while(j<n && s[j]!='0')
            {
                j++;
                cnt++;
            }
            if(j<n && cnt<=k)
            {
                k=k-cnt;
                i=j;
                while(i<n && s[i]=='0')
                {
                    i++;
                }
                continue;
            }
            stack<vector<int>>st;
            string p;
            while(i<n)
            {
                p.push_back(s[i]);
                i++;
            }
            //cout<<p<<endl;
            int sz=p.size();
            
            
            vector<int>dp(sz+1,0);
            
            for(int i=0;i<sz;i++)
            {
                while(!st.empty() && k>0 && st.top()[0]>(p[i]-'0'))
                {
                    
                    dp[st.top()[1]]=1;
                    st.pop();
                    k--;
                }
                st.push({p[i]-'0',i});
            }
            while(k>0 && st.size()>0)
            {
                dp[st.top()[1]]=1;
                st.pop();
                k--;
            }
            string ans;
            for(int i=0;i<sz;i++)
            {
                if(dp[i]==0)
                {
                    ans.push_back(p[i]);
                }
            }
            if(ans.size()==0)
            {
                return "0";
            }
            return ans;
        }
        return "0";
    }
};
