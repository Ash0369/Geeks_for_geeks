class Solution{
public:
	vector<int> generateNextPalindrome(int vec[], int n) 
	{
	    if(n==1)
	    {
	        if(vec[0]!=9) return {vec[0]+1};
	        
	        return {1,1};
	    }
	    bool check=false;
	    //1 5 3 4 6 7 1 7 4 2 7 3 5 4 7 2 6
	    //1 5 3 4 6 7 1       1 7 6 4 3 5 1
	    int left=0;
	    int right=n-1;
	    int carry=0;
	    while(right-left>2)
	    {
	        if(vec[left]==vec[right])
	        {
	            
	        }
	        else
	        {
	            if(vec[right]>vec[left])
	            {
	                check=true;
	                vec[right]=vec[left];
	                carry=1;
	            }
	            else
	            {
	                check=true;
	                vec[right]=vec[left];
	                carry=0;
	            }
	        }
	        left++;
	        right--;
	    }
	   // cout<<carry<<endl;
	    if(carry>0)
	    {
	        //cout<<vec[left]<<" "<<vec[left+1]<<" "<<vec[right]<<endl;
	        if(right-left==1)
	        {
	            if(vec[left]>vec[right])
	            {
	                vec[right]=vec[left];
	            }
	            else
	            {
	                vec[left]++;
	                vec[right]=vec[left];
	               while(left>=0 && vec[left]==10)
	               {
	                        vec[left]=0;
	                        if(left-1>=0) vec[left-1]++;
	                        left--;
	                        vec[right]=0;
	                        if(right+1<n) vec[right+1]++;
	                        right++;
	               }
	            }
	        }
	        else
	        {
	            if(vec[right]<vec[left])
	            {
	                vec[right]=vec[left];
	            }
	            else
	            {
	                vec[right]=vec[left];
	                vec[left+1]++;
	                if(vec[left+1]==10)
	                {
	                    vec[left+1]=0;
	                    vec[left]++;
	                    vec[right]=vec[left];
	                    while(left>=0 && vec[left]==10)
	                    {
	                        vec[left]=0;
	                        if(left-1>=0) vec[left-1]++;
	                        left--;
	                        vec[right]=0;
	                        if(right+1<n) vec[right+1]++;
	                        right++;
	                    }
	                }
	                
	            }
	        }
	    }
	    else
	    {
	        //cout<<vec[left]<<" "<<vec[right]<<endl;
	        if(vec[left]==vec[right])
	        {
	            
	        }
	        else if(vec[right]<vec[left])
	        {
	             check=true;
	             vec[right]=vec[left];
	        }
	        else
	        {
	            check=true;
	            if(right-left==1)
	            {
	                vec[left]++;
	                vec[right]=vec[left];
	               
	            }
	            else
	            {
	                if(vec[left+1]!=9)
	                {
	                    vec[left+1]++;
	                    vec[right]=vec[left];
	                }
	                else
	                {
	                    vec[left]++;
	                    vec[right]=vec[left];
	                    vec[left+1]=0;
	                }
	            }
	        }
	       
	    }
	    if(check==false)
	    {
	        if(n%2!=0)
	        {
	            vec[n/2]++;
	            if(vec[n/2]==10)
	            {
	                int left=(n/2)-1;
	                int right=(n/2)+1;
	                vec[left]++;
	                vec[right]++;
	                vec[n/2]=0;
	                while(left>=0 && vec[left]==10)
	                {
	                    vec[left]=0;
	                    if(left-1>=0) vec[left-1]++;
	                    left--;
	                    vec[right]=0;
	                    if(right+1<n) vec[right+1]++;
	                    right++;
	                }
	            }
	        }
	        else
	        {
	            
	                int left=(n/2)-1;
	                int right=(n/2);
	                vec[left]++;
	                vec[right]++;
	                while(left>=0 && vec[left]==10)
	                {
	                    vec[left]=0;
	                    if(left-1>=0) vec[left-1]++;
	                    left--;
	                    vec[right]=0;
	                    if(right+1<n) vec[right+1]++;
	                    right++;
	                }
	            
	        }
	    }
	    vector<int>ans;
	    if(vec[0]==0)
	    {
	        ans.push_back(1);
	        n--;
	        while(n>0)
	        {
	            ans.push_back(0);
	            n--;
	        }
	        ans.push_back(1);
	        return ans;
	    }
	    for(int i=0;i<n;i++)
	    {
	        ans.push_back(vec[i]);
	    }
	    if(vec[n-1]==0)
	    {
	        ans.push_back(1);
	    }
	    return ans;
	}

};
