class Solution 
{
  public:
    int minElements(int n, int m, vector<int> &arr1, vector<int> &arr2) 
    {
        int tot=0;
        for(auto x:arr1)
        {
            tot+=x;
        }
        sort(arr2.begin(),arr2.end());
        int ans=0;
        
        while(tot>0)
        {
            if(arr2.size()==0)
            {
                return -1;
            }
            tot-=arr2.back();
            arr2.pop_back();
            ans++;
        }
        return ans;
    }
};
