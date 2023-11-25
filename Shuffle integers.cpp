class Solution{
	
	
	
	public:
	void shuffleArray(int arr[],int n)
	{
	   for(int i=0;i<n;i++)
	   {
	       arr[i]=arr[i]*10000;
	       
	   }
	   int p=1;
	   for(int i=n/2;i<n;i++)
	   {
	       arr[p]+=arr[i]/10000;
	       p=p+2;
	   }
	   p=0;
	   for(int i=0;i<n/2;i++)
	   {
	       arr[p]+=arr[i]/10000;
	       p=p+2;
	   }
	   
	   for(int i=0;i<n;i++)
	   {
	       arr[i]=arr[i]%10000;
	   }
	    
	}
		 

};
