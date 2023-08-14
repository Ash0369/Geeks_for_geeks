class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        //find the subarray having maximum value c , where c=no of zero-no of one
        
        int one=0;
        int zero=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                one++;
                zero--;
            }
            else
            {
                zero++;
            }
            ans=max(ans,zero);
            if(zero<0)
            {
                zero=0;
                
            }
            
        }
        return ans+one;
    }
};
