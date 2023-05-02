class Solution
{
public:
    bool makePalindrome(int n,vector<string> &arr)
    {
        map<string,int>mp;
        for(auto x:arr)
        {
            mp[x]++;
        }
        for(int i=0;i<n;i++)
        {
            string temp=arr[i];
            reverse(temp.begin(),temp.end());
            if(mp[arr[i]]>0 && mp[temp]<=0)
            {
                return false;
            }
            mp[arr[i]]--;
            mp[temp]--;
        }
        return true;
    }
};
