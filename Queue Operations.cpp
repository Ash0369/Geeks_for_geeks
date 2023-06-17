class Solution{
    public:
    // Function to insert element into the queue
    map<int,int>mp;
    void insert(queue<int> &q, int k)
    {
        q.push(k);
        mp[k]++;
        // Your code here
    }
    
    // Function to find frequency of an element
    // return the frequency of k
    int findFrequency(queue<int> &q, int k){
        // Your code here
        return mp[k];
    }
    
};
