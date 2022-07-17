class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
    void swap(int &a,int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    void bubbleSort(int arr[], int n)
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<(n-i-1);j++)
            {
                if(arr[j]>arr[j+1])
                {
                    swap(arr[j],arr[j+1]);
                }
            }
        }  
    }
};
