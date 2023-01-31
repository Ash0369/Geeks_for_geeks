int check(int index,string a,string b)
{
    int len=b.size();
    int sz=a.size();
    int starta=index;
    int startb=0;
    int cnt=1;
    if(starta==0)
        cnt--;
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
    return cnt;
}
class Solution 
{
  public:
    int minRepeats(string A, string B) 
    {
        string a=A;
        string b=B;
        int n=a.size();
        int n1=b.size();
        
        char c=b[0];
        int ans=INT_MAX;
        int intial=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==c)
            {  
                int temp=check(i,a,b);    
                ans=min(ans,temp);
            }
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};
