class Solution {
    public:
    long long minOperations(vector<int> a, int n) {
        #define ll long long
        
        ll int ans=0;
        ll int p=0;
        for(int i=0;i<n;i++)
        {
            p+=a[i];
            if(p<0)
            {
                ans+=abs(p);
                p=0;
            }
        }
        return ans;
    }
};
