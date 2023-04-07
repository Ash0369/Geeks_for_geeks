class Solution
{   
public:
    int addMinChar(string str)
    {
        int n=str.size();
        int ans=0;
        int i=n-1;
        int j=0;
        while(i>=j)
        {
            if(str[i]==str[j])
            {
                i--;
                j++;
            }
            else
            {
                ans++;
                j=0;
                i=n-1-ans;
            }
        }
        return ans;
        
    }
};
