//Method-1 : Linear Search

class Solution
{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x)
    {
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(v[i]<=x)
            {
                ans=i;
            }
        }
        return ans;
    }
};

//Method-2 : Binary Search


int binary_search(vector<long long>&v, long long n, long long x,int l,int r)
{
    if(l>r)
    {
        return r;
    }
    int index=(l+r)/2;
    if(v[index]==x)
    {
        return index;
    }
    if(v[index]>x)
    {
        return binary_search(v,n,x,l,index-1);
    }
    return binary_search(v,n,x,index+1,r);
}
class Solution
{
  public:
    int findFloor(vector<long long> v, long long n, long long x)
    {
        int a= binary_search(v,n,x,0,n-1);
        return a;
    }
};
