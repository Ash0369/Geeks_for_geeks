#define ll long long
class Solution 
{
public:

	long long int NoOfChicks(int n)
	{
	    ll int intial=1;
	    vector<ll int>vec;
	    vec.push_back(1);
	    ll int curr=1;
	    for(int i=2;i<=n;i++)
	    {
	        curr=3*intial;
	        vec.push_back(curr-intial);
	        intial=curr;
	        if(i>=6)
	        {
	            intial-=vec[i-6];
	        }
	    }
	    return curr;
	}
};
