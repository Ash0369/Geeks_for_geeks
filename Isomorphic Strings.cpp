class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        map<char,char>mp;
        map<char,char>mp2;
        int n=str1.size();
        int m=str2.size();
        if(m!=n)
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            if(mp.find(str1[i])==mp.end())
            {
                if(mp2.find(str2[i])!=mp2.end())
                {
                    return false;
                }
                mp[str1[i]]=str2[i];
                mp2[str2[i]]=str1[i];
            }
            else{
                if(mp[str1[i]]==str2[i])
                {
                    
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
