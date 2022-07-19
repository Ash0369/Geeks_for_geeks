//For integers

int find_max(int arr[],int n)
{
    int temp=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>temp)
        {
            temp=arr[i];
        }
    }
    return temp;
}
void count_sort(int arr[],int n)
{
    int maximum=find_max(arr,n);
    int *c;
    c=new int[maximum+1];
    for(int i=0;i<=maximum;i++)
    {
        c[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        c[arr[i]]++;
    }
    int j=0;
    for(int i=0;i<=maximum;i++)
    {
        if(c[i]!=0)
        {
            arr[j]=i;
            j++;
            c[i]--;
            i--;
        }
    }

}

//For strings

class Solution
{
    public:
    string countSort(string arr)
    {
        int temp[26];
        for(int i=0;i<26;i++)
        {
            temp[i]=0;
        }
        for(int i=0;i<arr.size();i++)
        {
            int a=int(arr[i])-97;
            temp[a]++;
        }
        int j=0;
        for(int i=0;i<26;i++)
        {
            if(temp[i]!=0)
            {
                arr[j]=char(i+97);
                temp[i]--;
                i--;
                j++;
            }
        }
        return arr;
    }
};
