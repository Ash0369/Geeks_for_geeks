class Solution{
public:
    string flipCoins(int N, string s){
        int c=0;
        for(auto x:s)
        {
            if(x=='0') c++;
        }
        if(c%2==0)
        {
            return "Yes";
        }
        return "No";
    }
};
