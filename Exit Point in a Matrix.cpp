class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix,int d=0,int x=0,int y=0) {
        
        if(matrix[x][y]==0)
        {
            if(d==0)
            {
                if(y+1==m)
                {
                    return {x,y};
                }
                return FindExitPoint(n,m,matrix,d,x,y+1);
            }
            else if(d==1)
            {
                if(y-1==-1)
                {
                    return {x,y};
                }
                return FindExitPoint(n,m,matrix,d,x,y-1);
            }
            else if(d==2)
            {
                if(x-1==-1)
                {
                    return {x,y};
                }
                return FindExitPoint(n,m,matrix,d,x-1,y);
            }
            else{
                if(x+1==n)
                {
                    return {x,y};
                }
                return FindExitPoint(n,m,matrix,d,x+1,y);
            }
        }
        else
        {
            matrix[x][y]=0;
            if(d==0)
            {
                d=3;
            }
            else if(d==1){
                d=2;
            }
            else if(d==2)
            {
                d=0;
            }
            else{
                d=1;
            }
            if(d==0)
            {
                if(y+1==m)
                {
                    return {x,y};
                }
                return FindExitPoint(n,m,matrix,d,x,y+1);
            }
            else if(d==1)
            {
                if(y-1==-1)
                {
                    return {x,y};
                }
                return FindExitPoint(n,m,matrix,d,x,y-1);
            }
            else if(d==2)
            {
                if(x-1==-1)
                {
                    return {x,y};
                }
                return FindExitPoint(n,m,matrix,d,x-1,y);
            }
            else{
                if(x+1==n)
                {
                    return {x,y};
                }
                return FindExitPoint(n,m,matrix,d,x+1,y);
            }
        }
    }
};
