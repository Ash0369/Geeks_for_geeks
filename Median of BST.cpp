void push_left(struct Node *root,stack<Node*>&q1)
{
    if(root==NULL)
    {
        return;
    }
    q1.push(root);
    push_left(root->left,q1);
}
void push_right(struct Node *root,stack<Node*>&q1)
{
    if(root==NULL)
    {
        return;
    }
    q1.push(root);
    push_right(root->right,q1);
}
float findMedian(struct Node *root)
{
      stack<Node*>q1;
      stack<Node*>q2;
      
      push_left(root,q1);
      push_right(root,q2);
      
      int l=root->data;
      int r=root->data;
      
      while(!q1.empty() && !q2.empty())
      {
          l=q1.top()->data;
          r=q2.top()->data;
          
          if(l==r)
          {
              return (l+r)/2.0;
          }
          if(l>r)
          {
              break;
          }
          
          auto node1=q1.top();
          q1.pop();
          
          if(node1->right)
          {
              push_left(node1->right,q1);
          }
          
          auto node2=q2.top();
          q2.pop();
          
          if(node2->left)
          {
              push_right(node2->left,q2);
          }
      }
      
      return (l+r)/2.0;
      
}
