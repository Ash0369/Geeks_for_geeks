class Solution
{
public:
    
    long long int numoffbt(long long int arr[], int n)
    {
        sort(arr,arr+n);
        long long int mi=arr[0];
        long long int ma=arr[n-1];
        
        vector<int>vec(ma+2,0);
        vector<bool>pre(ma+2,false);
        for(int i=0;i<n;i++)
        {
            vec[arr[i]]=1;
            pre[arr[i]]=true;
        }
        long long int ans=0;
        int mod=1000000007;
        for(int ele=mi;ele<=ma;ele++)
        {
            if(pre[ele]==false)
            {
                continue;
            }
            for(int j=2;j*j<=ele;j++)
            {
                int other=ele/j;
                if(ele%j==0 && pre[other]==true && pre[ele]==true)
                {
                    if(other==j)
                    {
                        vec[ele]+=vec[j]*vec[other];
                    }
                    else
                    {
                        vec[ele]+=vec[j]*vec[other]*2;
                    }
                }
                
            }
            ans=(ans+vec[ele])%mod;
        }
        return ans;
    }
};
