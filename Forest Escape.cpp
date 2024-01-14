class Solution
{
public:
    bool escapeForest(int n,int m,vector<vector<char>> &grid)
    {
        int men=1;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        vector<vector<int>>a;
        vector<vector<int>>b;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='M')
                {
                    if(i==0 || i==n-1 || j==0 || j==m-1)
                    {
                        return true;
                    }
                    a.push_back({i,j});
                }
                if(grid[i][j]=='X')
                {
                    b.push_back({i,j});
                }
            }
        }
        while(men>0)
        {
            vector<vector<int>>ta;
            vector<vector<int>>tb;
            int cnt=0;
            for(auto x:a)
            {
                if(grid[x[0]][x[1]]=='X')
                {
                    continue;
                }
               
                for(int i=0;i<4;i++)
                {
                    int x1=x[0]+dx[i];
                    int x2=x[1]+dy[i];
                    
                    if(x1>=0 && x2>=0 && x1<n && x2<m && grid[x1][x2]=='.')
                    {
                        if(x1==0 || x1==n-1 || x2==0 || x2==m-1)
                        {
                            cnt++;
                        }
                        men++;
                        grid[x1][x2]='M';
                        ta.push_back({x1,x2});
                    }
                }
            }
            
            for(auto x:b)
            {
                for(int i=0;i<4;i++)
                {
                    int x1=x[0]+dx[i];
                    int x2=x[1]+dy[i];
                    
                    if(x1>=0 && x2>=0 && x1<n && x2<m)
                    {
                        if(grid[x1][x2]=='X')
                        {
                            continue;
                        }
                        if(grid[x1][x2]=='M')
                        {
                            if(x1==0 || x1==n-1 || x2==0 || x2==m-1)
                            {
                                cnt--;
                            }
                            men--;
                        }
                        grid[x1][x2]='X';
                        tb.push_back({x1,x2});
                    }
                }
            }
            a=ta;
            b=tb;
            if(cnt>0)
            {
                return true;
            }
            
        }
        return false;
    }
};
