#define ll long long
class Solution 
{
public:
    long long int MissingNo(vector<vector<int> >& matrix) 
    {
        map<ll int,ll int>st;
        ll int n=matrix.size();
        ll int zx,zy;
        for(int i=0;i<n;i++)
        {
            ll int a=0;
            for(int j=0;j<n;j++)
            {
                a=a+1LL*matrix[i][j];
                if(matrix[i][j]==0)
                {
                    zx=i;
                    zy=j;
                }
            }
            ll int b=0;
            for(int j=0;j<n;j++)
            {
                b=b+1LL*matrix[j][i];
            }
            
            st[a]++;
            st[b]++;
        }
        ll int d=-1;
        if(st.size()>2 || st.size()==1)
        {
            return -1;
        }
        ll int ele,ele2;
        for(auto x:st)
        {
            if(x.second==2)
            {
                ele=x.first;
            }
            else
            {
                ele2=x.first;
            }
        }
        if(n==2)
        {
            ele=st.begin()->first;
            st.erase(st.begin());
            ele2=st.begin()->first;
        }
        else if(ele>ele2)
        {
            return -1;
        }
        d=abs(ele2-ele);
        ll int sum=0;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==0)
            {
                sum+=d;
            }
            else
              sum+=1LL*matrix[i][0];
        }
        ll int a=0;
        ll int b=0;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][i]==0)
            {
                a=a+d;
            }
            else
            {
                a=a+1LL*matrix[i][i];
            }
            if(matrix[i][n-1-i]==0)
            {
                b=b+d;
            }
            else
            {
                b=b+1LL*matrix[i][n-1-i];
            }
        }
        if(a!=sum || b!=sum)
        {
            return -1;
        }
        return d;
    }
};
