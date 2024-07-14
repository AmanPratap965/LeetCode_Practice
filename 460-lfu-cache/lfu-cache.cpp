    class Node{
        public:
        int key;
        int val;
        int cnt;
        Node*next;
        Node*prev;
        Node(int k,int v){
                key=k;
                val=v;
                cnt=1;
        }
    };
    struct List{
        public:
        int size;
        Node*head;
        Node*tail;
        List(){
            head=new Node(0,0);
            tail=new Node(0,0);
            head->next=tail;
            tail->prev=head;
            size=0;
        }
        void addNode(Node *newNode){
        Node*temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        temp->prev=newNode;
        head->next=newNode;
        size++;
    }
    void deleteNode(Node* delNode){
        Node*x=delNode->prev;
        Node*y=delNode->next;
        x->next=y;
        y->prev=x;
        size--;
    }
    };
class LFUCache {
public:

    unordered_map<int,Node*>keyNode;
    unordered_map<int,List*>freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;
    LFUCache(int capacity) {
        minFreq=0;
        curSize=0;
        maxSizeCache=capacity;
    }
    void updateFreqList(Node* node){
        ///first erase it 
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);
        //if freqNode become empty increasee all the nodes available count
        if(node->cnt==minFreq && freqListMap[node->cnt]->size==0){
            minFreq++;
        }
        List*nextHigherList=new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end()){
                nextHigherList=freqListMap[node->cnt+1];
        }
        node->cnt+=1;
        nextHigherList->addNode(node);
        freqListMap[node->cnt]=nextHigherList;
        keyNode[node->key]=node;
    }
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node*node=keyNode[key];
            int value=node->val;
            updateFreqList(node);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache==0)return;
        if(keyNode.find(key)!=keyNode.end()){
            Node*node=keyNode[key];
            node->val=value;
            updateFreqList(node);
        }else{
            if(curSize==maxSizeCache){
                List*list=freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->deleteNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            //new Value has to be added who is not there previously
            minFreq=1;
            List* listFreq=new List();
            if(freqListMap.find(minFreq)!=freqListMap.end()){
                listFreq=freqListMap[minFreq];
            }
            Node*node=new Node(key,value);
            listFreq->addNode(node);
            keyNode[key]=node;
            freqListMap[minFreq]=listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */