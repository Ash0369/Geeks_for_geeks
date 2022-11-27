class Solution
{
public:	
	string addBinary(string A, string B)
	{
	    string ans="";
	    int carry=0;
	    int i=A.length()-1;
	    int j=B.length()-1;
	    while(i>=0 && j>=0)
	    {
	        if(A[i]=='1' && B[j]=='1')
	        {
	            if(carry==1)
	            {
	                ans+="1";
	            }
	            else
	            {
	                ans+="0";
	                carry=1;
	            }
	            
	        }
	        else if(A[i]=='0' && B[j]=='0')
	        {
	            if(carry==1)
	            {
	                ans+="1";
	                carry=0;
	            }
	            else
	            {
	                ans+="0";
	            }
	            
	        }
	        
	        else if(A[i]=='1' ||  B[j]=='1')
	        {
	            if(carry==1)
	            {
	                ans+="0";
	            }
	            else
	            {
	                ans+="1";
	            }
	            
	        }
	        
	        i--;
	        j--;
	    }
	    
	    while(i>=0)
	    {
	        if(A[i]=='1' && carry==1)
	        {
	            ans+="0";
	        }
	        else if(A[i]=='1' && carry==0)
	        {
	            ans+="1";
	        }
	        
	        else if(A[i]=='0' && carry==1)
	        {
	            ans+="1";
	            carry=0;
	        }
	        else if(A[i]=='0' && carry==0)
	        {
	            ans+="0";
	        }
	        i--;
	    }
	    
	    while(j>=0)
	    {
	        if(B[j]=='1' && carry==1)
	        {
	            ans+="0";
	        }
	        else if(B[j]=='1' && carry==0)
	        {
	            ans+="1";
	        }
	        
	        else if(B[j]=='0' && carry==1)
	        {
	            ans+="1";
	            carry=0;
	        }
	        else if(B[j]=='0' && carry==0)
	        {
	            ans+="0";
	        }
	        j--;
	    }
	    
	    if(carry==1)
	    {
	        ans+="1";
	    }
	    i=ans.size()-1;
	    while(i>=0 && ans[i]=='0')
	    {
	        i--;
	    }
	    string s=ans.substr(0,i+1);
	    reverse(s.begin(),s.end());
	    return s;
	}
};
