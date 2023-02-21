//Method-1 : 

class Solution
{   
public:
    int minIteration(int N, int M, int x, int y)
    {
        int n=N;
        int m=M;
        vector<vector<int>>dp(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({x-1,y-1});
        dp[x-1][y-1]=1;
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int cost=0;
        
        while(!q.empty())
        {
            int sz=q.size();
            bool res=false;
            for(int j=0;j<sz;j++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && dp[nx][ny]==0)
                    {
                        res=true;
                        dp[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
            if(res==true)
            {
                cost++;
            }
        }
        return cost;
    }
};


//Method-2 : 

class Solution
{   
public:
    int minIteration(int N, int M, int x, int y)
    {
        int n=N;
        int m=M;
        int left=max(n-x,x-1);
        int right=max(m-y,y-1);
        return left+right;
    }
};
