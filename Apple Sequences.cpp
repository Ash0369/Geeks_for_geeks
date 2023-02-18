class Solution
{   
public:
    int appleSequences(int n, int m, string arr)
    {
        int orange=0;
        int apple=0;
        int left=0;
        int ans=0;
        for(int right=0;right<n;right++)
        {
            if(arr[right]=='A')
            {
                apple++;
            }
            else
            {
                orange++;
            }
            int replacement=orange;
            while(replacement>m)
            {
                if(arr[left]=='A')
                {
                    apple--;
                }
                else
                {
                    orange--;
                }
                left++;
                replacement=orange;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
