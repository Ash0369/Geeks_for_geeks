class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        //Level order traversal in vertical is method.
        deque<Node*>data;
        deque<int>pos;
        data.push_back(root);
        pos.push_back(0);

        map<int,Node*>mp;
        while(!data.empty())
        {
            Node* front=data.front();
            if(mp.find(pos.front())==mp.end())
            {
                mp[pos.front()]=front;
            }
            if(front->left)
            {
                data.push_back(front->left);
                pos.push_back(pos.front()-1);
            }
            if(front->right)
            {
                data.push_back(front->right);
                pos.push_back(pos.front()+1);
            }
            data.pop_front();
            pos.pop_front();
        }
        vector<int>result;
        for(auto x:mp)
        {
            result.push_back(x.second->data);
        }
        return result;
    }

};
