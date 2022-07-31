vector<int>result;
void subset_sum(vector<int>&arr,int sum,int index)
{
    if(index>=arr.size())
    {
        result.push_back(sum);
        return;
    }
    subset_sum(arr,sum+arr[index],index+1);
    subset_sum(arr,sum,index+1);
    
}
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int n)
    {
        result.clear();
        subset_sum(arr,0,0);
        return result;
    }
};
