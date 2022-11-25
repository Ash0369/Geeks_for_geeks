//https://www.youtube.com/watch?v=-1G4kEhJ2dU

class Solution
{
public:
    #define ll long long
    long long dp[100][100];
    ll int ncr(int n,int r)
    {
        if(n<r)
        {
            return 0;
        }
        if(dp[n][r]!=-1)
        {
            return dp[n][r];
        }
        
        if(n==r || r==0)
        {
            return 1;
        }
        
        return dp[n][r]=ncr(n-1,r-1)+ncr(n-1,r);
    }
    long long count(long long x) 
    {
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<100;j++)
            {
                dp[i][j]=-1;
            }
        }
        ll int zero=0;
        ll int one=0;
        ll int ans=0;
        ll int position=0;
        while(x>0)
        {
            int a=1;
            if(x&1==1)
            {
                //Now we can fill at postion =zero+one (We alerdy removed Msb )
                //No of ones to fill one+1
                one++;
                //one C zero
                ans+=ncr(position,one);
            }
            else
            {
                zero++;
            }
            x=x>>1;
            position++;
        }
        return ans;
        return 0;
    }  
};
