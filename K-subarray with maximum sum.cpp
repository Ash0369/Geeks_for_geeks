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
        a.value=max(a.value,b.value);
        return a;
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
            return make(-1000000000000000);
        }
        if(low==lq && high==rq)
        {
            return sg[index];
        }
        int mid=(low+high)/2;
        data left=query(low,mid,lq,min(rq,mid),(2*index)+1);
        data right=query(mid+1,high,max(lq,mid+1),rq,(2*index)+2);
        return combine(left,right);
    }


};
class Solution 
{
  public:
    long long kMaxSubarray(int n, int k, vector<int> &arr) 
    {
       segment_tree sg(n+2);
       vector<ll int>psum(n,arr[0]);
       for(int i=1;i<n;i++)
       {
           psum[i]=psum[i-1]+arr[i];
       }
       sg.build(0,n-1,psum);
       ll int ans=arr[0];
       
       for(int i=0;i<n;i++)
       {
           //Find max we get
           ll int av=sg.query(0,n-1,i,min(n-1,i+k-1)).value;
           //cout<<i<<" "<<av<<endl;
           if(i>0)
           {
               av=av-psum[i-1];
           }
           ans=max(ans,av);
           //break;
       }
       return ans;
    }
};
