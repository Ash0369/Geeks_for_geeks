class Solution 
{
  public:
    int shortestDistance(int n, int m, vector<vector<int>>vec, int x, int y) 
    {
        if(vec[0][0]==0)
        {
            return -1;
        }
        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
        distance[0][0]=0;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({0,{0,0}});
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        while(!pq.empty())
        {
            auto node=pq.top();
            pq.pop();
            
            int dit=node.first;
            int x1=node.second.first;
            int y1=node.second.second;
            if(x1==x && y1==y)
            {
                break;
            }
            int prev=distance[x1][y1];
            
            for(int i=0;i<4;i++)
            {
                int nx=x1+dx[i];
                int ny=y1+dy[i];
                
                if(nx>=0 && nx<n && ny>=0 && ny<m && vec[nx][ny]==1)
                {
                    int intial=distance[nx][ny];
                    
                    if(intial>dit+1)
                    {
                        distance[nx][ny]=dit+1;
                        pq.push({dit+1,{nx,ny}});
                    }
                }
            }
        }
     
        if(distance[x][y]==INT_MAX)
        {
            return -1;
        }
        return distance[x][y];
    }
};
