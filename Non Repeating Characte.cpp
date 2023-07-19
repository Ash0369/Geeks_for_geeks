class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       map<char,int>mp;
       
       for(auto x:S)
       {
           mp[x]++;
       }
       for(auto x:S)
       {
           if(mp[x]==1)
           {
               return x;
           }
       }
       char c='$';
       return c;
       
    }

};
