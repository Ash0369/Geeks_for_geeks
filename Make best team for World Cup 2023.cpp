#define ll long long
class Solution {
public:
  long long maximumSum(int N, vector<int> &A) 
  {
      int  n=N;
 
      ll int ans=0;
      priority_queue<int>pq;
      
      int i=n/2;
      int j=i+1;
      if(n%2)
      {
          ans+=A[n/2];
          i--;
      }
      else{
          
          i--;
          j--;
      }
      
      while(i>=0)
      {
          pq.push(A[i]);
          pq.push(A[j]);
          ans+=pq.top();
          pq.pop();i--;j++;
      }
      return ans;
  }
};
