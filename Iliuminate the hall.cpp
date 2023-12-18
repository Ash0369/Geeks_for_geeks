class Solution{
    public:
    int min_lights(int hallway[], int n)
    {
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({i-hallway[i],i+hallway[i]});
        }
        sort(vec.begin(),vec.end());
        int b=0;
        int target=0;
        int i=0;
        while(target<n)
        {
            if(i==n || vec[i].first>target)
            {
                return -1;
            }
            int mx=vec[i].second;
            while(i+1<n && vec[i+1].first<=target)
            {
                mx=max(mx,vec[i+1].second);
                i++;
            }
            if(mx<target)
            {
                return -1;
            }
            b++;
            target=mx+1;
            i++;
        }
        return b;
    }
};
