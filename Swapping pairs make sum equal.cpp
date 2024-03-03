#define ll long long
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        ll int tot1=0;
        ll int tot2=0;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            tot1+=A[i];
        }
        for(int i=0;i<m;i++)
        {
            mp[B[i]]=1;
            tot2+=B[i];
        }
        
        for(int i=0;i<n;i++)
        {
            ll int curr1=tot1-A[i];
            ll int curr2=tot2+A[i];
            
            ll int d=curr2-curr1;
            if(d%2!=0)
            {
                continue;
            }
            d=d/2;
            if(mp[d])
            {
                return true;
            }
        }
        return -1;
	}
 

};
