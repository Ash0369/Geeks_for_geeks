#define pii pair<int,int>
bool cmp(pair<int,int>vec1,pair<int,int>vec2)
{
    if(vec1.first<vec2.first)
    {
        return true;
    }
    if(vec1.first==vec2.first)
    {
        if(vec1.second<vec2.second)
           return true;
    }
    return false;
}
class Solution 
{
  public:
    int minLaptops(int N, int start[], int end[]) 
    {
        
        int n=N;
        
        vector<pii>st;
        for(int i=0;i<n;i++)
        {
            st.push_back({start[i],end[i]});
        }
        
        sort(st.begin(),st.end(),cmp);
        priority_queue<int,vector<int>,greater<int>>pq;
      
        int laptop=0;
        int tme=0;
        
        for(int i=0;i<n;i++)
        {
            //cout<<st[i].first<<" "<<st[i].second<<endl;
            if(pq.empty())
            {
                laptop++;
                pq.push(st[i].second);
            }
            else if(pq.top()<=st[i].first)
            {
                pq.pop();
                pq.push(st[i].second);
            }
            else
            {
                laptop++;
                pq.push(st[i].second);
            }
        }
        
        return laptop;
    }
};
