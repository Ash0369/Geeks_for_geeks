#define ll long long
class Solution 
{
  public:
    long long countSubarray(int N, vector<int> &arr, int X, int K) 
    {
        int n=N;
        int i=0;
        int x=X;
        int j=0;
        int k=-1;
        int cnt=0;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==x)
            {
                if(cnt==0)
                {
                    cnt++;
                    j=i+1;
                    if(K==1)
                    {
                        k=i;
                        break;
                    }
                }
                else
                {
                    cnt++;
                    if(cnt==K)
                    {
                        k=i;
                        break;
                    }
                }
            }
            else if(cnt==0)
            {
                mp[arr[i]]++;
            }
            
        }
        if(k==-1)
        {
            return 0;
        }
      //  cout<<mp[2]<<endl;
        //cout<<j<<" "<<k<<endl;
        ll int ans=1;
        int mod=1e9+7;
        for(int i=k+1;i<n;i++)
        {
            if(arr[i]!=x)
            {
                
                ans=(ans+mp[arr[i]])%mod;
            }
            else
            {
                mp.clear();
                while(j<i && arr[j]!=x)
                {
                    
                    mp[arr[j]]++;
                    j++;
                }
                j++;
                ans=(ans+1)%mod;
            }
        }
        return ans;
    
    }
};
