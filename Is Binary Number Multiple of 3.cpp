class Solution
{
public:	
		
	int isDivisible(string s)
	{
	    int r=0;
	    int n=s.size();
	    for(int i=n-1;i>=0;i--)
	    {
	        if(s[i]=='1')
	        {
	            if((n-i-1)%2==0)
	            {
	                r++;
	            }
	            else
	            {
	                r=r+2;
	            }
	        }
	    }
	    return r%3==0;
	}
};
