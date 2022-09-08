//Method-1 :

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


//Method-2 : 

int binary_search(int arr[],int n,int l,int r)
{
    if(l>r)
    {
        return 0;
    }
    int index=(l+r)/2;
    
    int next=(index+1)%n;
    int prev=(index+n-1)%n;
    
    
    if(arr[next]>arr[index] && arr[prev]>arr[index])
    {
        return index;
    }
    //go in direction where array is not sorted
    
    if(arr[0]<=arr[index])
    {
        return binary_search(arr,n,index+1,r);
    }
    else if(arr[index]<=arr[n-1])
    {
        return binary_search(arr,n,l,index-1);
    }
}
class Solution
{
public:	
	int findKRotation(int arr[], int n) 
	{
	    return binary_search(arr,n,0,n-1);
	}
	
};
