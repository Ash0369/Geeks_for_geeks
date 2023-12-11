class Solution 
{
  public:
    long long count101(long long n) 
    {
        #define ll long long
        
        string s="";
        while(n>0)
        {
            if(n&1LL)
            {
                s.push_back('1');
            }
            else{
                s.push_back('0');
            }
            n=n/2;
        }
        reverse(s.begin(),s.end());
        
        ll int ans=0;
        int sz=s.size();
        vector<int>dp1(sz+2,0);
        vector<int>dp2(sz+2,0);
        
        for(int i=0;i<sz;i++)
        {
            if(s[i]=='1')
            {
                dp1[i]=1;
            }
            if(i>0)
            {
                dp1[i]+=dp1[i-1];
            }
        }
        for(int i=sz-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                dp2[i]=1;
            }
            
            dp2[i]+=dp2[i+1];
            
        }
        for(int i=0;i<sz;i++)
        {
            if(s[i]=='0')
            {
                int a=0;
                int b=0;
                if(i>0)
                {
                    a=dp1[i-1];
                }
                b=dp2[i+1];
                ans+=1LL*a*b;
                
            }
        }
        return ans;
    }
};
