class Solution{
public:
    int remove_duplicate(int arr[],int n)
    {
        int i=0;
        int j=1;
        while(j<n)
        {
            if(arr[j]==arr[i])
            {
                j++;
                continue;
            }
            else
            {
                arr[i+1]=arr[j];
                i++;
            }
            j++;
        }
        return i+1;
    }
};
