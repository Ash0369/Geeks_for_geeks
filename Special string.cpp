#define ll long long
int mod=1000000007;

bool check(string &s)
{
    //cout<<s<<endl;
    if(s.size()==1)
    {
        return false;
    }
    int i=0;
    int j=s.size();
    j--;
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

ll int dp[105][4][30][30];
ll int dfs(int index,string &s,bool tight,int last,int plast)
{
    if(index==(int)s.size())
    {
        if(tight)
        {
            return 0;
        }
        return 1;
    }
    
    if(dp[index][tight][last][plast]!=-1)
    {
        return dp[index][tight][last][plast];
    }
    ll int ans=0;
    if(tight==false)
    {
       //put anything
       
       for(char i='a';i<='z';i++)
       {
           if(last!=26 && (i-'a')==last)
           {
                continue;
           }
           if(plast!=26 && (i-'a')==plast)
           {
                continue;
           }
           ans=(ans+dfs(index+1,s,tight,i-'a',last))%mod;
       }
    }
    else
    {
        //we can only put gretaer
        char c=s[index];
        for(char i=c;i<='z';i++)
        {
            if(last!=26 && (i-'a')==last)
            {
                 continue;
            }
            if(plast!=26 && (i-'a')==plast)
            {
                 continue;
            }
            ans=(ans+dfs(index+1,s,i==c,i-'a',last))%mod;
        }
    }
    return dp[index][tight][last][plast]=ans;
}
class Solution 
{
  public:
    int specialStrings(int N, string S) 
    {
        memset(dp,-1,sizeof(dp));
        int n=N;
        string s=S;
        return dfs(0,s,true,26,26);
        
    }
};
