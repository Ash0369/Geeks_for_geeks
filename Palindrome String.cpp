class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    string s=S;
	    reverse(S.begin(),S.end());
	    return S==s;
	}

};
