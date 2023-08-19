class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    return lower_bound(arr,arr+n,x+1)-lower_bound(arr,arr+n,x);
	}
};
