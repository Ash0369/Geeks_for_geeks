struct Node
{
    int key,val,cnt;
    Node *next;
    Node *prev;
    Node(int _key,int _val)
    {
        key=_key;
        val=_val;
        cnt=1;
    }
};

struct List
{
    int size;
    Node *head;
    Node *tail;
    
    List()
    {
        head= new Node(0,0);
        tail=new Node(0,0);
        tail->prev=head;
        head->next=tail;
        size=0;
    }
    
    void addfront(Node *node)
    {
        Node *temp=head->next;
        
        temp->prev=node;
        node->prev=head;
        
        node->next=temp;
        head->next=node;
        size++;
    }
    
    void remove(Node *node)
    {
        Node *temp=node->next;
        
        node->prev->next=temp;
        temp->prev=node->prev;
        
        size--;
    }
};

class LFUCache 
{
public:
    
    int curr_size=0;
    int min_frequency=0;
    int max_size=0;
    map<int,Node*>keynode;
    map<int,List*>fre;
    
    LFUCache(int capacity) 
    {
        max_size=capacity;
    }
    void update_fre(Node *node)
    {
        keynode.erase(node->key);
        fre[node->cnt]->remove(node);
        
        if(node->cnt==min_frequency && fre[node->cnt]->size==0)
        {
            min_frequency++;
        }
        
        List *higher=new List();
        
        if(fre.find(node->cnt+1)!=fre.end())
        {
            higher=fre[node->cnt+1];
        }
        node->cnt=node->cnt+1;
        
        higher->addfront(node);
        
        fre[node->cnt]=higher;
        keynode[node->key]=node;
    }
    int get(int key) 
    {
        if(keynode.find(key)==keynode.end())
        {
            return -1;
        }
        Node *node=keynode[key];
        int val=node->val;
        update_fre(node);
        return val;
    }
    
    void put(int key, int value) 
    {
        if(max_size==0)
        {
            return;
        }
        if(keynode.find(key)!=keynode.end())
        {
            Node *node=keynode[key];
            node->val=value;
            update_fre(node);
            return;
        }
        
        if(curr_size==max_size)
        {
            List *list=fre[min_frequency];
            keynode.erase(list->tail->prev->key);
            
            fre[min_frequency]->remove(list->tail->prev);
            
            curr_size--;
        }
        
        curr_size++;
        
        min_frequency=1;//New value will be added
        List *lst=new List();
        if(fre.find(min_frequency)!=fre.end())
        {
            lst=fre[min_frequency];
        }
        
        Node *node=new Node(key,value);
        lst->addfront(node);
        keynode[key]=node;
        fre[min_frequency]=lst;
        
    }
};
