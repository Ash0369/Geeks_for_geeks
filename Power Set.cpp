vector<string>ans;
class Solution
{
	public:
		vector<string> AllPossibleStrings(string s)
		{
		    ans.clear();
		    int n=s.size();
		    
		    int z=pow(2,n);
		    
		    for(int i=1;i<z;i++)
		    {
		        string p="";
		        int index=0;
		        int r=(z-1)&i;
		        
		        while(index<n && r)
		        {
		            if((r&1))
		            {
		                p.push_back(s[index]);
		                
		            }
		            r=r/2;
		            index++;
		        }
		        ans.push_back(p);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};
