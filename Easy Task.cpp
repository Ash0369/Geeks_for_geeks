class segment_tree
{
    vector<vector<int>>seg;
    public:
    segment_tree(int n)
    {
        seg.resize(4*n+1);
    }

    void build(int index,int low,int high,string &s)
    {
        if(low==high)
        {
            seg[index]=vector<int>(26,0);
            seg[index][s[low]-'a']=1;
            return;
        }
        
        int mid=(low+high)/2;
        build(2*index+1,low,mid,s);
        build(2*index+2,mid+1,high,s);
        seg[index]=vector<int>(26,0);
        for(int i=0;i<26;i++)
        {
            seg[index][i]=seg[2*index+1][i]+seg[2*index+2][i];
        }
    }

    vector<int> query(int index,int low,int high,int l,int r)
    {
        if(r<low || high<l)
        {
            return vector<int>(26,0);
        }
        if(low>=l && high<=r)
        {
            return seg[index];
        }

        int mid=(low+high)/2;
        auto left=query(2*index+1,low,mid,l,r);
        auto right=query(2*index+2,mid+1,high,l,r);
        vector<int>ans(26,0);
        for(int i=0;i<26;i++)
        {
            ans[i]=left[i]+right[i];
        }
        return ans;
    }

    void update(int index,int low,int high,int i,char x)
    {
        if(low==high)
        {
            seg[index]=vector<int>(26,0);
            seg[index][(int)(x-'a')]=1;
            return;
        }
        int mid=(low+high)/2;
        if(i<=mid)
        {
            update(2*index+1,low,mid,i,x);
        }
        else
        {
            update(2*index+2,mid+1,high,i,x);
        }
        for(int i=0;i<26;i++)
        {
           seg[index][i]=seg[2*index+1][i]+seg[2*index+2][i];
        }
    }

};


class Solution
{
public:
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries)
    {
        segment_tree sg(n+5);
        sg.build(0,0,n-1,s);
        vector<char>ans;
        for(auto x:queries)
        {
            if(stoi(x[0])==1)
            {
              int index=stoi(x[1]);
              s[index]=x[2][0];
              sg.update(0,0,n-1,index,x[2][0]);
            }
            else
            {
                vector<int>rn;
                int l=stoi(x[1]);
                int r=stoi(x[2]);
                int k=stoi(x[3]);
                rn=sg.query(0,0,n-1,l,r);
                
                for(int i=25;i>=0;i--)
                {
                    k=k-rn[i];
                    if(k<=0)
                    {
                        ans.push_back(char(i+97));
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
