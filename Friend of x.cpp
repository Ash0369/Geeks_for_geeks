class Solution {
  public:
    string isFriend(int n, int x, int y, vector<int> &arr) {
        for(auto x1:arr)
        {
            if((x1+x)==y)
            {
                return "yes";
            }
        }
        return "no";
    }
};
