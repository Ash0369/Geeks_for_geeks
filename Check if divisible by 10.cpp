class Solution 
{
  public:
    int isDivisibleBy10(string bin)
    {
        int n=bin.size();
        
        int last=1;
        int tot=0;
        for(int i=n-1;i>=0;i--)
        {
            if(bin[i]=='0')
            {
                
            }
            else
            {
                tot+=last;
            }
            last*=2;
            last=last%10;
        }
        return tot%10==0;
    }
    
};
