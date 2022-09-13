//Method-1 : Linear Search

class Solution
{
public:
	
	int findMaximum(int arr[], int n) 
	{
	    int prev=-1;
	    for(int i=0;i<n;i++)
	    {
	        int x=arr[i];
	        if(x<prev)
	        {
	            return prev;
	        }
	        prev=x;
	    }
	}
};

//Method-2 : Binary Search :


int binary_search(int arr[],int n,int l,int r)
{
    if(l>r)
    {
        return -1;
    }
    int mid=(l+r)/2;
    if(mid>0 && arr[mid-1]<arr[mid]  && mid<n-1 && arr[mid]>arr[mid+1])
    {
        return arr[mid];
    }
    else if(mid>0 && arr[mid-1]<arr[mid])
    {
        return binary_search(arr,n,mid+1,r);
    }
    return binary_search(arr,n,l,mid-1);
    
}
class Solution
{
public:
	
	int findMaximum(int arr[], int n) 
	{
	    int ans=binary_search(arr,n,0,n-1);
	    if(ans==-1)
	    {
	        return arr[n-1];
	    }
	    return ans;
	}
};
