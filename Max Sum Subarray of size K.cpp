class Solution
{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int N)
    {
        long long int max_sum=0;
        int i;
        for(i=0;i<k;i++)
        {
            max_sum=max_sum+arr[i];
        }
        long long int sum=max_sum;
        int ka=0;
        for(int j=i;j<N;j++)
        {
            sum=sum-arr[ka];
            sum=sum+arr[j];
            max_sum=max(max_sum,sum);
            ka++;
        }
        return max_sum;
    }
};
