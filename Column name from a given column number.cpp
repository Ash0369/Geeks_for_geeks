#define ll long long
class Solution
{
    public:
    string colName (long long int n)
    {
        string s;
        while(n>0)
        {
            char c = --n % 26 + 'A';
            s=c+s;
            n=n/26;
        }
        return s;
    }
};
