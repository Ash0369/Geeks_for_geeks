bool allocate(int value,int n,int A[],int size)
{
    int page=0;
    int count=1; //Allocating to 1st student
    for(int i=0;i<size;i++)
    {
        if(A[i]>value)
        {
            return false;
        }
        else if(page+A[i]>value)
        {
            count++;
            page=A[i];
        }
        else
        {
            page=page+A[i];
        }
        
    }
    if(count<=n)
    {
        //cout<<value<<endl;
        return true;
    }
    return false;
}
class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N)
        {
            return -1;
        }
        int low=A[0];
        int high=0;
        for(int i=0;i<N;i++)
        {
            high=high+A[i];
            low=min(low,A[i]);
        }
        int res=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(allocate(mid,M,A,N))
            {
                res=min(res,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return res;
    }
};
