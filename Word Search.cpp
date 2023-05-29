int n,m;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool dfs(int x,int y,int index,string &word,vector<vector<char>>&board)
{
    if(index==word.size())
    {
        return true;
    }
    bool ans=false;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx>=0 && ny>=0 && nx<n && ny<m && board[nx][ny]==word[index])
        {
            char c=board[nx][ny];
            board[nx][ny]='1';
            ans=ans|dfs(nx,ny,index+1,word,board);
            board[nx][ny]=c;
        }
    }
    return ans;
}
class Solution 
{
public:
    bool isWordExist(vector<vector<char>>& board, string word) 
    {
        n=board.size();
        m=board[0].size();
        bool ans=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=ans|dfs(i,j,0,word,board);
            }
        }
        return ans;
    }
};
