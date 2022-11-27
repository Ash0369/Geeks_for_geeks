class Solution 
{
  public:
    int arrayOperations(int n, vector<int> &arr) 
    {
        int cnt=0;
        bool taken=false;
        for(auto x:arr)
        {
            if(x==0 && taken)
            {
                cnt++;
                taken=false;
            }
            else if(x!=0)
            {
                taken=true;
            }
        }
        if(taken)
        {
            cnt++;
        }
        return min(2,cnt);
    }
};
