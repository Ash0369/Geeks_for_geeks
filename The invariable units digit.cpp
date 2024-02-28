class Solution
{
  public:
    bool unitDigit(string N, int P)
    {
    	int b=N.back()-'0';
    	int tot=1;
    	
    	while(P--)
    	{
    	    tot=tot*b;
    	    tot=tot%10;
    	}
    	return tot==b;
    }

};
