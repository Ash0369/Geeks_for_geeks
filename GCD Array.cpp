class Solution {
  public:
    int solve(int N, int K, vector<int> &arr) 
    {
        int sum=accumulate(arr.begin(),arr.end(),0);
        vector<int>divisor;
        
        for(int i=1;i<=(sqrt(sum)+1);i++)
        {
            if(sum%i==0)
            {
                divisor.push_back(i);
                if(i*i!=sum)
                {
                    divisor.push_back(sum/i);
                }
            }
        }
        
        //Prefix sum
        
        for(int i=1;i<N;i++)
        {
            arr[i]=arr[i]+arr[i-1];
        }
        
        int ans=1;
        
        for(auto g:divisor)
        {
            int partition=0;
            for(int i=0;i<N;i++)
            {
                if(arr[i]%g==0)
                {
                    partition++;
                }
            }
            if(partition>=K)
            {
                ans=max(ans,g);
            }
        }
        return ans;
    }
};
