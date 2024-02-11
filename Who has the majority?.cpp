class Solution{
  public:
    // Function to find element with more appearances between two elements in an
    // array.
    int majorityWins(int arr[], int n, int x, int y) 
    {
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        if(mp[x]>mp[y])
        {
            return x;
        }
        else if(mp[x]<mp[y])
        {
            return y;
        }
        return min(x,y);
    }
};
