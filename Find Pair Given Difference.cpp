class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        
        map<int,int>mp;
        for(auto y:arr){
            mp[y]++;
        }
        
        for(auto y:arr){
            int r=y+x;
            if(r==x || r==y)
            {
                if(mp[r]>1)
                {
                    return 1;
                }
            }
            else if(mp.find(r)!=mp.end())
            {
                return 1;
            }
            
            r=y-x;
            if(r==x || r==y)
            {
                if(mp[r]>1)
                {
                    return 1;
                }
            }
            else if(mp.find(r)!=mp.end())
            {
                return 1;
            }
            
        }
        return -1;
    }
};
