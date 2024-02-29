class Solution {
public:
    int countTestedDevices(vector<int>& bp) {
        int n=bp.size();
        
        int ans=0;
        
        for(auto x:bp){
            int z=x-ans;
            if(z>0)
               {
                ans++;
                }
            }
        return ans;

    }
};
