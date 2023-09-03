class Solution 
{
  public:
    int maxBoxes(int N, int K, int C, int col[]) 
    {
        int n=N;
        int k=K;
        int c=C;
        vector<vector<int>>p;
        for(int i=0;i<n;i++)
        {
            if(col[i]==c)
            {
                int start=i;
                
                while(i<n && col[i]==c)
                {
                    i++;
                }
                i--;
                p.push_back({start,i});
            }
        }
        
        //Try explosion from all points
        
        int ans=0;
        
        for(auto x:p)
        {
            int start=x[0];
            int end=x[1];
            if(end-start+1<2)continue;
            ans=max(ans,end-start+1);
            while(true)
            {
                if(end+1<n && start-1>=0 && col[start-1]==col[end+1])
                {
                    int sz=2;
                    start--;
                    end++;
                    while(start>=1 && col[start-1]==col[start])
                    {
                        sz++;
                        start--;
                    }
                    while(end+1<n && col[end+1]==col[end])
                    {
                        sz++;
                        end++;
                    }
                    if(sz<3)
                    {
                        break;
                    }
                    ans=max(ans,end-start+1);
                }
                else
                {
                    break;
                }
            }
            
        }
        return ans;
    }
};
