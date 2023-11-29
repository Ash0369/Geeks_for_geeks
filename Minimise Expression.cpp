class Solution
{
public:
    int minimiseExpression(vector<int> &A, int N)
    {
        int n=N;
        long long int av=0;
        for(auto x:A)
        {
            av+=x;
        }
        av=av/n;
        int ans=0;
        for(auto x:A)
        {
            ans+=(abs(x-av)*abs(x-av));
        }
        return av;
    }
};
