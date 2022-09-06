class Solution
{
public:
    int isStackPermutation(int n,vector<int> &A,vector<int> &B)
    {
        int k=0;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            st.push(A[i]);
            while(!st.empty() && st.top()==B[k])
            {
                st.pop();
                k++;
            }
        }
        
        while(!st.empty() && st.top()==B[k])
        {
            st.pop();
            k++;
        }
        
        if(st.empty())
        {
            return 1;
        }
        return 0;
        
    }
};
