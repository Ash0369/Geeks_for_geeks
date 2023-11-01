class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        int n=N;
        int p=P;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>n)
            {
                arr[i]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]%(n+1)==0)
            {
                continue;
            }
            int ele=arr[i]%(n+1);
            arr[ele-1]+=n+1;
        }
        for(int i=0;i<n;i++)
        {
            arr[i]=arr[i]/(n+1);
        }
    }
};
