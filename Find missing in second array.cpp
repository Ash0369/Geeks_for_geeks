class Solution{
	
	
	public:
	vector<long long> findMissing(long long A[], long long B[],  
                 int N, int M) 
	{ 
	    #define ll long long
	    
	    map<int,int>mp;
	    
	    for(int i=0;i<M;i++)
	    {
	        mp[B[i]]=1;
	    }
	    vector<ll int>vec;
	    for(int i=0;i<N;i++)
	    {
	        if(mp[A[i]]==0)
	        {
	            vec.push_back(A[i]);
	        }
	    }
	    return vec;
	} 
};
