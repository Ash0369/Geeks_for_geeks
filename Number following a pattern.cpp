class Solution
{   
public:
    string printMinNumberForPattern(string s)
    {
        int n=s.size();
        
        stack<int>st;
        
        string ans="";
        
        st.push(0);
        string temp="";
        int cnt=1;
        for(int i=0;i<n;i++)
        {
            temp.push_back(cnt+'0');
            cnt++;
            if(s[i]=='I')
            {
                reverse(temp.begin(),temp.end());
                ans+=temp;
                temp="";
            }
        }
        temp.push_back(cnt+'0');
        reverse(temp.begin(),temp.end());
        ans+=temp;
        return ans;
    }
};
