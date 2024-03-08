class Solution{
public:	
	bool sameFreq(string s)
	{
	    map<char,int>mp;
	    for(auto x:s)
	    {
	        mp[x]++;
	    }
	    vector<int>st;
	    for(auto x:mp)
	    {
	        st.push_back(x.second);
	    }
	    sort(st.begin(),st.end());
	    int sz=st.size();
	    if(st[0]==st.back())
	    {
	        return true;
	    }
	    else if(st[sz-2]==st[0] && abs(st.back()-st[0])<=1)
	    {
	        return true;
	    }
	    return false;
	   
	}
};
