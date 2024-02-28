class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        string ans;
        if(9*n<sum)
        {
            return "-1";
        }
        else{
            while(n--)
            {
                if(sum>=9)
                {
                    ans.push_back('9');
                    sum-=9;
                }
                else{
                    ans.push_back(sum+'0');
                    sum=0;
                }
            }
        }
        return ans;
    }
};
