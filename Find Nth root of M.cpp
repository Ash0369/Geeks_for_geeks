#define ll long long
int root(int n,int m)
{
    int diff=0;
    int low=1;
    int high=m;
    
    while(high-low>1)
    {
        ll int mid=(high+low)/2;
        //cout<<mid<<endl;
        if(pow(mid,n)==m)
        {
            return mid;
        }
        else if(pow(mid,n)>m)
        {
            high=mid;
        }
        else
        {
            low=mid;
        }
    }
    if(pow(low,n)==m)
    {
        return low;
    }
    if(pow(high,n)==m)
    {
        return high;
    }
    return -1;
}
class Solution
{
	public:
	int NthRoot(int n, int m)
	{
	    return root(n,m);
	}  
};
