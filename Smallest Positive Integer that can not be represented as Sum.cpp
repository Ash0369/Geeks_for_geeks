class Solution
{   
public:
    long long smallestpositive(vector<long long> array, int n)
    { 
        #define ll long long
        sort(array.begin(),array.end());
        ll int psum=0;
        for(int i=0;i<n;i++)
        {
            if(array[i]>(psum+1))
            {
                return psum+1;
            }
            psum+=array[i];
        }
        return psum+1;
    } 
};
