//Method-1 : 

class Solution
{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) 
    {
        map<ll int,int>mp;
        for(auto x:A)
        {
            mp[x]=mp[x]+1;
        }
        for(auto x:B)
        {
            mp[x]=mp[x]-1;
        }
        
        for(auto x:mp)
        {
            if(x.second!=0)
            {
                return false;
            }
        }
        return true;
    }
};

//Method-2 : 

class Solution
{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) 
    {
       sort(A.begin(),A.end());
       sort(B.begin(),B.end());
       if(A==B)
       {
           return true;
       }
       return false;
    }
};
