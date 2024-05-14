int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        
        vector<vector<int>>dp(rows,vector<int>(columns,1e9));
        dp[rows-1][columns-1]=0;
        set<vector<int>>st;
        st.insert({0,rows-1,columns-1});
        
        while(st.size()>0)
        {
            auto node=*st.begin();
            st.erase(*st.begin());
            int x=node[1];
            int y=node[2];
            int d=node[0];
            
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(nx>=0 && ny>=0 && nx<rows && ny<columns)
                {
                    int d1=dp[nx][ny];
                    int offer=abs(heights[x][y]-heights[nx][ny]);
                    if(max(offer,d)<d1)
                    {
                        if(st.find({d1,nx,ny})!=st.end())
                        {
                            st.erase({d1,nx,ny});
                        }
                        st.insert({max(offer,d),nx,ny});
                        dp[nx][ny]=max(offer,d);
                    }
                }
            }
        }
        return dp[0][0];
    }
};
