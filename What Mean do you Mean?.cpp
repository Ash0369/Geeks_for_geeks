#define ll long long
class Solution{
    public:
    bool IsMean(int n, int k, int x, vector<int> &arr)
    {
        ll int sum=0;
        for(auto x:arr)
        {
            sum+=x;
        }
        ll int need=x*n;
        
        if(need<sum)
        {
            return false;
        }
    
        if(k==1 )
        {
            return need==sum;
        }
        
        ll int r=(need-sum)/(k-1);
        if((need-sum)%(k-1)!=0)
        {
            return false;
        }
        sort(arr.begin(),arr.end());
        
        int i=0;
        int j=n-1;
        
        while(i<j)
        {
            if(arr[i]+arr[j]==r)
            {
                return true;
            }
             if(arr[i]+arr[j]>r)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};
