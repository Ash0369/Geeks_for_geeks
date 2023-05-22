class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int cnt=0;
        int ele=0;
        for(int i=0;i<size;i++)
        {
            if(cnt==0)
            {
                cnt=1;
                ele=a[i];
                continue;
            }
            if(a[i]==ele)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        cnt=0;
        for(int i=0;i<size;i++)
        {
            if(a[i]==ele)
            {
                cnt++;
            }
        }
        if(cnt>((size/2)))
        {
            return ele;
        }
        return -1;
    }
};
