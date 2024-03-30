class Solution {
public:   
    int minValue(Node* root) {
        if(root->left)
        {
            return minValue(root->left);
        }
        return root->data;
    }
};
