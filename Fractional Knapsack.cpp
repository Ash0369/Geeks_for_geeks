bool cmp(pair<double,int>&p1,pair<double,int>&p2)
{
    if(p1.first>p2.first)
    {
        return true;
    }
    return false;
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        vector<pair<double,int>>vec;
        
        for(int i=0;i<n;i++)
        {
            double z=(1.000*arr[i].value)/arr[i].weight;
            vec.push_back({z,i});
        }
        sort(vec.begin(),vec.end(),cmp);
        
        double ans=0;
        
        for(int i=0;i<n;i++)
        {
            int index=vec[i].second;
            
            if(w>=(arr[index].weight))
            {
                w-=arr[index].weight;
                ans+=arr[index].value;
            }
            else{
                ans+=(vec[i].first*w);
                break;
            }
        }
        return ans;
    }
        
};
