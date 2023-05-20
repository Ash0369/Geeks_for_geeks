class Solution 
{
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) 
    {
        int n=N;
        int g=groupSize;
        
        if(n%g!=0)
        {
            return false;
        }
        sort(hand.begin(),hand.end());
        vector<int>vis(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==1)
            {
                continue;
            }
            int ele=hand[i];
            int sz=1;
            for(int j=i+1;j<n;j++)
            {
                if(sz==g)
                {
                    break;
                }
                if(vis[j]==1 || hand[j]==ele)
                {
                    continue;
                }
                if(hand[j]!=(ele+1))
                {
                    return false;
                }
                vis[j]=1;
                ele=hand[j];
                sz++;
                
            }
        }
        return true;
    }
};
