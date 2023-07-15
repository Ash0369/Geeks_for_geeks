class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int ele;
        if(sizeOfStack%2==0)
        {
            ele=(sizeOfStack/2);
        }
        else
        {
            ele=(sizeOfStack/2);
        }
        stack<int>temp;
        while(ele--)
        {
            temp.push(s.top());
            s.pop();
        }
        s.pop();
        while(!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }
    }
};
