bool cmp(string &a,string &b)
{
    string p=a+b;
    string q=b+a;
    
    if(p>q)
    {
        return true;
    }
    return false;
}
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(int n, vector<string> &vec) {
	    
        sort(vec.begin(),vec.end(),cmp);
        string ans="";
        for(auto x:vec)
        {
            ans+=x;
        }
        reverse(ans.begin(),ans.end());
        
        while(ans.size()>1 && ans.back()=='0')
        {
            ans.pop_back();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
	}
};
