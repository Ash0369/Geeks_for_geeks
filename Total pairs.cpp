class Solution 
{
public:
	int TotalPairs(vector<int>&nums, int x, int y)
	{

	    int cnt=0;
	    sort(nums.begin(),nums.end());
	    int n=nums.size();
	    for(int i=0;i<n;i++)
	    {
	        int ele=nums[i];
	        
	        //we should get x
	        
	        int lower=(x+ele-1)/ele;
	        
	        int upper=(y+ele-1)/ele;
	        if((upper*ele)<=y)
	        {
	            upper++;
	        }
	        //lower=max(lower,ele);
	        //upper=max(upper,ele);
	        
	        auto index=lower_bound(nums.begin(),nums.end(),lower);
	        auto index1=lower_bound(nums.begin(),nums.end(),upper);
	        if(index==nums.end() && index1==nums.end())
	        {
	            continue;
	        }
	        int ans=(index-nums.begin());
	        ans=max(i+1,ans);
	        if(index1!=nums.end())
	        {
	            int temp=index1-nums.begin();
	            temp=max(temp,i+1);
	            temp--;
	            
	            ans=(temp-(ans-1));
	        }
	        else
	        {
	            ans=(n-1-(ans-1));
	        }
	        cnt+=ans;
	        
	        
	    }
	    return cnt;
	}
};
