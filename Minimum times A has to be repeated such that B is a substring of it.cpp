int check(int index,string a,string b)
{
    int len=b.size();
    int sz=a.size();
    int starta=sz;
    int startb=sz-index;
    int cnt=0;
    while(startb<len)
    {
        if(starta%sz==0)
        {
            cnt++;
        }
        if(b[startb]!=a[starta%sz])
        {
            return INT_MAX;
        }
        startb++;
        starta++;
    }
    return cnt+1;
}
class Solution 
{
  public:
    int minRepeats(string A, string B) 
    {
        string a=A;
        string b=B;
        int n=a.size();
        char c=b[0];
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(a[i]==c)
            {
                string x=a.substr(i,n-i);
                string y=b.substr(0,n-i);
                if(x==y)
                {
                    int temp=check(i,a,b);
                    ans=min(ans,temp);
                }
            }
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};
