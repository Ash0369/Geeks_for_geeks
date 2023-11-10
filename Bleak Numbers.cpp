class Solution
{
public:
	int is_bleak(int n)
	{
	    for(int i=n-1;i>=max(0,n-30);i--)
	    {
	        int b=__builtin_popcount(i);
	        if(i+b==n)
	        {
	            return false;
	        }
	    }
	     return true;
	}
};
