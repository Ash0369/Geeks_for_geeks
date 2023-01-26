class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string lower="";
        string upper="";
        for(int i=0;i<n;i++)
        {
            if(isupper(str[i]))
            {
                upper.push_back(str[i]);
            }
            else
            {
                lower.push_back(str[i]);
            }
        }
        sort(upper.begin(),upper.end());
        sort(lower.begin(),lower.end());
        
        int x=0;
        int y=0;
        
        for(int i=0;i<n;i++)
        {
            if(isupper(str[i]))
            {
                str[i]=upper[y];
                y++;
            }
            else
            {
                str[i]=lower[x];
                x++;
            }
        }
        
        return str;
    }
};
