class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n=arr.size();
        vector<int>ans(n,INT_MAX);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=st.top();
            }
            st.push(i);
           
        }
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                int d=st.top();
                if(ans[i]==INT_MAX)
                {
                    st.push(i);
                    ans[i]=d;
                    continue;
                }
                if(abs(i-ans[i])>abs(d-i))
                {
                    ans[i]=d;
                }
                else if((i-ans[i])==(d-i))
                {
                    if(arr[ans[i]]>arr[d])
                    {
                        ans[i]=d;
                    }
                }
            }
            st.push(i);
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i]==INT_MAX)
            {
                ans[i]=-1;
            }
        }
        return ans;
    }
};
