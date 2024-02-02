class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int i=1;
        int n=s.size();
        int ans=0;
        int n1=1;
        for(int i=0;i<n;i++)
        {
            if(int(s[i])>=48 && int(s[i])<=57)
            {
                ans=ans*10;
                ans+=(s[i]-'0');
                //p.push_back(s[i]-'0');
            }
            else{
                if(i==0)
                {
                    if(s[i]=='-')
                    {
                        n1=-1;
                    }
                    continue;
                }
                return -1;
            }
        }
        ans=ans*n1;
        return ans;
        
        
    }
};
