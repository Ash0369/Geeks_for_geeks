class Solution
{
    //Complete the function and return minimum number of operations
    public:
    int specialPalindrome(string s1, string s2)
    {
        int n1=s1.size();
        int n2=s2.size();
        
        vector<int>dp(n1,0);
        int j=n1-1;
        for(int i=0;i<n1;i++)
        {
            if(i!=0)
            {
                dp[i]=dp[i-1];
            }
            if(s1[i]!=s1[j])
            {
                dp[i]+=1;
            }
            j--;
        }
        
        int ans=INT_MAX;
        string s=s1;
        for(int i=0;i<=n1-n2;i++)
        {
            s1=s;
            int k=i;
            int curr=0;
            for(int j=0;j<n2;j++)
            {
                char c=s2[j];
                
                if(s1[k]!=c)
                {
                    s1[k]=c;
                    curr++;
                }
                k++;
               
            }
            k--;
            for(int j=0;j<i;j++)
            {
                if(s1[j]!=s1[n1-j-1])
                {
                    
                    curr++;
                    s1[j]=s1[n1-j-1];
                }
            }
            for(int j=i;j<=k;j++)
            {
                if(s1[j]!=s1[n1-j-1])
                {
                    if(n1-j-1<=k)
                    {
                        curr+=10000;
                    }
                    curr++;
                    s1[j]=s1[n1-j-1];
                }
            }
            for(int j=k+1;j<n1;j++)
            {
                if(s1[j]!=s1[n1-j-1])
                {
                    
                    curr++;
                    s1[j]=s1[n1-j-1];
                }
            }
            ans=min(ans,curr);
        }
        if(ans>=10000)
        {
            ans=-1;
        }
        return ans;
    }
};
