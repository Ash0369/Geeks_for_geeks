class Solution
{
    public:
    vector <int> lexicographicallyLargest(vector <int> &a,int n)
    {
        for(int i=0;i<n;i++)
        {
            int x=a[i]%2;
            int start=i;
            i++;
            while(i<n && a[i]%2==x)
            {
                i++;
            }
            i--;
            sort(a.begin()+start,a.begin()+i+1,greater<int>());
        }
        return a;
    }
};
