class Solution{   
public:
    long long int totalWays(int N)
    {
        #define ll long long
        
        ll int ans=1;
        for(int i=1;i<=N;i++)
        {
            ans=ans*i;
        }
        return ans;
    }
};
