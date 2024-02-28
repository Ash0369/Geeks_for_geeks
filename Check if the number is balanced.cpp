class Solution{
public:	
	bool balancedNumber(string s)
	{
	    int n=s.size();
	    
	    int m=n/2;
	    
	    int tot1=0;
	    int tot2=0;
	    
	    
	    for(int i=0;i<m;i++)
	    {
	        tot1+=s[i]-'0';
	    }
	    for(int i=m+1;i<n;i++)
	    {
	        tot2+=s[i]-'0';
	    }
	    
	    return tot1==tot2;
	}
};
