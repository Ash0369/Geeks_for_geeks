#define ll long long
class Solution 
{
  public:
    long long solve(int n, int k, vector<long long> GeekNum) 
    {
        ll int sum=0;
        for(int i=0;i<k;i++)
        {
            sum=sum+1LL*GeekNum[i];
        }
        GeekNum.push_back(sum);
        //cout<<sum<<endl;
        if(n<=k)
        {
            return GeekNum[n-1];
        }
        else if(n==k+1)
        {
            return sum;
        }
        else
        {
            int intial=0;
            int index=k;
            while(index!=n-1)
            {
                sum=(2*sum)-1LL*GeekNum[intial];
                GeekNum.push_back(sum);
                intial++;
                index++;
                //cout<<sum<<endl;
            }
            return sum;
        }
    }
};
