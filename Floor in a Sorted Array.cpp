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
