int cal(char &c1,char &c2)
{
    if(c1=='C')
    {
        if(c2=='A')
        {
            return 1;
        }
        if(c2=='G')
        {
            return 1;
        }
         if(c2=='T')
        {
            return 2;
        }
        return 0;
    }
    
    
    if(c1=='G')
    {
        if(c2=='A')
        {
            return 2;
        }
        if(c2=='C')
        {
            return 1;
        }
         if(c2=='T')
        {
            return 1;
        }
        return 0;
    }
    
    if(c1=='A')
    {
        if(c2=='G')
        {
            return 2;
        }
        if(c2=='C')
        {
            return 1;
        }
         if(c2=='T')
        {
            return 1;
        }
        return 0;
    }
    
    
    if(c1=='T')
    {
        if(c2=='C')
        {
            return 2;
        }
        if(c2=='G')
        {
            return 1;
        }
         if(c2=='A')
        {
            return 1;
        }
        return 0;
    }
}
class Solution 
{
  public:
    long long easyProblem(int n, int l, vector<string> &s) 
    {
        #define ll long long
        vector<vector<ll int>>graph(n+2,vector<ll int>(n+2,0));
        
        for(int i=0;i<n;i++)
        {
            
            for(int j=i+1;j<n;j++)
            {
                string s1=s[i];
                string s2=s[j];
                ll int cost=0;
                for(int k=0;k<l;k++)
                {
                    if(s1[k]!=s2[k])
                    {
                        cost+=cal(s1[k],s2[k]);
                    }
                }
                graph[i][j]=cost;
                graph[j][i]=cost;
                
            }
        }
        string p="";
        for(int i=0;i<l;i++)
        {
            p.push_back('A');
        }
        for(int j=0;j<n;j++)
        {
            string s1=p;
            string s2=s[j];
            int cost=0;
            for(int k=0;k<l;k++)
            {
                if(s1[k]!=s2[k])
                {
                    cost+=cal(s1[k],s2[k]);
                }
            }
            graph[n][j]=cost;
            graph[j][n]=cost;
            
        }
        
        vector<int>dp(n,0);
        
        int till=0;
        
        priority_queue<pair<int,ll int>,vector<pair<int,ll int>>,greater<pair<int,ll int>>>pq;
        
        for(int i=0;i<n;i++)
        {
            pq.push({graph[i][n],i});
        }
        ll int ans=0;
        while(till<n && pq.size()>0)
        {
            int index=pq.top().second;
            ll int c=pq.top().first;
            
            pq.pop();
            if(dp[index])
            {
                continue;
            }
            //cout<<c<<" "<<index<<endl;
            ans+=c;
            till++;
            dp[index]=1;
            for(int j=0;j<n;j++)
            {
                if(dp[j])
                {
                    continue;
                }
                pq.push({graph[index][j],j});
            }
        }
        if(till==n)
        {
            return ans;
        }
        return -1;
    }
    
};
