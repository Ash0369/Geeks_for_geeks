class Solution 
{
  public:
    bool isMagicArray(int n, vector<int> &arr) 
    {
        for(int i=1;i<n;i++)
        {
            if((arr[i]%2)==(arr[i-1]%2))
            {
                return false;
            }
        }
        return true;
    }
};
