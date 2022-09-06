//Method-1 : O(n) Time Complexity

class Solution
{
public:	
	int count(int arr[], int n, int x) 
	{
	    int count=0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]==x)
	        {
	            count++;
	        }
	    }
	    return count;
	}
};


//Method-2 : O(log(n)) Binary search:

int search(int arr[],int l,int r,int k)
{
    if(r<l)
    {
        return 0;
    }
    int mid=(l+r)/2;
    int ele=arr[mid];
    if(ele==k)
    {
        int a=search(arr,l,mid-1,k);
        int b=search(arr,mid+1,r,k);
        return 1+a+b;
    }
    if(ele>k)
    {
        return  search(arr,l,mid-1,k);
    }
    
    return search(arr,mid+1,r,k);
    
}

class Solution
{
public:	
	int count(int arr[], int n, int x) 
	{
	    return search(arr,0,n-1,x);
	}
};
