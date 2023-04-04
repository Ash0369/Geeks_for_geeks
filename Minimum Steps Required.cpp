int minSteps(string s) 
{
    int n=s.size();
    int a=0;
    int b=0;
    for(int i=0;i<n;i++)
    {
        char c=s[i];
        if(c=='a')
        {
            i++;
            while(i<n && s[i]=='a')
            {
                i++;
            }
            i--;
            a++;
        }
        else if(c=='b')
        {
            i++;
            while(i<n && s[i]=='b')
            {
                i++;
            }
            i--;
            b++;
        }
    }
    
    return min(a,b)+(max(a,b)>0);
}
