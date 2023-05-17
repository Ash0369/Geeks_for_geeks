class Solution{
public:
	void pushZerosToEnd(int arr[], int n) 
	{
        int j=0;
        while(j<n && arr[j]!=0)
        {
            j++;
        }
        if(j==n)
        {
            return;
        }
        for(int i=j+1;i<n;i++)
        {
            if(arr[i]!=0)
            {
                swap(arr[i],arr[j]);
                j++;
            }
        }
	}
};
