bool vowel(char a)
{
    if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
    {
        return true;
    }
    return false;
}
class Solution
{
    public:
    string rearrange (string s, int n)
    {
        vector<int>cont(26,0);
        vector<int>vow(26,0);
        int cntv=0;
        int cntc=0;
        for(int i=0;i<n;i++)
        {
            if(vowel(s[i]))
            {
                vow[s[i]-'a']++;
                cntv++;
            }
            else
            {
                cntc++;
                cont[s[i]-'a']++;
            }
           // alphabet[s[i]-'a']++;
        }
        string ans="";
        
        int c=0;
        int v=0;
        
        if(cntc>cntv)
        {
            while(true)
            {
                while(cont[c]==0 && c<26)
                {
                    c++;
                }
                while(vow[v]==0 && v<26)
                {
                    v++;
                }
                
                if(c<26 && v<26)
                {
                    ans+=c+'a';
                    ans+=v+'a';
                    cont[c]--;
                    vow[v]--;
                }
                else
                {
                    if(c<26 && cont[c]==1)
                    {
                        ans+=c+'a';
                        cont[c]--;
                        while(c<26 && cont[c]==0)
                        {
                            c++;
                        }
                    }
                    break;
                }
            }
            
        }
        else
        {
            while(true)
            {
                while(cont[c]==0 && c<26)
                {
                    c++;
                }
                while(vow[v]==0 && v<26)
                {
                    v++;
                }
                
                if(c<26 && v<26)
                {
                    ans+=v+'a';
                    ans+=c+'a';
                    cont[c]--;
                    vow[v]--;
                }
                else
                {
                    if(v<26 && vow[v]==1)
                    {
                        ans+=v+'a';
                        vow[v]--;
                        while(v<26 && vow[v]==0)
                        {
                            v++;
                        }
                    }
                    break;
                }
            }
            
        }
        
        if(c==26 && v==26)
        {
            return ans;
        }
        return "-1";
        
    }
};
