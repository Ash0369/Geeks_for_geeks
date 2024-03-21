class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int>ans;
    	queue<Node*>q;
    	
    	q.push(root);
    	int iter=0;
    	while(!q.empty())
    	{
    	    int sz=q.size();
    	    vector<int>v;
    	    while(sz--)
    	    {
    	        auto node=q.front();
    	        q.pop();
    	        v.push_back(node->data);
    	        
    	        if(node->left)
    	        {
    	            q.push(node->left);
    	        }
    	        if(node->right)
    	        {
    	            q.push(node->right);
    	        }
    	    }
    	    
    	    if(iter%2==1)
    	    {
    	        reverse(v.begin(),v.end());
    	    }
    	    iter++;
    	    for(auto x:v)
    	    {
    	        ans.push_back(x);
    	    }
    	}
    	return ans;
    }
};
