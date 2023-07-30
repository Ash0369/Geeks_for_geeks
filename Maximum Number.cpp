class Solution {
  public:
    int maximumNumber(int N) 
    {
        int n=N;
        string s=to_string(n);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='7')
            {
                s[i]='9';
                break;
            }
        }
        return stoi(s);
    }
};
