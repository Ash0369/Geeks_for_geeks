int price_cal(int price[],int n,int index,int right,vector<vector<int>>&vec)
{
    if(index==0)
    {
        return price[right-1];
    }
    if(vec[index][right]==-1)
    {
        int cut=INT_MIN;
        if(index!=right)
        {
            cut=price[right-index-1]+price_cal(price,n,index-1,index,vec);
        }
        int not_cut=price_cal(price,n,index-1,right,vec);
        vec[index][right]=max(cut,not_cut);
    }
    return vec[index][right];
}
class Solution
{
  public:
    int cutRod(int price[], int n) 
    {
        vector<vector<int>>vec(n+1,vector<int>(n+1,-1));
        return price_cal(price,n,n,n,vec);
    }
};
