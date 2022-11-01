class Solution 
{
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        set<string>st;
        for(auto x:wordList)
            st.insert(x);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            string s=node.first;
            int pos=node.second;
            if(s==endWord)
                return pos;
            st.erase(s);
            
            for(int j=0;j<s.length();j++)
            {
                for(int i=97;i<=126;i++)
                {
                    char c=char(i);
                    string temp=s;
                    temp[j]=c;
                    if(st.find(temp)!=st.end())
                    {
                        q.push({temp,pos+1});
                    }
                }
            }
        }
        return 0;
    }
};
