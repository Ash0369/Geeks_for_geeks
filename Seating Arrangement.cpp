class Solution
{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats)
    {
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            if(seats[i]==0)
            {
                if((i-1<0 || seats[i-1]==0) && (i+1>=m || seats[i+1]==0))
                {
                    cnt++;
                    seats[i]=1;
                }
            }
        }
        return cnt>=n;
    }
};
