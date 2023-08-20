vector<int> rotate(vector<int>&arr)
{
    int e=arr.back();
    arr.pop_back();
    vector<int>ans;
    ans.push_back(e);
    for(int i=0;i<arr.size();i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}
class Solution{
    public:
    int min_operations(int n, vector<int>&arr, vector<int>&brr) {
	    reverse(arr.begin(),arr.end());
	    reverse(brr.begin(),brr.end());
	    int ans=0;
	    while(arr.size()>0)
	    {
	        if(arr.back()==brr.back())
	        {
	            ans++;
	            arr.pop_back();
	            brr.pop_back();
	        }
	        else
	        {
	            ans++;
	            arr=rotate(arr);
	        }
	    }
	    return ans;
	    
    }
};
