class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        vector<int>mxl(n+1,0);
        vector<int>mnl(n+1,0);
        
        vector<int>mxr(n,0);
        vector<int>mnr(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            mxl[i]=arr[i];
            mnl[i]=arr[i];
            
            if(i>0){
                mxl[i]=max(mxl[i-1],mxl[i]);
                mnl[i]=min(mnl[i-1],mnl[i]);
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            mxr[i]=arr[i];
            mnr[i]=arr[i];
            
            if(i!=n-1){
                mxr[i]=max(mxr[i+1],mxr[i]);
                mnr[i]=min(mnr[i+1],mnr[i]);
            }
        }
        
        int ans=1e9;
        
        for(int i=k-1;i<n;i++)
        {
            //I remove til i
            
            int left=i-k+1;
            
            int mx=-1;
            int mn=1000000000;
            
            if(i+1<n)
            {
                mx=mxr[i+1];
                mn=mnr[i+1];
            }
            if(left-1>=0)
            {
                mx=max(mx,mxl[left-1]);
                mn=min(mn,mnl[left-1]);
            }
            if(mn==1000000000 && mx==-1)
            {
                continue;
            }
            else if(mn==1000000000 || mx==-1)
            {
                ans=0;
                continue;
            }
            ans=min(ans,mx-mn);
        }
        return ans;
    }
};
