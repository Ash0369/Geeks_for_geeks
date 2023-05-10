class Solution
{
public:
    int totalCuts(int N,int K,vector<int> &A)
    {
        int n=N;
        int k=K;
        vector<int>suf(n+1,0);
        suf[n]=1e7;
        for(int i=n-1;i>=0;i--)
        {
            suf[i]=min(suf[i+1],A[i]);
        }
        int mx=0;
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            mx=max(mx,A[i]);
            if(mx+suf[i+1]>=k)
            {
                ans++;
            }
        }
        return ans;
    }
};
