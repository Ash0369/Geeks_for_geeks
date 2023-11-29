class Solution
{
public:
    int subarraySumK(vector<int> &a, int n, int k)
    {
        int sum=0;
        int ans=1e6;
        int elft=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            while(sum>=k)
            {
                ans=min(ans,i-elft+1);
                sum=sum-a[elft];
                elft++;
            }
        }
        if(ans==1e6)
        {
            return -1;
        }
        return ans;
    }
};
