class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        int n=N;
        sort(arr,arr+n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt=1;
            int prev=arr[i];
            i++;
            while(i<n && (arr[i]==prev+1 ||arr[i]==prev))
            {
                if(arr[i]==prev)
                {
                    i++;
                    continue;
                }
                prev=arr[i];
                i++;
                cnt++;
            }
            i--;
            ans=max(ans,cnt);
        }
        return ans;
    }
};
