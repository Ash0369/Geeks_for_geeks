class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
            int left=(2*i)+1;
            int right=(2*i)+2;
            int lar=i;
            if(left<n && arr[i]<arr[left])
            {
                lar=left;
                
            }
            if(right<n && arr[lar]<arr[right])
            {
                lar=right;
            }
            
            if(lar!=i)
            {
                swap(arr[i],arr[lar]);
                heapify(arr,n,lar);
            }
              
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    {
        for(int i=n/2-1;i>=0;i--)
        {
            heapify(arr,n,i);  
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        /*for(int i=0;i<n;i++)
        {
        cout<<arr[i]<<" ";
        }
        cout<<endl;*/
       
        for(int i=n-1;i>=0;i--)
        {
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }
};
