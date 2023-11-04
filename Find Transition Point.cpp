class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) {
       int ans=-1;
       for(int i=0;i<n;i++)
       {
           if(arr[i]==1)
           {
               return i;
           }
       }
       return ans;
    }
};
