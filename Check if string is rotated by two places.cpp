class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        int n=str1.size();
        int m=str2.size();
        if(m!=n)
        {
            return false;
        }
        if(m==1)
        {
            return str1==str2;
        }
        string s="";
        s.push_back(str1[n-2]);
        s.push_back(str1[n-1]);
        for(int i=0;i<n-2;i++)
        {
            s.push_back(str1[i]);
        }
        if(s==str2)
        {
            return true;
        }
        s="";
        for(int i=2;i<n;i++)
        {
            s.push_back(str1[i]);
        }
        s.push_back(str1[0]);
        s.push_back(str1[1]);
        return s==str2;
    }

};
