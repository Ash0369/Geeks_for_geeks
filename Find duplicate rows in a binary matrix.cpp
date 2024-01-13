class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int m, int n) 
    { 
        vector<int>ans;
        map<vector<int>,int>mp;
        
        for(int i=0;i<m;i++)
        {
            if(mp.find(matrix[i])==mp.end())
            {
                mp[matrix[i]]=1;
            }
            else
            {
                ans.push_back(i);
            }
        }
        return ans;
      
    } 
};
