class Solution
{
public:
    int minimumNumber(int n,vector<int> &arr)
    {
        int min_ele=INT_MAX;
        for(auto x:arr)
        {
            min_ele=min(min_ele,x);
        }
        return min_ele;
    }
};
