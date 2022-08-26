class Solution{
public:

	void rearrange(int arr[], int n) 
	{
	    queue<int>p;
	    queue<int>neg;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0)
	        {
	            p.push(arr[i]);
	        }
	        else
	        {
	            neg.push(arr[i]);
	        }
	    }
	    int i=0;
	    while(!p.empty() && !neg.empty())
	    {
	        arr[i]=p.front();
	        p.pop();
	        i++;
	        arr[i]=neg.front();
	        neg.pop();
	        i++;
	    }
	    while(!p.empty())
	    {
	        arr[i]=p.front();
	        p.pop();
	        i++;
	    }
	    while(!neg.empty())
	    {
	        arr[i]=neg.front();
	        neg.pop();
	        i++;
	    }
	}
};
