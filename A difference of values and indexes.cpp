//https://leetcode.com/discuss/interview-question/749936/maximum-absolute-difference-amazon

class Solution
{
  public:
    int maxDistance(int arr[], int n) 
    {
        int maxminus=INT_MIN;
        int minminus=INT_MAX;
        
        int maxplus=INT_MIN;
        int minplus=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            maxminus=max(maxminus,arr[i]-i);
            minminus=min(minminus,arr[i]-i);
            
            maxplus=max(maxplus,arr[i]+i);
            minplus=min(minplus,arr[i]+i);
        }
        
        int ans1=maxminus-minminus;
        int ans2=maxplus-minplus;
        
        return max(ans1,ans2);
    } 
};
