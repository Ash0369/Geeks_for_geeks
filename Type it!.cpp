int type(string &curr,string &s,bool available)
{
    if(curr==s)
    {
        return 0;
    }
    int ind=curr.size();
    if(ind>=s.size())
    {
        return 1e5;
    }
    
    curr.push_back(s[ind]);
    
    int op1=1+type(curr,s,available);
    int op2=1e5;
    curr.pop_back();
    if(ind>0 && available==true)
    {
        string t=curr+curr;
        op2=1+type(t,s,false);
    }
    return min(op1,op2);
    
}
class Solution 
{
  public:
    int minOperation(string s) 
    {
        string t="";
        return type(t,s,true);
    }
};
