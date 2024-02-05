class Solution {
  public:
    int ReturnToRoot(int N, vector<string> &M) {
        int d=0;
        for(auto x:M)
        {
            if((x[0]!=('.')))
            {
                d++;
            }
            else if((x[1]==('/')))
            {
                
            }
            else{
                d--;
            }
            
        }
        return d;
    }
};
