class Solution
{
    public:
    int minNumber(int arr[],int N)
    {
        int a=0;
        for(int i=0;i<N;i++)
        {
            a=a+arr[i];
        }
        int z=a;
        while(true)
        {
            bool r=false;
            for(int i=2;i*i<=z;i++)
            {
                if(z%i==0)
                {
                    r=true;
                    break;
                }
            }
            if(r==false)
            {
                return z-a;
            }
            z++;
        }
        return -1;
    }
};
