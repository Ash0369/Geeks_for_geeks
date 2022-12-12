class Solution 
{
  public:
    int totalTime(int n, vector<int> &arr, vector<int>&time) 
    {
        vector<int>curr(n+1,-1);
        int tme=0;
        for(int i=0;i<n;i++)
        {
            int ele=arr[i];
            int wait=time[ele-1];
            
            if(curr[ele]==-1 || curr[ele]+wait<=tme)
            {
                curr[ele]=tme;
                tme++;
                //cout<<ele<<" "<<curr[ele]<<endl;
            }
            else
            {
                //cout<<"qe";
                int diff=curr[ele]+wait-tme;
                tme+=diff;
                curr[ele]=tme;
                tme++;
            }
            //cout<<tme<<endl;
        }
        return tme-1;
    }
};
