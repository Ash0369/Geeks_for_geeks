class Solution{   
public:
    void leftRotate(int arr[], int n, int k) 
    {
         k=k%n;
	    reverse(arr,arr+k);
	    reverse(arr+k,arr+n);
	    reverse(arr,arr+n);
    }
};
