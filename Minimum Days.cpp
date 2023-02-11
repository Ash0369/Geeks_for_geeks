bool check(int mid,vector<int>&p,string s)
{
    int n=p.size();
    for(int i=0;i<mid;i++)
    {
        s[p[i]]='?';
    }
    for(int i=0;i<n-1;i++)
    {
        if(s[i]!='?' && s[i]==s[i+1])
        {
            return false;
        }
    }
    return true;
}
class Solution 
{
  public:
    int getMinimumDays(int N,string S, vector<int> &P) 
    {
        int n=N;
        int left=0;
        int right=n-1;
        int ans=right;
        
        while(left<=right)
        {
            int mid=(left+right)>>1;
            if(check(mid,P,S))
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        
        return ans;
    }
};
