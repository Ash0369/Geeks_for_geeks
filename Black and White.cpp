long long numOfWays(int n, int m)
{
    long long int ans=0;
    int mod=1e9+7;
    
    int dx[8]={-1,-1,1,1,-2,-2,2,2};
    int dy[8]={2,-2,2,-2,1,-1,1,-1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int cnt=0;
            for(int k=0;k<8;k++)
            {
                int nx=i+dx[k];
                int ny=j+dy[k];
                
                if(nx>=0 && ny>=0 && nx<n && ny<m)
                {
                    cnt++;
                }
            }
            
            ans=(((ans+(n*m))%mod)-1-cnt)%mod;
        }
    }
    return ans;
}
