#include <iostream>
using namespace std;
#include <unordered_map>

class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            next = prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if (m.find(key) == m.end()){
            return -1;
        } 
        Node* node = m[key];
        deleteNode(node);
        addNode(node);
        return node->val;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* node = m[key];
            deleteNode(node);
            delete node;
            m.erase(key);
        }

        if (m.size() == cap) {
            Node* lru = tail->prev;
            m.erase(lru->key);
            deleteNode(lru);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */