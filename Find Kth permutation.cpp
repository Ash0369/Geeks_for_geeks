class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        string ans="";
        for(int i=1;i<=n;i++)
        {
            ans.push_back(i+'0');
        }
        for(int i=1;i<k;i++)
        {
            next_permutation(ans.begin(),ans.end());
        }
        return ans;
    }
};
