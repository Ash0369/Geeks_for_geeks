class Solution{
public:
    int isLeap(int N){
        if(N%4==0 )
        {
            if(N%100==0)
            {
                if(N%400==0)
                {
                    return 1;
                }
                return 0;
            }
            return 1;
        }
        else{
            return 0;
        }
    }
};
