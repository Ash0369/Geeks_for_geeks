bool cmp(Job one,Job two)
{
    if(one.profit>two.profit)
    {
        return true;
    }
    return false;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int ans=0;
        int j=0;
        sort(arr,arr+n,cmp);
        vector<int>dp(100000,0);
        for(int i=0;i<n;i++)
        {
            Job curr=arr[i];
            for(int i=curr.dead;i>=1;i--)
            {
                if(dp[i]==0)
                {
                    dp[i]=1;
                    ans+=curr.profit;
                    j++;
                    break;
                }
            }
        }
        return {j,ans};
    } 
};
