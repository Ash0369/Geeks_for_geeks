#define ll long long
class segment_tree
{
    public:
    struct data
    {
        ll int value=0;
    };
    vector<data>sg;
    vector<data>lazy;
    segment_tree(int n)
    {
        data d;
        d.value=0;
        sg.resize(4*(n+1));
        lazy.resize(4*(n+1),d);
    }
    data make(ll int val)
    {
        data res;
        res.value=val;
        return res;
    }
    data combine(data a,data b)
    {
        a.value=a.value&b.value;
    }
    void push(int index)
    {
        sg[(2*index)+1].value+=lazy[index].value;
        lazy[(2*index)+1].value+=lazy[index].value;

        sg[(2*index)+2].value+=lazy[index].value;
        lazy[(2*index)+2].value+=lazy[index].value;

        lazy[index].value=0;
    }
    void build(int low,int high,vector<ll int>&arr,int index=0)
    {
        if(low>high)
        {
            return;
        }
        if(low==high)
        {
            sg[index]=make(arr[low]);
            return;
        }
        int mid=(low+high)/2;
        build(low,mid,arr,(2*index)+1);
        build(mid+1,high,arr,(2*index)+2);

        sg[index]=combine(sg[(2*index)+1],sg[(2*index)+2]);
    }
    data query(int low,int high,int lq,int rq,int index=0)
    {
        if(lq>rq)
        {
            return make(-1);
        }
        if(low==lq && high==rq)
        {
            return sg[index];
        }
        push(index);
        int mid=(low+high)/2;
        data left=query(low,mid,lq,min(rq,mid),(2*index)+1);
        data right=query(mid+1,high,max(lq,mid+1),rq,(2*index)+2);
        return combine(left,right);
    }

};
class Solution 
{
  public:
    vector<int> minQuery(int N, int Q, vector<int> &A, vector<vector<int>> &q) 
    {
        int n=N;
        segment_tree sg(n+2);
        vector<ll int>vec;
        for(auto x:A)
        {
            vec.push_back(x);
        }
        sg.build(0,n-1,vec);
        vector<int>ans;
        for(auto x:q)
        {
            int l1=x[0];
            int r1=x[1];
            
            int l2=x[2];
            int r2=x[3];
            
            l1--;
            l2--;
            r1--;
            r2--;
            
            
            ll int t1=sg.query(0,n-1,l1,r1).value;
            ll int t2=sg.query(0,n-1,l2,r2).value;
            ans.push_back(t1|t2);
        }
        return ans;
        
    }
};
