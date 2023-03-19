class Solution 
{
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) 
    {
        int n=N;
        vector<int>left(n+1,0);
        vector<int>right(n+1,0);
        set<int>st;
        for(int i=0;i<n;i++)
        {
            st.insert(A[i]);
            left[i+1]=st.size();
        }
        st.clear();
        for(int i=n-1;i>0;i--)
        {
            st.insert(A[i]);
            right[i-1]=st.size();
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i]=left[i]-right[i];
        }
        return ans;
    }
};
