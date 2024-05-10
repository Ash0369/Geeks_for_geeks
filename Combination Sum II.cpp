set<vector<int>>ans;

void dfs(int index,int n,int k,vector<int>&arr,vector<int>&c)
{
    if(k==0)
    {
        ans.insert(c);
        return;
    }
    if(index==n){
        return;
    }
    dfs(index+1,n,k,arr,c);
    if(arr[index]<=k){
        c.push_back(arr[index]);
        dfs(index+1,n,k-arr[index],arr,c);
        c.pop_back();
    }
    
}
class Solution{
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        sort(arr.begin(),arr.end());
        ans.clear();
        vector<int>t;
        
        dfs(0,n,k,arr,t);
        
        vector<vector<int>>ans1;
        for(auto x:ans){
            ans1.push_back(x);
        }
        return ans1;
    }
};
