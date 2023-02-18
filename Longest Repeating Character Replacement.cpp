int mx(map<char,int>&mp)
{
    int ans=0;
    for(auto x:mp)
    {
        ans=max(ans,x.second);
    }
    return ans;
}
class Solution 
{
public:
    int characterReplacement(string s,int k) 
    {
        map<char,int>mp;
        int maxf=0;
        int left=0;
        int ans=0;
        for(int right=0;right<s.size();right++)
        {
            mp[s[right]]++;
            maxf=mx(mp);
            int replacement=right-left+1-maxf;
            while(replacement>k)
            {
                mp[s[left]]--;
                left++;
                maxf=mx(mp);
                replacement=right-left+1-maxf;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
