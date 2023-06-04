class Solution
{
  public:
    string reverseEqn (string s)
    {
        string ans="";
        for(int i=s.size()-1;i>=0;i--)
        {
            if(int(s[i])>=48 && int(s[i])<=57)
            {
                string temp;
                while(i>=0 && int(s[i])>=48 && int(s[i])<=57)
                {
                    temp.push_back(s[i]);
                    i--;
                }
                reverse(temp.begin(),temp.end());
                ans=ans+temp;
                i++;
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
