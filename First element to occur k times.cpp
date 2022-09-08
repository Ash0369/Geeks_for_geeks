class Solution
{
    public:
    int firstElementKTime(int a[], int n, int k)
    {
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]=mp[a[i]]+1;
            if(mp[a[i]]>=k)
            {
                return a[i];
            }
        }
        return -1;
    }
};
