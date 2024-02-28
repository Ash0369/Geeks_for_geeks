class Solution
{
  public:
        string smallestNumber(string num)
        { 
            map<int,int>mp;
            for(auto x:num)
            {
                mp[x-'0']++;
            }
            for(int i=0;i<num.size();i++)
            {
                
            
                mp[num[i]-'0']--;
                
                
                int val=num[i]-'0';
                
                int j=0;
                
                while(j<val)
                {
                    if(j==0 && i==0)
                    {
                        j++;
                        continue;
                    }
                    if(mp[j]==0)
                    {
                        j++;
                        continue;
                    }
                    
                
                num[i]=j+'0';
                int n=num.size();
                        int k=n-1;
                        while(num[k]!=(j+'0'))
                        {
                            k--;
                        }
                        num[k]=val+'0';
                        return num;
                    
                }
            }
            return num;
        } 
 
};
