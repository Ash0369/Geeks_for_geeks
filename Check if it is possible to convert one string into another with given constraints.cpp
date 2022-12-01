class Solution 
{
  public:
    int isItPossible(string s, string t, int M, int N) 
    {
        int i=0;
        string a,b;
        for(int i=0;i<M;i++)
        {
            if(s[i]!='#')
            {
                a.push_back(s[i]);
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(t[i]!='#')
            {
                b.push_back(t[i]);
            }
        }
        
        return a==b;
    }
};
