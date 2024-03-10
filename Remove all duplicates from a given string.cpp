class Solution
{
public:
	string removeDuplicates(string str) 
	{
	    map<char,int>mp;
	    string ans="";
	    for(auto x:str)
	    {
	        if(mp[x]>0)
	        {
	            
	        }
	        else
	        {
	            ans.push_back(x);
	            mp[x]++;
	        }
	    }
	    return ans;
	}
};
