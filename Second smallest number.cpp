class Solution
{   
  public:
    string secondSmallest(int S, int D)
    {
        int s=S;
        int d=D;
        
        if(d==1)
        {
            return "-1";
        }
        string ans="";
        for(int i=0;i<d;i++)
        {
            ans.push_back('0');
        }
        ans[0]='1';
        s--;
        if(s<=0)
        {
            return "-1";
        }
        
        bool res=false;
        for(int i=d-1;i>=0;i--)
        {
            if(s>=9)
            {
                if(i==0)
                {
                    return "-1";
                }
                ans[i]='9';
                s=s-9;
            }
            else
            {
                if(i==0)
                {
                    s++;
                }
                ans[i]=(s+'0');
                if(i!=d-1)
                {
                    if(ans[i]=='9')
                    {
                        return "-1";
                    }
                    ans[i]=((ans[i]-'0')+1)+'0';
                    ans[i+1]=((ans[i+1]-'0')-1)+'0';
                }
                else
                {
                     ans[i]=((ans[i]-'0')-1)+'0';
                     ans[i-1]=((ans[i-1]-'0')+1)+'0';
                }
                res=true;
                break;
            }
           
        }
        if(res)
        {
            return ans;
        }
        return "-1";
    }
};
