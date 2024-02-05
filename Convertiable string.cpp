class Solution {
  public:
    vector<int> CompatibleStrings(int n, vector<string> &a1, vector<string> &a2) 
    {
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++)
        {
            string s1=a1[i];
            string s2=a2[i];
            
            if(s1.size()!=s2.size())
            {
                continue;
            }
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            
            vector<int>sz1(26,0);
            vector<int>sz2(26,0);
            
            for(auto x:s1)
            {
                sz1[x-'a']++;
            }
            for(auto x:s2)
            {
                sz2[x-'a']++;
            }
            int k=-1;
            bool res=true;
            for(int i=0;i<26;i++)
            {
                if(sz1[i]!=sz2[i])
                {
                    if(k==-1)
                    {
                        k=abs(sz1[i]-sz2[i]);
                    }
                    else{
                        k=__gcd(k,abs(sz1[i]-sz2[i]));
                    }
                }
            }
            if(k==1)
            {
                continue;
            }
            if(k==-1)
            {
                ans[i]=1;
                continue;
            }
            int c=0;
            for(int i=0;i<26;i++)
            {
                if(sz1[i]==sz2[i])
                {
                    continue;
                }
                if(sz1[i]>sz2[i])
                {
                    c+=abs(sz1[i]-sz2[i])/k;
                }
                else
                {
                    int need=abs(sz1[i]-sz2[i])/k;
                    if(c<need)
                    {
                        res=false;
                        break;
                    }
                    c=c-need;
                }
                
            }
            if(res==true && c==0)
            {
                ans[i]=1;
            }
        }
        return ans;
    }
};
