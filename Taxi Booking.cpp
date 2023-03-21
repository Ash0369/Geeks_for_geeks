class Solution
{
public:
    int minimumTime(int N,int cur,vector<int> &pos,vector<int> &time)
    {
        int n=N;
        int ans=1e9;
        for(int i=0;i<n;i++)
        {
            int d=abs(cur-pos[i])*time[i];
            ans=min(ans,d);
        }
        return ans;
    }
};
