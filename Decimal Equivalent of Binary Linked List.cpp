#define ll long long
#define mod 1000000007
ll int pwr(ll int a,ll int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b%2==0)
    {
        ll int ans1=pwr(a,b/2);
        ll int ans2=(ans1*ans1)%mod;
        return ans2;
    }
    ll int ans1=pwr(a,b/2);
    ll int ans2=(ans1*ans1)%mod;
    ans2=(ans2*a)%mod;
    return ans2;
}
#include<vector>
class Solution
{
    public:
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        long long unsigned int decimalValue(Node *head)
        {
            vector<bool>v;
            while(head!=NULL)
            {
                v.push_back(head->data);
                head=head->next;
            }
            
            int i=0;
            
            long long unsigned int ans=0;
            while(v.size()>0)
            {
                if(v.back()==true)
                {
                    ans=(ans+pwr(2,i))%mod;
                }
                i++;
                v.pop_back();
            }
            return ans;
        }
};
