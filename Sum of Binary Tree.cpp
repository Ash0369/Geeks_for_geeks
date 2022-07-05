long long int sum=0;
void calc_sum(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    sum=sum+root->key;
    calc_sum(root->left);
    calc_sum(root->right);
}
long int sumBT(Node* root)
{
    sum=0;
    calc_sum(root);
    return sum;
}
