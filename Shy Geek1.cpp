#define ll long long
class Solution{
    public:
    Shop s;
    Solution(Shop shop){
        s=shop;
    }
    long long find(int n, long k){
        ll int ans=0;
        int prev=n-1;
        while(k>0)
        {
            int left=0;
            int right=prev;
            ll int z=-1;
            while(left<=right)
            {
                int mid=(left+right)/2;
                
                ll int av=s.get(mid);
                assert(av!=-1);
                if(av<=k)
                {
                    z=av;
                    prev=mid-1;
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            if(z==-1)
            {
                return ans;
            }
            ans+=k/z;
            ll int p=k/z;
            k=k-(p*z);
            
        }
        return ans;
    }

};
