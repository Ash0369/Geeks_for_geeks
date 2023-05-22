class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        int n=N;
        int m=M;
        int x=X;
        map<int,int>mp;
        for(int i=0;i<m;i++)
        {
            mp[B[i]]=i;
        }
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            int ele=A[i];
            if(mp.find(x-ele)!=mp.end())
            {
                vec.push_back({ele,x-ele});
            }
        }
        sort(vec.begin(),vec.end());
        return vec;
    }
};
