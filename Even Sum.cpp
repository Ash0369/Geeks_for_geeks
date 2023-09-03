class Solution {
  public:
    int findMin(int A[], int n)
    {
        vector<int>odd;
        vector<int>even;
        for(int i=0;i<n;i++)
        {
            if(A[i]%2==0)
            {
                even.push_back(A[i]);
            }
            else
            {
                odd.push_back(A[i]);
            }
        }
        sort(even.begin(),even.end());
        int sz=odd.size();
        if(sz%2==0)
        {
            return 0;
        }
       // return 0;
        int op=1e9;
        for(auto x:even)
        {
           // cout<<x<<endl;
            int p=0;
            int ele=x;
            while(ele%2==0 && ele>0)
            {
                ele=ele/2;
                p++;
            }
            op=min(op,p);
        }
        if(op==1e9)return -1;
        return op;
    }
};
