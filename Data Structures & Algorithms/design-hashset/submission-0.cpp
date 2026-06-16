class MyHashSet {
public:
int size = 1000;
vector<list<int>> bucket;
    MyHashSet() {
        bucket.resize(size);
    }
    int hashFunction(int key){
        return key % size;
    }
    
    void add(int key) {
       int index = hashFunction(key);

        // avoid duplicates
        for(auto x : bucket[index]){
            if(x == key) return;
        }

        bucket[index].push_back(key);
    }
    
    void remove(int key) {
        int index = hashFunction(key);

        bucket[index].remove(key);
    }
    
    bool contains(int key) {
        int index = hashFunction(key);

        for(auto x : bucket[index]){
            if(x == key) return true;
        }

        return false;
    }
    
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */