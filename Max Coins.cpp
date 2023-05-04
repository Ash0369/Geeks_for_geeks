bool cmp(vector<int>&v1,vector<int>&v2)
{
    if(v1[0]<v2[0])
    {
        return true;
    }
    if(v1[0]==v2[0])
    {
        return v1[1]<v2[1];
    }
    return false;
}
class Solution
{
public:
    int maxCoins(int n,vector<vector<int>> &ranges)
    {
        sort(ranges.begin(),ranges.end(),cmp);
        vector<int>mx(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            mx[i]=max(mx[i+1],ranges[i][2]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int start=ranges[i][0];
            int end=ranges[i][1];
            int low=i;
            int high=n-1;
            int index=high;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(ranges[mid][0]>=end)
                {
                    high=mid-1;
                    index=mid;
                }
                else
                {
                    low=mid+1;
                }
            }
            
            int temp=ranges[i][2];
            if(i==index)
            {
                index++;
            }
            if(index<n && ranges[index][0]>=end)
            {
                temp+=mx[index];
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};
