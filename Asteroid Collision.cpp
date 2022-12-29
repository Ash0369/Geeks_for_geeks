class Solution 
{
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) 
    {
        // code here
        int n=N;
        stack<int>st;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            if(asteroids[i]>0)
            {
                st.push(asteroids[i]);
            }
            else
            {
                if(st.empty())
                {
                    v.push_back(asteroids[i]);
                }
                else
                {
                    while(!st.empty() && abs(asteroids[i])>st.top())
                    {
                        st.pop();
                    }
                    if(!st.empty() && abs(asteroids[i])==st.top())
                    {
                        st.pop();
                    }
                    else if(st.empty())
                    {
                        v.push_back(asteroids[i]);
                    }
                }
            }
        }
        vector<int>temp;
        while(!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        v.insert(v.end(),temp.begin(),temp.end());
        return v;
    }
};
