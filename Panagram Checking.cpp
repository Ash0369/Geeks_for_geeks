class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) 
    {
        set<char>st;
        for(auto x:s)
        {
            
            if(int(x)<65)
            {
                continue;
            }
            char y=tolower(x);
            st.insert(y);
        }
        //cout<<st.size()<<endl;
        if(st.size()==26)
        {
            return true;
        }
        return false;
    }

};
