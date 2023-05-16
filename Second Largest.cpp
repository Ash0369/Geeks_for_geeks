class Solution
{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) 
	{
	    int mx1=arr[0];
	    int mx2=-1;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>mx1)
	        {
	            mx2=mx1;
	            mx1=arr[i];
	        }
	        else if(arr[i]>mx2 && arr[i]<mx1)
	        {
	            mx2=arr[i];
	        }
	    }
	    return mx2;
	}
};
