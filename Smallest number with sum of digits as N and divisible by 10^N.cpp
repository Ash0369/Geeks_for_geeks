class Solution
{
	public:
	string digitsNum(int n)
	{
	    string res;
	    for(int i=0;i<n;i++)
	    {
	        res.push_back('0');
	    }
	    while(n>0)
	    {
	        res.push_back(min(n,9)+'0');
	        n=n-9;
	    }
	    reverse(res.begin(),res.end());
	    return res;
	    
	}
};
