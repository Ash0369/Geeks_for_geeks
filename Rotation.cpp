class Solution
{
public:	
	int findKRotation(int arr[], int n) 
	{
	    int count=0;
	    int prev=0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]<prev)
	        {
	            break;
	        }
	        prev=arr[i];
	        count++;
	    }
	    if(count==n)
	    {
	        return 0;
	    }
	    return count;
	}
};
