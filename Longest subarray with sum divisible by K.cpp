class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    #define ll long long
	    map<ll int,int>mp;
	    map<ll int,int>a;
	    ll int tot=0;
	    mp[0]=-1;
	    a[0]=-1;
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        tot+=arr[i];
	        ll int r=abs(tot)%k;
	
	        if(tot>=0)
	        {
	            
	            if(mp.find(r)!=mp.end())
	            {
	                ans=max(ans,i-mp[r]);
	            }
	            if(a.find(k-r)!=a.end())
	            {
	                //cout<<i<<endl;
	                ans=max(ans,i-a[k-r]);
	            }
	        }
	        if(tot<=0)
	        {
	            if(a.find(r)!=a.end())
	            {
	                ans=max(ans,i-a[r]);
	            }
	            if(mp.find(k-r)!=mp.end())
	            {
	                ans=max(ans,i-mp[k-r]);
	            }
	        }
	        
	        if(tot>=0)
	        {
	             if(mp.find(r)==mp.end())
	             {
	                 mp[r]=i;
	             }
	        }
	        if(tot<=0)
	        {
	            //cout<<r<<endl;
	             if(a.find(r)==a.end())
	             {
	                 a[r]=i;
	             }
	        }
	       
	        
	    }
	    return ans;
	}
};
