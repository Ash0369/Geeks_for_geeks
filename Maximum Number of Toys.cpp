#define ll long long

class Solution
{
public:
  vector<int> maximumToys(int N,vector<int> A,int Q,vector<vector<int>> Queries)
  {
      ll int n=N;
      vector<pair<ll int,ll int>>vec;
      for(int i=0;i<n;i++)
      {
          vec.push_back({A[i],i});
      }
      sort(vec.begin(),vec.end());
      map<ll int,ll int>mp;
      for(int i=0;i<n;i++)
      {
          mp[vec[i].second]=i;
      }
      vector<ll int>prefix(n,0);
      prefix[0]=vec[0].first;
      for(int i=1;i<n;i++)
      {
          prefix[i]=vec[i].first+prefix[i-1];
      }
      vector<int>ans;
      for(auto x:Queries)
      {
          ll int c=x[0];
          ll int k=x[1];
          
          ll int left=0;
          ll int right=n-1;
          ll int cnt=-1;
          while(left<=right)
          {
              ll int mid=(left+right)/2;
              if(prefix[mid]<=c)
              {
                  left=mid+1;
                  cnt=mid;
              }
              else
              {
                  right=mid-1;
              }
          }
        
          if(cnt<0)
          {
              ans.push_back(0);
              continue;
          }
          
          ll int idx=cnt;
          
          ll int rem=c-prefix[cnt];
          cnt++;
          set<int>notrem;
          
          for(int i=2;i<(2+k);i++)
          {
              ll int newid=mp[x[i]-1];
              if(newid<=idx)
              {
                  cnt--;
                  rem+=vec[newid].first;
              }
              else
                 notrem.insert(newid);
              
          }
          
          ll int start=idx+1;
          while(start<n && vec[start].first<=rem)
          {
              if(notrem.find(start)==notrem.end())
              {
                  cnt++;
                  rem=rem-vec[start].first;
              }
              start++;

          }
          ans.push_back(cnt);
      }
      return ans;
  }
};
