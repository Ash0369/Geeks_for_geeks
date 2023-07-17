class Solution 
{
	public:
		string FirstNonRepeating(string s)
		{
		    map<char,int>mp;
		    string ans;
		    
		    int i=0;
		    for(int j=0;j<s.size();j++)
		    {
		        mp[s[j]]++;
		        
		        while(i<j && mp[s[i]]>1)
		        {
		            i++;
		        }
		        
		        if(mp[s[i]]==1)
		        {
		            ans.push_back(s[i]);
		        }
		        else
		        {
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};
