#define ll long long
ll int merge(int left,int mid,int right,vector<int>&arr)
{
    ll int cnt=0;
    int aptr=left;
    int bptr=mid+1;
    int i=0;
    vector<ll int>temp;
    while(aptr<=mid && bptr<=right)
    {
        if(arr[aptr]>=arr[bptr])
        {
            temp.push_back(arr[bptr]);
            bptr++;
        }
        else
        {
            cnt+=right-bptr+1;
            temp.push_back(arr[aptr]);
            aptr++;
        }  
    }
    while(aptr<=mid)
    {
        temp.push_back(arr[aptr]);
        aptr++;
    }
    
    while(bptr<=right)
    {
         temp.push_back(arr[bptr]);
         bptr++;
    }
    
    int ptr=0;
    for(int i=left;i<=right;i++)
    {
        arr[i]=temp[ptr];
        ptr++;
    }
    return cnt;
}

ll int merge_sort(vector<int>&arr, int left,int right)
{
    ll int ans=0;
    if(left>=right)
        return 0;
    
    int mid=(left+right)/2;
    ans+=merge_sort(arr,left,mid);
    ans+=merge_sort(arr,mid+1,right);
    ans+=merge(left,mid,right,arr);
    return ans;
}

class Solution
{
public:
  long long countSubstring(string S)
  {
      string s=S;
      int n=s.length();
      vector<int>vec;
      int cnt=0;
      for(auto x:s)
      {
         if(x=='0')
         {
             vec.push_back(-1);
         }
         else
         {
             //cnt++;
             vec.push_back(1);
         }
      }
      if(vec[0]>0)
      {
          cnt++;
      }
      for(int i=1;i<n;i++)
      {
          vec[i]+=vec[i-1];
          if(vec[i]>0)
          {
              cnt++;
          }
      }
      return cnt+merge_sort(vec,0,n-1);
  }
};
