class Solution{
public:
    int count_set_bits(int *arr, int n) {
        int ans=0;
        while(n--)
        {
            ans+=__builtin_popcount(*arr);
            arr++;
        }
        return ans;
    }
};
