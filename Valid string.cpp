class Solution 
{
  public:
    int validStrings(int n, int k, vector<string> &arr) 
    {
        int ans=0;
        for(auto x:arr)
        {
            int c=0;
            for(auto y:x)
            {
                if(y=='a' || y=='e' || y=='i' || y=='o' || y=='u')
                {
                    c++;
                }
            }
            if(c==k)
            {
                ans++;
            }
        }
        return ans;
    }
};
