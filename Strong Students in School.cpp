class Solution{
public:
    int diffSum(int n,int m,int arr[])
    {
        if(m==n)
        {
            return 0;
        }
        sort(arr,arr+n);
        int sum1=0;
        int sum2=0;
        for(int i=0;i<m;i++)
        {
            sum1+=arr[i];
        }
        for(int i=n-1;i>=n-m;i--)
        {
            sum2+=arr[i];
        }
        return sum2-sum1;
    }
};
