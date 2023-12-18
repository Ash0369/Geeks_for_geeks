class Solution 
{
	public:
	int minOperations(vector<int> a, int n) 
	{
	    int mx=a[0];
	    for(int i=0;i<n;i++)
	    {
	        mx=max(mx,a[i]);
	    }
	    vector<int>vec;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]==mx)
	        {
	            vec.push_back(i);
	        }
	    }
	    int last=-10;
	    int curr=0;
	    int ans=0;
	    for(auto x:vec)
	    {
	        if(x==(last+1))
	        {
	            last=x;
	            curr++;
	            ans=max(ans,curr);
	        }
	        else{
	            curr=1;
	            ans=max(ans,curr);
	            last=x;
	        }
	    }
	    int z=vec.size();
	    return z-ans;
	}
};+
