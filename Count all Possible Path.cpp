class Solution 
{
public:
	int isPossible(vector<vector<int>>paths)
	{
	    int n=paths.size();
	    for(int i=0;i<n;i++)
	    {
	        int cnt=0;
	        for(int j=0;j<n;j++)
	        {
	            cnt+=paths[i][j];
	        }
	        if(cnt%2!=0)
	        {
	            return 0;
	        }
	    }
	    return 1;
	}

};
