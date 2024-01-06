class Solution {
public:
	int sumOfPowers(int a, int b)
	{
	    int ans=0;
	    for(int i=a;i<=b;i++)
	    {
	        int ele=i;
	        for(int j=2;j*j<=ele;j++)
	        {
	            if(ele%j==0)
	            {
	                while(ele%j==0)
	                {
	                    ele=ele/j;
	                    ans++;
	                }
	            }
	        }
	        if(ele>1)
	        {
	            ans++;
	        }
	    }
	    return ans;
	}
};
