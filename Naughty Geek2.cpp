class Solution{   
public:
    long long int totalWays(int n)
    {
        #define ll long long
        ll int ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=ans*i;
        }
        return ans;
    }
};
