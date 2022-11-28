class Solution
{
public:
	vector<int> findSubarray(int a[], int n) 
	{
	    int ans=INT_MIN;
	    int curr=INT_MIN;
	    int curr_index=0;
	    int mx_sum=a[0];
	    int start=0;
	    int end=0;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]<0)
	        {
	            curr=INT_MIN;
	            continue;
	        }
	        else if(curr==INT_MIN)
	        {
	            curr=a[i];
	            curr_index=i;
	            if(curr>ans)
	            {
	                ans=curr;
	                start=i;
	                end=i;
	            }
	            
	        }
	        else
	        {
	            curr+=a[i];
	            if(curr > ans || (curr == ans && (i - curr_index > end-start)))
	            {
	                ans=curr;
	                start=curr_index;
	                end=i;
	            }
	        }
	        
	    }
	    
	    vector<int>res;
	    if(ans==INT_MIN)
	    {
	        return {-1};
	    }
	    for(int i=start;i<=end;i++)
	    {
	        res.push_back(a[i]);
	    }
	    return res;

	}
};
