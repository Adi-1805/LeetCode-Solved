class Node{
public:
    int key, val;
    Node *next, *prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
    Node *LRU = new Node(-1, -1), *MRU = new Node(-1, -1); // DLL Structure: MRU <=> head <=> ... <=> LRU 
    unordered_map<int, Node*> mp; // {key: Node} and each Node containe {key, value}
    int cap = 0;
public:
    LRUCache(int capacity) {
        cap = capacity; MRU->next = LRU; LRU->prev = MRU; 
    }

    void removeNode(Node* &node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertAtHead(Node* &node){
        node -> next = MRU -> next; 
        node -> prev = MRU;
        MRU -> next -> prev = node;
        MRU -> next = node;
    }
    
    int get(int key) {
       if (mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        removeNode(node);
        insertAtHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->val = value;
            removeNode(node);
            insertAtHead(node);
            return ;
        }
        if(mp.size() == cap){
            Node* temp = LRU->prev;
            removeNode(temp);
            mp.erase(temp->key);
        }
        Node* newNode = new Node(key, value);
        insertAtHead(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be indqantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */