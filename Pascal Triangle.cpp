int mod=1e9+7;
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int numRows) {
        vector<vector<ll int>>result;
        for(int i=0;i<numRows;i++)
        {
           
            vector<ll int>temp(i+1,1);
            for(int j=1;j<i;j++)
            {
                ll int a=result[i-1][j-1];
                ll int b=result[i-1][j];
                temp[j]=(a+b)%mod;
            }
            result.push_back(temp);
        }
        return result[numRows-1];
    }
};
