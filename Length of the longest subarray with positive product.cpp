class Solution 
{
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n)
        {
            int left=0;
            int ans=0;
            int positive=0;
            int negative=0;
            int pos1=-1;
            int pos2=-1;
            
            
            for(int right=0;right<n;right++)
            {
                if(arr[right]>0)
                {
                    positive++;
                    if(negative%2==0)
                    {
                        ans=max(ans,right-left+1);
                    }
                    else
                    {
                         ans=max(ans,right-pos1+1);
                    }
                }
                else if(arr[right]<0)
                {
                    negative++;
                    if(negative==1)
                    {
                        pos1=right+1;
                        continue;
                    }
                    
                    if(negative%2==0)
                    {
                        ans=max(ans,right-left+1);
                    }
                    else
                    {
                        ans=max(ans,right-pos1+1);
                    }
                    
                }
                else
                {
                    positive=0;
                    negative=0;
                    pos1=-1;
                    pos2=-1;
                    left=right+1;
                    continue;
                }
            }
            return ans;
        }
};
