class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        map<string,int>mp;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        vector<string>ans;
        int z=0;
        string p="";
        for(auto x:mp)
        {
            if(x.second>z)
            {
                p=x.first;
                z=x.second;
            }
        }
        ans.push_back(p);
        ans.push_back(to_string(z));
        return ans;
    }
};
