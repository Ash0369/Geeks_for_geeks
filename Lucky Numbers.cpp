class Solution
{
public:
    bool isLucky(int n) 
    {
        int c=2;
        while(c<=n)
        {
            if(n%c==0)return false;
            
            n=n-(n/c);
            c++;
        }
        return true;
    }
};
