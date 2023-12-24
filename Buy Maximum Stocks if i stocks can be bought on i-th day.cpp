class Solution 
{
public:
    int buyMaximumProducts(int n, int k, int price[])
    {
        vector<pair<int,int>>f;
        for(int i=0;i<n;i++)
        {
            f.push_back({price[i],i+1});
        }
        sort(f.begin(),f.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(k>=(1LL*f[i].second*f[i].first))
            {
                k=k-(f[i].second*f[i].first);
                ans+=f[i].second;
            }
            else{
                ans+=k/f[i].first;
                break;
            }
        }
        return ans;
    }
};
