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
 
class Solution 
{
  public:
    bool isAdditiveSequence(string s) 
    {
        int n=s.size();
        string a="";
        for(int i=0;i<n/2;i++)
        {
            a.push_back(s[i]);
            
            string b="";
            
            for(int j=i+1;j<n;j++)
            {
                b.push_back(s[j]);
                
                if(a.size()>0 && b.size()>0)
                {
                    string b1=b;
                    string c=add(a,b);
                    string d="";
                    if(a=="1" && b=="47")
                    {
                      // cout<<a<<" "<<b<<" "<<c<<endl;
                    }
                    for(int k=j+1;k<n;k++)
                    {
                        d.push_back(s[k]);
                        if(d==c)
                        {
                            c=add(b1,d);
                            b1=d;
                            d.clear();
                            if(k==n-1)
                            {
                               // cout<<i<<" "<<j<<endl;
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};
