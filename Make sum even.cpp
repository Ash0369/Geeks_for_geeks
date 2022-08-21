class Solution 
{
  public:
  #define ll long long int
    bool makeEven(vector<int> arr) 
    {
        if(arr.size()%2!=0)
        {
            return false;
        }
        ll odd=0;
        ll even=0;
        
        for(auto x:arr)
        {
            if(x%2==0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        
        if(odd%2!=0)
        {
            return false;
        }
        return true;
    }
};
