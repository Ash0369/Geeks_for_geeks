#define ll long long
class Solution
{   
public:
    long long solve(int X,int Y,string S)
    {
      int x1=X;
      int y=Y;
      
      char first;
      char second;
      if(x1>y)
      {
          first='p';
          second='r';
      }
      else
      {
          first='r';
          second='p';
          swap(x1,y);
      }
      ll int ans=0;
      stack<char>st;
      for(auto x:S)
      {
          if(st.empty())
          {
              st.push(x);
              continue;
          }
          if(st.top()==first && second==x)
          {
              st.pop();
              ans+=x1;
          }
          else
          {
              st.push(x);
          }
      }
      stack<char>store;
      while(st.size()>0)
      {
          if(store.size()>0 && st.top()==second && store.top()==first)
          {
              ans+=y;
              st.pop();
              store.pop();
          }
          else if(st.top()==first && st.size()>1)
          {
              store.push(st.top());
              st.pop();
              if(st.top()==second)
              {
                  st.pop();
                  store.pop();
                  ans+=y;
              }
          }
          else
          {
              store.push(st.top());
              st.pop();
          }
      }
    
      return ans;
    }
};
