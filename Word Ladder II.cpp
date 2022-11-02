class Solution 
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<vector<string>>q;
        q.push({beginWord});
        
        set<string>st;
        for(auto x:wordList)
        {
            st.insert(x);
        }
        st.erase(beginWord);
        vector<vector<string>>ans;
        while(!q.empty())
        {
            vector<string>to_remove;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto node=q.front();
                q.pop();
                string s=node[node.size()-1];
                if(s==endWord)
                {
                    ans.push_back(node);
                    for(int j=i+1;j<n;j++)
                    {
                        auto node=q.front();
                        q.pop();
                        string s=node[node.size()-1];
                        if(s==endWord)
                        {
                            ans.push_back(node);
                        }
                    }
                    return ans;
                }
                for(int j=0;j<s.length();j++)
                {
                    char a=s[j];
                    for(int k=97;k<=122;k++)
                    {
                        s[j]=char(k);
                        if(a==s[j])
                        {
                            continue;
                        }
                        if(st.find(s)!=st.end())
                        {
                            to_remove.push_back(s);
                            node.push_back(s);
                            q.push(node);
                            node.pop_back();
                        }
                    }
                    s[j]=a;
                }
            }
            for(auto x:to_remove)
            {
                st.erase(x);
            }
            
        }
        return {};
    }
};
