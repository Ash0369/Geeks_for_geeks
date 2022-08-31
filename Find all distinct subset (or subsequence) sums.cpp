set<int>st;
int sumc(vector<int>&nums,int index,int sum,vector<vector<int>>&dp)
{
    
    if(index==-1)
    {
        st.insert(sum);
        return st.size();
    }
    
    if(dp[index][sum]==-1)
    {
        int l=sumc(nums,index-1,sum+nums[index],dp);
        int r=sumc(nums,index-1,sum,dp);
        dp[index][sum]=l+r;
    }
    return dp[index][sum];
    
}
class Solution 
{
public:
	vector<int> DistinctSum(vector<int>nums)
	{
	    st.clear();
	    int sum=0;
	    int n=nums.size();
	    for(auto x:nums)
	    {
	        sum=sum+x;
	    }
	    vector<vector<int>>dp(100,vector<int>(10000,-1));
	    sumc(nums,nums.size()-1,0,dp);
	    vector<int>res;
	    while(!st.empty())
	    {
	        res.push_back((*st.begin()));
	        st.erase((*st.begin()));
	    }
	    return res;
	}
};
