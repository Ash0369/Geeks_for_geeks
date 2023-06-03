#define ll long long
class Solution
{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3)
    {
        stack<int>a;
        stack<int>b;
        stack<int>c;
        
        ll int s1=0;
        ll int s2=0;
        ll int s3=0;
        
        for(int i=N1-1;i>=0;i--)
        {
            int x=S1[i];
            a.push(x);
            s1=s1+x;
        }
        for(int i=N2-1;i>=0;i--)
        {
            int x=S2[i];
            b.push(x);
            s2=s2+x;
        }
        for(int i=N3-1;i>=0;i--)
        {
            int x=S3[i];
            c.push(x);
            s3=s3+x;
        }
        
        
        while(s1!=s2 || s2!=s3 || s1!=s3)
        {
            while((s1>s2 || s1>s3) && a.size()>0)
            {
                s1=s1-a.top();
                a.pop();
            }
            while((s2>s1 || s2>s3) && b.size()>0)
            {
                s2=s2-b.top();
                b.pop();
            }
            while((s3>s1 || s3>s2) && c.size()>0)
            {
                s3=s3-c.top();
                c.pop();
            }
        }
        
        return s1;
    }
};
