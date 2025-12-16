#include<iostream>
#include<unordered_map>
using namespace std;

struct Node {
    int key, val, cnt;
    Node *next;
    Node *prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        cnt = 1;
        next = prev = nullptr;
    }
};

struct List {
    int size;
    Node *head;
    Node *tail;

    List() {
        size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
};

class LFUCache {
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node* node) {
        keyNode.erase(node->key);

        freqListMap[node->cnt]->removeNode(node);

        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

        node->cnt++;

        if (freqListMap.find(node->cnt) == freqListMap.end()) {
            freqListMap[node->cnt] = new List();
        }

        freqListMap[node->cnt]->addFront(node);
        keyNode[node->key] = node;
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) return -1;

        Node* node = keyNode[key];
        int res = node->val;
        updateFreqListMap(node);
        return res;
    }

    void put(int key, int value) {
        if (maxSizeCache == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);
            return;
        }

        if (curSize == maxSizeCache) {
            List* list = freqListMap[minFreq];
            Node* nodeToRemove = list->tail->prev;

            list->removeNode(nodeToRemove);
            keyNode.erase(nodeToRemove->key);
            curSize--;
        }

        curSize++;
        minFreq = 1;

        if (freqListMap.find(minFreq) == freqListMap.end()) {
            freqListMap[minFreq] = new List();
        }

        Node* node = new Node(key, value);
        freqListMap[minFreq]->addFront(node);
        keyNode[key] = node;
    }
};
