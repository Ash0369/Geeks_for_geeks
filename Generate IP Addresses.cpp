bool isvalid(string s)
{
    if(s.length()>1 && s[0]=='0')
    {
        return false;
    }
    if(s.length()>3)
    {
        return false;
    }
    if(stoi(s)<=255)
    {
        return true;
    }
    return false;
}
void ip_adress(string s,vector<string>&res,string curr,int index,int dot)
{
    if(dot==3)
    {
        curr=curr+s.substr(index,s.length()-index);
        if(isvalid(s.substr(index,s.length()-index)))
        {
            res.push_back(curr);
        }
    }
    if((index+1)<=s.length()-1)
    {
        ip_adress(s,res,curr+s[index]+'.',index+1,dot+1);
    }
    if((index+2)<=s.length()-1 && isvalid(s.substr(index,2)))
    {
        ip_adress(s,res,curr+s.substr(index,2)+'.',index+2,dot+1);
    }
    
    if((index+3)<=s.length()-1 && isvalid(s.substr(index,3)))
    {
        ip_adress(s,res,curr+s.substr(index,3)+'.',index+3,dot+1);
    }
   
    
    
}
class Solution 
{
public:
    vector<string> genIp(string &s) 
    {
        vector<string>res;
        ip_adress(s,res,"",0,0);
        return res;
    }
};
