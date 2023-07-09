int mod=1e9+7;
#define ll long long
ll int dp[201][201][15][4];
ll int dfs(int index,string &s,int mx,int last,int k,int op)
{
    int n=s.size();
 
    if(op<0)
    {
        return 0;
    }
    
    if(index==n)
    {
        return op==0;
    }
    if(dp[index][op][mx][last]!=-1)
    {
        return dp[index][op][mx][last];
    }
    int ans=0;
    
    if(s[index]=='?')
    {
       // cout<<index<<" "<<last<<" "<<mx<<" "<<op<<endl;
        //1 means )
        if(last==1 && mx==k)
        {
            //(
            ans+=dfs(index+1,s,1,0,k,op+1);
        }
        else if(last==0 && mx==k)
        {
            //)
            ans+=dfs(index+1,s,1,1,k,op-1);
        }
        else
        {
            if(last==1)
            {
                ans+=dfs(index+1,s,mx+1,1,k,op-1);
                ans+=dfs(index+1,s,1,0,k,op+1);
            }
            else if(last==0)
            {
                ans+=dfs(index+1,s,mx+1,0,k,op+1);
                ans+=dfs(index+1,s,1,1,k,op-1);
            }
            else
            {
                ans+=dfs(index+1,s,1,0,k,op+1);
                ans+=dfs(index+1,s,1,1,k,op-1);
            }
        }
        ans=ans%mod;
        return dp[index][op][mx][last]=ans;
    }
    else if(s[index]==')' && last==1)
    {
        if(mx==k)
        {
            return dp[index][op][mx][last]=0;
        }
        return dp[index][op][mx][last]=dfs(index+1,s,mx+1,last,k,op-1);
    }
    else if(s[index]==')' && last==0)
    {
        return dp[index][op][mx][last]=dfs(index+1,s,1,1,k,op-1);
    }
    else if(s[index]==')')
    {
        return dp[index][op][mx][last]=dfs(index+1,s,1,1,k,op-1);
    }
    else if(s[index]=='(' && last==1)
    {
        return dp[index][op][mx][last]=dfs(index+1,s,1,0,k,op+1);
    }
    else if(s[index]=='(' && last==0)
    {
        if(mx==k)
        {
            return dp[index][op][mx][last]=0;
        }
        return dp[index][op][mx][last]=dfs(index+1,s,mx+1,last,k,op+1);
    }
    else if(s[index]=='(')
    {
        return dp[index][op][mx][last]=dfs(index+1,s,1,0,k,op+1);
    }
}
class Solution{
public:
    int countStrings(int n,string &s,int k){
        memset(dp,-1,sizeof(dp));
        return dfs(0,s,0,2,k,0);
    }
};
