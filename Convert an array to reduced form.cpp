class Solution
{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) 
	{
	    map<int,int>mp;
	    for(int i=0;i<n;i++)
	    {
	        mp[arr[i]]=i;
	    }
	    int reduced=0;
	    for(auto x:mp)
	    {
	        arr[x.second]=reduced;
	        reduced++;
	    }
	}

};
