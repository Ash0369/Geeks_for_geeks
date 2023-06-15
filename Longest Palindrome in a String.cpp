class Solution 
{
  public:
    string longestPalin (string S) 
    {
        string s=S;
        int ans=0;
        string p;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            //odd length
            int left=i-1;
            int right=i+1;
            int cnt=1;
            while(left>=0 && right<n && s[left]==s[right])
            {
                cnt=cnt+2;
                left--;
                right++;
            }
            if(cnt>ans)
            {
                left++;
                right--;
                p=s.substr(left,right-left+1);
                ans=right-left+1;
            }
            
            //even length
            
            left=i;
            right=i+1;
            cnt=0;
            while(left>=0 && right<n && s[left]==s[right])
            {
                cnt=cnt+2;
                left--;
                right++;
            }
            if(cnt>ans)
            {
                left++;
                right--;
                p=s.substr(left,right-left+1);
                ans=right-left+1;
            }
        }
        return p;
    }
};
