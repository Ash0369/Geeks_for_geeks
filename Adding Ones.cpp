class Solution{
    public:
    void update(int a[], int n, int updates[], int k)
    {
        sort(updates,updates+k);
        int sum=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            while(j<k && updates[j]<=(i+1))
            {
                sum++;
                j++;
            }
            a[i]=sum;
        }
    }
};
