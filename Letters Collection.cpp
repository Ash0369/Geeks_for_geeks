int dx[8]={-1,0,1,1,1,0,-1,-1};
int dy[8]={1,1,1,0,-1,-1,-1,0};

int dx1[16]={-2,-2,-1,0,1,2,2,2,1,0,-1,-2,-2,2,2,-2};
int dy1[16]={0,2,2,2,2,2,0,-2,-2,-2,-2,-2,1,1,-1,-1};


class Solution
{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        vector<int>ans;
        for(int i=0;i<q;i++)
        {
            auto z=queries[i];
            int tot=0;
            int x=z[1];
            int y=z[2];
            if(z[0]==2)
            {
                for(int j=0;j<16;j++)
                {
                    int nx=x+dx1[j];
                    int ny=y+dy1[j];
                    if(nx>=0 && ny>=0 && nx<n && ny<m)
                    {
                        tot+=mat[nx][ny];
                    }
                }
                ans.push_back(tot);
                
                continue;
            }
            for(int j=0;j<8;j++)
            {
                int nx=x+dx[j];
                int ny=y+dy[j];
                if(nx>=0 && ny>=0 && nx<n && ny<m)
                {
                    tot+=mat[nx][ny];
                }
            }
            ans.push_back(tot);
        }
        return ans;
    }
};
