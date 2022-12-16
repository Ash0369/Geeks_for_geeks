class Solution
{
public:
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
    {
        int ans=0;
        if(ty==0)
        {
            int dxo[6]={1,-1,0,1,1,0};
            int dyo[6]={0,0,-1,-1,1,1};
            
            int dxe[6]={-1,0,-1,1,0,-1};
            int dye[6]={0,-1,-1,0,1,1};
            
            
            if(j%2==0)
            {
                for(int k=0;k<6;k++)
                {
                    int nx=i+dxe[k];
                    int ny=j+dye[k];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m)
                    {
                        
                        ans+=mat[nx][ny];
                    }
                }
            }
            else
            {
                for(int k=0;k<6;k++)
                {
                    int nx=i+dxo[k];
                    int ny=j+dyo[k];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m)
                    {
                        
                        ans+=mat[nx][ny];
                    }
                }
            }
        }
        else
        {
            int dx[8]={2,-2,-1,0,1,0,1,-1};
            int dy[8]={0,0,-2,-2,-2,2,2,2};
            
            int dxo[4]={2,2,-1,-1};
            int dyo[4]={-1,1,1,-1};
            
            int dxe[4]={1,1,-2,-2};
            int dye[4]={-1,1,1,-1};
            
            for(int k=0;k<8;k++)
            {
                int nx=i+dx[k];
                int ny=j+dy[k];
                
                if(nx>=0 && ny>=0 && nx<n && ny<m)
                {
                    ans+=mat[nx][ny];
                }
            }
            if(j%2==0)
            {
                for(int k=0;k<4;k++)
                {
                    int nx=i+dxe[k];
                    int ny=j+dye[k];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m)
                    {
                        ans+=mat[nx][ny];
                    }
                }
            }
            else
            {
                for(int k=0;k<4;k++)
                {
                    int nx=i+dxo[k];
                    int ny=j+dyo[k];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m)
                    {
                        ans+=mat[nx][ny];
                    }
                }
            }
        }
        return ans;
    }
};
