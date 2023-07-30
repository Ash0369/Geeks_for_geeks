class Solution 
{
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) 
    {
        int cnt=0;
        for(auto x:hours)
        {
            if(x>=target)
                cnt++;
        }
        return cnt;
    }
};
