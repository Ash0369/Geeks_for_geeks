class Solution {
  public:
    int minimum_difference(int n, vector<string> &words) 
    {
        int ans1=1e9;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                string a=words[i];
                string b=words[j];
                
                //now we will check
                int ans=0;
                for(int i=0;i<a.size();i++)
                {
                    if(a[i]==b[i]) continue;
                    
                    ans+=min(abs(b[i]-a[i]),'z'-max(b[i],a[i])+min(b[i],a[i]));
                }
                ans1=min(ans1,ans);
                
            }
        }
        return ans1;
    }
};
