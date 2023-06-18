class Solution 
{
  public:
    int distributeTicket(int N, int k) 
    {
        int front=0;
        int back=N;
        while(front<back)
        {
            front+=k;
            if(front>=back)
            {
                return back;
            }
            back=back-k;
            if(front>=back)
            {
                return front+1;
            }
        }
    }
};
