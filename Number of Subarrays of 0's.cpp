#define ll long long
long long int no_of_subarrays(int n, vector<int> &arr) 
{
    ll int prev=0;
    ll int ans=0;
    for(int right=0;right<n;right++)
    {
        if(arr[right]==0)
        {
            ans=ans+(prev)+1;
            prev++;
        }
        else
        {
            prev=0;
        }
    }
    return ans;
}
