class MyLinkedList {
    private:
    struct Node {
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = nullptr;
        }
        };
public:
Node*dummy;
int size;
    MyLinkedList() {
        dummy=new Node(0);
        size=0;
    }
    
    int get(int index) {
        if(index<0||index>=size)
            return -1;
        Node*curr=dummy->next;
        for(int i=0;i<index;i++){
            curr=curr->next;
        } 
        return curr->val;       
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
     
    }
    
    void addAtTail(int val) {
       addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size)
        return;

        if(index < 0)
        index = 0;
        Node*newNode=new Node(val);
        Node*prev=dummy;

        for(int i=0;i<index;i++){
            prev=prev->next;
        }
        newNode->next=prev->next;
        prev->next=newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
       if(index < 0 || index >= size)
        return;

        Node* prev = dummy;

        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        Node* del = prev->next;
        prev->next = del->next;

        delete del;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */