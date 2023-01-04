//Method-1: O(n*n) Space Complexity so will give Segementaton error after Test Case 140

//Ihis problem is just finding longest strictly increasing subsequence

int assembly(int n,int h[],int index,int prev,vector<vector<int>>&dp)
{
    if(index==n)
    {
        return 0;
    }
    if(dp[index][prev]!=-1)
    {
        return dp[index][prev];
    }
    int choose=0;
    if(prev==0 || h[prev-1]<h[index])
    {
        choose=1+assembly(n,h,index+1,index+1,dp);
    }
    int not_choose=assembly(n,h,index+1,prev,dp);
    
    return dp[index][prev]=max(choose,not_choose);
}
class Solution 
{
  public:
    int removeStudents(int H[], int N) 
    {
        int n=N;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return n-assembly(n,H,0,0,dp);
    }
};

//Method-2 : Time Complexity O(n*n) so give TLE after Test case 140

class Solution 
{
  public:
    int removeStudents(int H[], int N) 
    {
        int n=N;
        vector<int>dp(n+1,-1);
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            int mx=0;
            for(int j=i+1;j<n;j++)
            {
                if(H[j]>H[i])
                {
                    mx=max(mx,dp[j]);
                }
            }
            dp[i]=1+mx;
        }
        
        return n-*max_element(dp.begin(),dp.end());
    }
};

//Method-3 : 

class Solution 
{
  public:
    int removeStudents(int H[], int N) 
    {
        int n=N;
        vector<int>dp;
        for(int i=0;i<n;i++)
        {
            int index=lower_bound(dp.begin(),dp.end(),H[i])-dp.begin();
            if(index==dp.size())
            {
                dp.push_back(H[i]);
            }
            else
            {
                dp[index]=H[i];
            }
        }
        return n-dp.size();
    }
};
