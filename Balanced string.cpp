int find(int n)
{
    int x=0;
    while(n>0)
    {
        x=x+(n%10);
        n=n/10;
    }
    return x;
}
string form(int n,string s)
{
    if(n%2==0)
    {
        int x=(n%26)/2;
        int y=(n%26)/2;
        while(n>=26)
        {
            s+="abcdefghijklmnopqrstuvwxyz";
            n=n-26;
        }
        
        for(int i=1;i<=x;i++)
        {
            s.push_back(char(i+96));
        }
        for(int i=1;i<=y;i++)
        {
            s.push_back(char(122-y+i));
        }
        
    }
    else
    {
        int sum=find(n);
        if(sum%2==0)
        {
            int x=((n%26)+1)/2;
            int y=((n%26)-1)/2;
            while(n>=26)
            {
                s+="abcdefghijklmnopqrstuvwxyz";
                n=n-26;
            }
            
            for(int i=1;i<=x;i++)
            {
                s.push_back(char(i+96));
            }
            
            for(int i=1;i<=y;i++)
            {
                s.push_back(char(122-y+i));
            }
            
        }
        else
        {
            int x=((n%26)-1)/2;
            int y=((n%26)+1)/2;
            while(n>=26)
            {
                s+="abcdefghijklmnopqrstuvwxyz";
                n=n-26;
            }
            
            for(int i=1;i<=x;i++)
            {
                s.push_back(char(i+96));
            }
            
            for(int i=1;i<=y;i++)
            {
                s.push_back(char(122-y+i));
            }
        }
    }
    return s;
}
class Solution 
{
  public:
    string BalancedString(int n) 
    {
        return form(n,"");
    }
};
