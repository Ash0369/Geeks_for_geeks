class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            d=d%16;
            int m=(1<<16)-1;
            return {((n<<d)|((n>>(16-d))))&m,((n>>d)|((n<<(16-d))))&m};
        }
};
