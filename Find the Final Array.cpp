class Solution 
{
  public:
    vector<long long> finalArray(int n, vector<int> &B) 
    {
        #define ll long long
        
        vector<ll int>ans;
        ll int hand=0;
        int op=0;
        map<int,int>mp;
        
        for(int i=0;i<n;i++)
        {
            ans.push_back(B[i]+hand);
            hand=hand-op;
            int z=mp[i];
            op=op-z;
            
            int val=B[i];
            if(val>1)
            {
                mp[i+val-1]++;
                op++;
                hand+=val-1;
            }
            
        }
        return ans;
    }
};
