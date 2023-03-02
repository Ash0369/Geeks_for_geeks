//Methd-1 : Give TLE 1060 Case

#define ll long long
ll int color(int index,vector<vector<int>>&costs,int last,vector<vector<ll int>>&dp)
{
    int n=costs.size();
    int k=costs[0].size();
    if(index==n)
    {
        return 0;
    }
    if(dp[index][last]!=-1)
    {
        return dp[index][last];
    }
    ll int cst=1e15;
    for(int i=0;i<k;i++)
    {
        if(last==i)
        {
            continue;
        }
        cst=min(cst,costs[index][i]+1LL*color(index+1,costs,i,dp));
    }
    return dp[index][last]=cst;
}
class Solution
{
public:
    int minCost(vector<vector<int>>&costs) 
    {
        int n=costs.size();
        int k=costs[0].size();
        vector<vector<ll int>>dp(n+1,vector<ll int>(k+2,-1));
        ll int price=color(0,costs,k,dp);
        if(price>=1e15)
        {
            return -1;
        }
        return price;
    }
};

//Method-2 : 

#define ll long long
class Solution
{
public:
    int minCost(vector<vector<int>>&costs) 
    {
        int n=costs.size();
        int k=costs[0].size();
        vector<vector<ll int>>dp(n+1,vector<ll int>(k+2,-1));
        ll int mc1=1e18;
        ll int mc2=1e18;
        int index1=-1;
        int index2=-1;
        for(int j=0;j<k;j++)
        {
            if(costs[n-1][j]<=mc1)
            {
                swap(mc1,mc2);
                swap(index1,index2);
                mc1=costs[n-1][j];
                index1=j;
            }
            else if(costs[n-1][j]<=mc2)
            {
                mc2=costs[n-1][j];
                index2=j;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            ll int mcc1=1e18;
            ll int mcc2=1e18;
            int new_index1=-1;
            int new_index2=-1;
            bool got=true;
            for(int j=0;j<k;j++)
            {
                if(index1!=j)
                {
                    ll int cost1=mc1+costs[i][j];
                    if(cost1<=mcc1)
                    {
                        swap(mcc1,mcc2);
                        swap(new_index1,new_index2);
                        mcc1=cost1;
                        new_index1=j;
                    }
                    else if(cost1<=mcc2)
                    {
                        mcc2=cost1;
                        new_index2=j;
                    }
                }
                else
                {
                    ll int cost1=mc2+costs[i][j];
                    if(cost1<=mcc1)
                    {
                        swap(mcc1,mcc2);
                        swap(new_index1,new_index2);
                        mcc1=cost1;
                        new_index1=j;
                    }
                    else if(cost1<=mcc2)
                    {
                        mcc2=cost1;
                        new_index2=j;
                    }
                }
                
               
            }
            mc1=mcc1;
            mc2=mcc2;
            index1=new_index1;
            index2=new_index2;
        }
        
        if(mc1!=1e18)
        {
            return mc1;
        }
        if(mc2!=1e18)
        {
            return mc2;
        }
        return -1;
    }
};
