class Solution{
public: 
    bool checkSorted(int N, vector<int>a)
    {
        int n=N;
        if(n==1)
        {
            return false;
        }
        vector<int>vec=a;
        
        sort(vec.begin(),vec.end());
        
        int cnt=0;
        int cnt1=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=(i+1))
            {
                if(a[a[i]-1]==(i+1))
                {
                    cnt++;
                }
                else
                {
                    cnt1++;
                }
            }
        }
        if(cnt1<=3 && cnt==0)
        {
            return true;
        }
        if(cnt1>0)
        {
            return false;
        }
        return cnt==0 || cnt==4;
    }   
};
