class Solution
{
public:
    string stringMirror(string str)
    {
        string ans="";
        ans.push_back(str[0]);
        for(int i=1;i<str.size();i++)
        {
            if(ans[i-1]>str[i] || (i>1 && ans[i-1]>=str[i]))
            {
                ans.push_back(str[i]);
            }
            else
            {
                break;
            }
        }
        string temp=ans;
        reverse(temp.begin(),temp.end());
        ans=ans+temp;
        return ans;
    }
};
