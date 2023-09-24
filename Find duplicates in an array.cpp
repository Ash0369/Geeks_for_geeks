class Solution{
  public:
    vector<int> duplicates(int vec[], int n) 
    {
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int ele=vec[i]%n;
            vec[ele]+=n;
        }
        for(int i=0;i<n;i++)
        {
            if(vec[i]/n>1)
            {
                ans.push_back(i);
            }
        }
        if(ans.size()==0)
        {
            ans.push_back(-1);
        }
        return ans;
    }
};
