#define ll long long
bool binary_search(int mid,int k,int n,vector<int>&arr)
{
   ll int curr=0;
   for(int i=0;i<n;i++)
   {
       curr+=arr[i];
       if(curr<mid)
       {
           
       }
       else
       {
           if(curr%mid==0)
           {
               k--;
               curr=0;
           }
       }
   }
   return k<=0;
}
class Solution 
{
  public:
    int solve(int N, int K, vector<int> &arr) 
    {
        int n=N;
        int k=K;
        
        ll int right=0;
        for(int i=0;i<n;i++)
        {
            right+=arr[i];
        }
        ll int ans=1;
        for(ll int i=1;i<=sqrt(right);i++)
        {
            if((right%i)==0)
            {
                if(binary_search(i,k,n,arr))
                {
                    ans=max(ans,i);
                }
                if(binary_search(right/i,k,n,arr))
                {
                    ans=max(ans,right/i);
                }
            }
        }
        return ans;
    }
};
