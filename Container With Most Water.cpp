#define ll long long
long long maxArea(long long A[], int len)
{
    int left=0;
    int right=len-1;
    int ans=0;
    while(left<right)
    {
        int h=min(A[left],A[right]);
        ans=max(ans,(right-left)*h);
        
        if(A[left]>A[right])
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return ans;
}
