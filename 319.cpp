int square_root(int n)
{
    int low=1;
    int high=n;
    while((high-low)>1)
    {
        int mid=(low+high)/2;
        if((1LL*mid*mid)<n)
        {
            low=mid;
        }
        else
        {
            high=mid;
        }
    }
    return high;
}
class Solution 
{
public:
    int bulbSwitch(int n) 
    {
        if(n==0)
            return 0;
        return square_root(n+1)-1;
    }
};
