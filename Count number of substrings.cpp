#define ll long long

ll int solve(string &s,int k)
{
    int n=s.size();
    ll int ans=0;
    int left=0;
    int right=0;
    int diff=0;
    vector<int>mp(28,0);
    while(right<n)
    {
        mp[s[right]-'a']++;
        if(mp[s[right]-'a']==1)
        {
            diff++;
        }
        while(diff>k)
        {
            mp[s[left]-'a']--;
            if(mp[s[left]-'a']==0)
            {
                diff--;
            }
            left++;
        }
        ans+=right-left+1;
        right++;
    }
    return ans;
}
class Solution
{
  public:
    long long int substrCount (string s, int k) 
    {
        return solve(s,k)-solve(s,k-1);
    }
};
