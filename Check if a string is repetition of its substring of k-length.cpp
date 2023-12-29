class Solution
{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    if(n%k!=0)
	    {
	        return 0;
	    }
	    
	    set<string>st;
	    int i=0;
	      while(i < n) {
	        int j = i + k;
	        string temp = "";
	        
	        for(int ind = i; ind < j; ind++)
	            temp += s[ind];
	            
	        st.insert(temp);
	        if(st.size() > 2)
	            return 0;
	            
	        i += k;
	    }
	    
	    return st.size() <= 2 ? 1 : 0; 
	}
};
