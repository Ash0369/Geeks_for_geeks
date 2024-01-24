class Solution{   
public:
    int solve(int n1,int n2)
    {
        vector<int>prime(100000,0);
        for(int i=1000;i<=9999;i++)
        {
            int ele=i;
            bool res=false;
            for(int j=2;j*j<=ele;j++)
            {
                if(ele%j==0)
                {
                    res=true;
                    break;
                }
            }
            if(res==false)
            {
                prime[i]=1;
            }
        }
        vector<int>dp(100000,1e9);
        dp[n1]=0;
       queue<int>q;
        q.push(n1);
        while(!q.empty())
        {
            int ele=q.front();
            q.pop();
            int r=dp[ele];
            
            string s=to_string(ele);
            
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if(i==0 && j==0)
                    {
                        continue;
                    }
                    
                    string temp=s;
                    temp[i]=j+'0';
                    
                    if(prime[stoi(temp)]==1 && dp[stoi(temp)]>r+1)
                    {
                        dp[stoi(temp)]=r+1;
                        q.push(stoi(temp));
                    }
                }
            }
            
            
        }
        return dp[n2];
        
    }
};
