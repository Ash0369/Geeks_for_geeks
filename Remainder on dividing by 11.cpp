int find(string &x,int index,int prev)
{
    if(index>=x.size())
    {
        return prev;
    }
    if(prev==0)
    {
        if(x.size()==1)
        {
            return stoi(x);
        }
        int num=stoi(x.substr(index,2));
        int r=num%11;
        return find(x,index+2,r);
    }
    int num=(prev*10)+(x[index]-'0');
    return find(x,index+1,num%11);
}
class Solution
{

public:
    int xmod11(string x)
    {
       return find(x,0,0);
    }
};
