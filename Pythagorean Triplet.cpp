class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) 
	{
	    map<int,int>mp;
	    for(int i=0;i<n;i++)
	    {
	        mp[arr[i]*arr[i]]++;
	    }
	    for(auto x:mp)
	    {
	        int val=x.first;
	        mp[val]--;
	        for(int i=1;i<=1000;i++)
	        {
	            int val2=i*i;
	            if(mp.find(val2)!=mp.end() && mp[val2]>0)
	            {
	                int need=val+val2;
	                if(mp.find(need)!=mp.end())
	                {
	                    //cout<<val<<" "<<val2<<" "<<need<<endl;
	                    return true;
	                }
	            }
	        }
	        mp[val]++;
	    }
	    return false;
	}
};
