#include<string>
string add(string str1, string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
bool check(string &c,string &z)
{
    for(int i=0;i<z.size();i++)
    {
        if(c[i]!=z[i])
        {
            return false;
        }
    }
    return true;
}
bool dfs(string a,string b,string c)
{
    //cout<<a<<" "<<b<<" "<<c<<endl;
    if(c.size()==0)
    {
        return false;
    }
    string z=add(a,b);
    int sz=z.size();
    if(sz>(c.size()))
    {
        return false;
    }
    if(check(c,z)==1)
    {
        if(c==z)
        {
            return true;
        }
        string d=c.substr(sz);
        return dfs(b,z,d);
    }
    return false;
}
class Solution{   
public:
    int isSumString(string s)
    {
        int n=s.size();
        //dfs(s.substr(0,2),s.substr(2,2),s.substr(4));
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                if(dfs(s.substr(0,i),s.substr(i,j-i),s.substr(j)))
                {
                    return true;
                }
            }
        }
        return false;
        
    }
};
