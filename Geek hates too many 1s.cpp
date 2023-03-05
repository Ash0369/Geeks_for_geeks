class Solution 
{
    public:
    int noConseBits(int n) 
    {
        string s="";
        while(n>0)
        {
            if((n&1)==0)
            {
                s.push_back('0');
            }
            else
            {
                s.push_back('1');
            }
            n=n>>1;
        }
        reverse(s.begin(),s.end());
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                cnt=0;
            }
            else
            {
                cnt++;
                if(cnt==3)
                {
                    s[i]='0';
                    cnt=0;
                }
            }
        }
        int ans=0;
        int bits=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                ans=(1<<bits)+ans;
            }
            bits++;
        }
        return ans;
    }
};
