class Solution 
{
  public:
	void shortest_distance(vector<vector<int>>&matrix)
	{
	    #define ll long long 
	    int n=matrix.size();
	    
	    for(int i=0;i<n;i++)
	    {
	        //We will go via i --> via 0,1,..
	        for(int row=0;row<n;row++)
	        {
	            for(int col=0;col<n;col++)
	            {
	                //how to arrive from row--> col , row->i->col
	                
	                ll int costa=matrix[row][i];
	                ll int costb=matrix[i][col];
	                if(matrix[row][i]==-1)
	                {
	                    continue;
	                }
	                if(matrix[i][col]==-1)
	                {
	                    continue;
	                }
	                ll int cost=costa+costb;
	                
	                if(cost<matrix[row][col] || matrix[row][col]==-1)
	                {
	                    matrix[row][col]=cost;
	                }
	            }
	        }
	    }
	}
};
