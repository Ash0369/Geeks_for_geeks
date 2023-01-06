vector<bool>dp(10005,false);
void sieve()
{
    for(int i=2;i<=sqrt(10005);i++)
    {
        if(dp[i]==true)
        {
            continue;
        }
        for(int j=i*i;j<10005;j=j+i)
        {
            dp[j]=true;
        }
    }
}
class Solution
{   
  public:
    int shortestPath(int Num1,int Num2)
    {   
        sieve();
        queue<pair<int,int>>q;
        q.push({Num1,0});
       
        vector<int>vist(10005,false);
        vist[Num1]=true;
        while(!q.empty())
        {
            int ele=q.front().first;
            int op=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<=9;j++)
                {
                    if(i==0 && j==0)
                    {
                        continue;
                    }
                    string s=to_string(ele);
                    s[i]=j+'0';
                    int temp=stoi(s);
                    
                    if(dp[temp]==false && vist[temp]==false)
                    {
                        vist[temp]=true;
                        if(temp==Num2)
                        {
                            return op+1;
                        }
                        q.push({temp,op+1});
                    }
                }
            }
        }
        return 0;
    }
};
