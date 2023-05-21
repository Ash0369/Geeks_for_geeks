class Solution
{
public:	
	int search(int A[], int N)
	{
	    int xr=0;
        for(int i=0;i<N;i++)
        {
            int x=A[i];
            xr=xr^x;
        }
        return xr;
	}
};
