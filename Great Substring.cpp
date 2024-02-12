#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>pbds; 
class Solution 
{
  public:
    long long greatCount(int n, string s) 
    {
        #define ll long long
        pbds st;
        ll int ans=0;
        int sr=0;
        for(int i=0;i<n;i++)
        {
            int prev=sr;
            sr+=(s[i]=='1');
            int curr=(2*sr)-i;
            
            int p=st.order_of_key(curr);
            ans=ans+p;
            
            st.insert((2*prev)-i+1);
            if(s[i]=='1')
            {
                ans++;
            }
        }
        return ans;
    }
};
