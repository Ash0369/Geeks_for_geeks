bool compare(pair<int,int>& a , pair<int,int>& b){
    return (a.first == b.first) ? a.second > b.second : a.first > b.first;
}
class Solution 
{
  public:
    vector<int> topK(vector<int>& nums, int k) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++)
        {
            int f=1;
            i++;
            while(i<n && nums[i]==nums[i-1])
            {
                f++;
                i++;
            }
            i--;
            v.push_back({f,nums[i]});
        }
        sort(v.begin(),v.end(),compare);
       // reverse(v.begin(),v.end());
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
