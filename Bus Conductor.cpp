class Solution 
{
  public:
    int findMoves(int n, vector<int> chairs, vector<int> passengers) 
    {
        sort(chairs.begin(),chairs.end());
        sort(passengers.begin(),passengers.end());
        int move=0;
        for(int i=0;i<n;i++)
        {
            move=move+abs(passengers[i]-chairs[i]);
        }
        return move;
    }
};
