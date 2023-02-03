class Solution
{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        vector<int>rev(4);
        /*
        up=0
        right=1;
        down=2;
        left=3;
        */
        
        rev[0]=1;
        rev[1]=2;
        rev[2]=3;
        rev[3]=0;
        
        int x=0;
        int y=0;
        int d=1;
        if(matrix[0][0]==1)
        {
            d=rev[d];
            matrix[0][0]=0;
        }
        while(true)
        {
            int nx=x+dx[d];
            int ny=y+dy[d];
            
            if(nx>=0 && ny>=0 && nx<n && ny<m)
            {
                 x=nx;
                 y=ny;
                if(matrix[nx][ny]==1)
                {
                   matrix[nx][ny]=0;
                   d=rev[d];
                }
            }
            else
            {
                return {x,y};
            }
        }
        return {};
    }

};
