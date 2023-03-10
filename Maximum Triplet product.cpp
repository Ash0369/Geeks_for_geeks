#define ll long long
class Solution 
{
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	vector<ll int>pos;
    	vector<ll int>neg;
    	for(int i=0;i<n;i++)
    	{
    	    if(arr[i]>=0)
    	    {
    	        pos.push_back(arr[i]);
    	    }
    	    else
    	    {
    	        neg.push_back(arr[i]);
    	    }
    	}
    
    	sort(pos.begin(),pos.end(),greater<int>());
    	sort(neg.begin(),neg.end());

        ll int val1=-1e18;
        ll int val2=-1e18;
        ll int val3=-1e18;
        ll int val4=-1e18;
        int x=neg.size();
        if(pos.size()>=3)
        {
            val1=pos[0]*pos[1]*pos[2];
        }
        if(pos.size()>=1 && neg.size()>=2)
        {
            val2=pos[0]*neg[0]*neg[1];
        }
        if(pos.size()>=2 && neg.size()>=1)
        {
            val4=pos[pos.size()-1]*pos[pos.size()-2]*neg[x-1];
        }
        if(neg.size()>=3)
        {
            val3=neg[x-1]*neg[x-2]*neg[x-3];
        }
    	return max({val1,val2,val3,val4});
    }
};
