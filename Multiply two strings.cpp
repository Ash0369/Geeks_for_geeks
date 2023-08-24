{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) 
    {
        if(s1=="0" && s2=="0")
        {
            return "0";
        }
        vector<int>res(s1.size()+s2.size(),0);
        int n1=s1.size();
        int n2=s2.size();
        int last1=0;
        int last2=0;
        int n=1;
        if(s1[0]=='-')
        {
            n=-1;
            last1=1;
        }
        if(s2[0]=='-')
        {
            n*=-1;
            last2=1;
        }
        for(int i=n1-1;i>=last1;i--)
        {
            for(int j=n2-1;j>=last2;j--)
            {
                res[i+j+1]+=(s1[i]-'0')*(s2[j]-'0');
                res[i+j]+=res[i+j+1]/10;
                res[i+j+1]=res[i+j+1]%10;
                
            }
        }
        
        int i=0;
        string ans="";
        if(n==-1)
        {
            ans.push_back('-');
        }
        while(res[i]==0)
        {
            i++;
        }
        while(i<res.size())
        {
            ans+=to_string(res[i]);
            i++;
        }
        
        return ans;
    }

};
