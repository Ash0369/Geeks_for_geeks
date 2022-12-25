#define ll long long
class Solution 
{
  public:
  //Atmost x elements -atmost x-1 elements is equal to exact x elements.
    long long goodSubarrays(int n,int x, vector<int>arr) 
    {
        // Atmost x
        map<int,int>mp;
        int left=0;
        int right=0;
        int gold=0;
        ll int cnt=0;
        for(int right=0;right<n;right++)
        {
            mp[arr[right]]++;
            if(mp[arr[right]]==3)
            {
                gold++;
            }
            if(gold>x)
            {
                while(gold>x)
                {
                    mp[arr[left]]--;
                    if(mp[arr[left]]==2)
                    {
                        gold--;
                    }
                    left++;
                }
            }
           
            cnt+=right-left+1;
            
        }
        
        
        //Atmost x-1
        x--;
        mp.clear();
        left=0;
        right=0;
        gold=0;
        ll int cnt2=0;
        for(int right=0;right<n;right++)
        {
            mp[arr[right]]++;
            if(mp[arr[right]]==3)
            {
                gold++;
            }
            if(gold>x)
            {
                while(gold>x)
                {
                    mp[arr[left]]--;
                    if(mp[arr[left]]==2)
                    {
                        gold--;
                    }
                    left++;
                }
            }
            cnt2+=right-left+1;
            
        }
        return cnt-cnt2;
    }
};
