class Solution {
public:
    int solve(int n, int a, vector<int> x) 
    {
        sort(x.begin(),x.end());
        vector<int>test;
        test.push_back(x[0]);
        test.push_back(x[1]);
        if(n>=3)
        {
            test.push_back(x[n-1]);
        }
        if(n>=4)
        {
            test.push_back(x[n-2]);
        }
        
        
        int ans=0;
        int sz=test.size();
        for(int i=0;i<sz;i++)
        {
            for(int j=i+1;j<sz;j++)
            {
                ans=max(ans,abs(a-test[i])+abs(a-test[j]));
            }
        }
        return ans;
    }
};
