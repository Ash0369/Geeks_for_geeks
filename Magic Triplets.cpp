//Method-1 : Space Complexity O(n*n)

class Solution
{
	public:
	int countTriplets(vector<int>vec)
	{
	    int ans=0;
	    int n=vec.size();
	    unordered_map<int,vector<int>>mp;
	    for(int i=0;i<n;i++)
	    {
	        int bar=vec[i];
	        int cnt=0;
	        for(int j=i+1;j<n;j++)
	        {
	            if(vec[j]>bar)
	            {
	                mp[i].push_back(j);
	            }
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        auto v=mp[i];
	        for(auto x:v)
	        {
	            ans=ans+mp[x].size();
	        }
	    }
	    return ans;
	}
};


//Method-2 : In O(1) Space

class Solution
{
	public:
	int countTriplets(vector<int>vec)
	{
	    int ans=0;
	    int n=vec.size();
	    for(int i=0;i<n;i++)
	    {
	       int small=0;
	       int large=0;
	       
	       for(int j=i-1;j>=0;j--)
	       {
	           if(vec[j]<vec[i])
	           small++;
	       }
	       
	       for(int j=i+1;j<n;j++)
	       {
	           if(vec[j]>vec[i])
	           large++;
	       }
	       
	       ans=ans+(small*large);
	    }
	    
	   
	    return ans;
	}
};
