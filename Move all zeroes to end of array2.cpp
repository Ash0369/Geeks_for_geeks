class Solution
{
public:
	void pushZerosToEnd(int arr[], int n) 
	{
	    int i=0;
	    int j=1;
	    while(i<n)
	    {
	        if(arr[i]!=0)
	        {
	            i++;
	            continue;
	        }
	        j=max(j,i+1);
	        while(j<n && arr[j]==0)
	        {
	            j++;
	        }
	        if(j<n)
	        {
	            swap(arr[i],arr[j]);
	            i++;
	        }
	        else{
	            break;
	        }
	    }
	}
};
