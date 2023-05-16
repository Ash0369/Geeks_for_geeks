#define ll long long
bool check(ll int num)
{
    ll int y=1;
    while(y<num)
    {
        y=y*5;
    }
    if(y==1)
    {
        return 1;
    }
    return y==num;
}
ll int dfs(string &s,int index)
{
    if(index<0)
    {
        return 0;
    }
    int n=s.size();
    ll int curr=0;
    ll int ans=1000;
    int p=0;
    for(int i=index;i>=0;i--)
    {
        if(s[i]=='0')
        {
            p++;
            continue;
        }
        else
        {
            curr+=pow(2,p);
        }
        if(check(curr))
        {
            ans=min(ans,1+dfs(s,i-1));
        }
        p++;
    }
    return ans;
}
class Solution
{
    public:
    int cuts(string s)
    {
        int ans=dfs(s,s.size()-1);
        if(ans>=1000)
        {
            return -1;
        }
        return ans;
    }
};
