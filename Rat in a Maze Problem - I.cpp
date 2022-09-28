class Solution
{
    public:
    void rat(vector<vector<int>>&m,int i,int j,string s, vector<string>&res,vector<vector<int>>&vis)
    {
        int n=m.size();
        if(i==n-1 && j==n-1)
        {
            if(m[i][j]==0)
            {
                return;
            }
            res.push_back(s);
            return;
        }
        if(i==n || j==n || i==-1 || j==-1)
        {
            return;
        }
        vis[i][j]=1;
        if(i+1<n && m[i+1][j]==1 && vis[i+1][j]==0)
        {
            s.push_back('D');
            rat(m,i+1,j,s,res,vis);
            s.pop_back();
        }
        if(j+1<n && m[i][j+1]==1 && vis[i][j+1]==0)
        {
            s.push_back('R');
            rat(m,i,j+1,s,res,vis);
            s.pop_back();
        }
        if(i-1>=0 && m[i-1][j]==1 && vis[i-1][j]==0)
        {
            s.push_back('U');
            rat(m,i-1,j,s,res,vis);
            s.pop_back();
        }
        if(j-1>=0 && m[i][j-1]==1 && vis[i][j-1]==0)
        {
            s.push_back('L');
            rat(m,i,j-1,s,res,vis);
            s.pop_back();
        }
        
        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
         vector<string>res;
         if(m[0][0]==0)
         {
             return {};
         }
        vector<vector<int>>vis(n+1,vector<int>(n+1,0));
        rat(m,0,0,"",res,vis);
        return res;
    }
};
