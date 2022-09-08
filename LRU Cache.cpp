struct Node 
{
  int key;
  int value;
  struct Node *next;
  struct Node *prev;
  Node(int x,int y) 
  {
    key= x;
    value=y;
    next = NULL;
    prev=NULL;
  }
};
class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    int max_size;
    int size=0;
    map<int,Node*>mp;
    Node *dummy_head=new Node(-1,-1);
    Node *dummy_tail=new Node(-1,-1);
    
    LRUCache(int cap)
    {
        max_size=cap;
        dummy_head->next=dummy_tail;
        dummy_tail->prev=dummy_head;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(mp.find(key)!=mp.end())
        {
            int a=mp[key]->value;
            mp[key]->prev->next=mp[key]->next;
            mp[key]->next->prev=mp[key]->prev;
            
            Node *temp=dummy_head->next;
            dummy_head->next=mp[key];
            mp[key]->prev=dummy_head;
            
            mp[key]->next=temp;
            temp->prev=mp[key];
            
            return a;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
         
        if(mp.find(key)!=mp.end())
        {
            mp[key]->value=value;
            // mp[key].first->data=value;
            
            mp[key]->next->prev=mp[key]->prev;
            mp[key]->prev->next=mp[key]->next;
            Node *temp=dummy_head->next;
            
            dummy_head->next=mp[key];
            mp[key]->prev=dummy_head;
            
            mp[key]->next=temp;
            temp->prev=mp[key];
            
            return;
        }
        else
        {
             Node *temp=dummy_head->next;
             Node *n=new Node(key,value);
             dummy_head->next=n;
             n->prev=dummy_head;
             
             n->next=temp;
             temp->prev=n;
             
             mp[key]=n;
        }
        
        if(size<max_size)
        {
            size++;
        }
        else
        {
            int data=dummy_tail->prev->key;
            mp.erase(data);
            dummy_tail->prev=dummy_tail->prev->prev;
            dummy_tail->prev->next=dummy_tail;
            
        }
         
    }
};
