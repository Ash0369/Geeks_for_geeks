class Solution {
  public:
    int getTwinCount(int N , int Arr[]) 
    {
        sort(Arr,Arr+N);
        int ans=0;
        
        for(int i=0;i<N-1;i++)
        {
            if(Arr[i]==Arr[i+1])
            {
                ans+=2;
                i++;
            }
        }
        return ans;
    }
};
