class Solution{
   public:
    void swap(long long int &a,long long int &b)
    {
        int c=a;
        a=b;
        b=c;
    }
    void rearrange(long long *arr, int n) 
    {
        if(n==1)
        {
            return;
        }
        
        int start=0;
        int end=n-1;
        int mx=arr[n-1]+1;
    
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                arr[i]+=(arr[end]%mx)*mx;
                end--;
            }
            else
            {
                arr[i]+=(arr[start]%mx)*mx;
                start++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            arr[i]=arr[i]/mx;
        }
      
    }
};
