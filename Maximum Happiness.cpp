class Solution 
{
  public:
    int maxHappy(int n, vector<int> &b, int m, vector<int> &r) 
    {
        sort(b.begin(),b.end());
        sort(r.begin(),r.end());
        int i=0;
        int j=0;
        int ans=0;
        while(i<n && j<m)
        {
            if(b[i]>=r[j])
            {
                i++;
                j++;
                ans++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
