class ArrayQueue {

private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    ArrayQueue(int size){
        arr = new int[size];
        front = 0;
        rear = 0;
        this->size = size;
    }

    void push(int x) {
        if(rear == size) {
            return;
        }
        else {
            arr[rear] = x;    
            rear++;
        }
    }
    
    int pop() {
        if(front == rear) {
            return -1;     
        }
        else {
            int ans = arr[front];
            front++;

            if(front == rear) {
                front = 0;
                rear = 0;
            }

            return ans;
        }
    }
    
    int peek() {
        if(front == rear) {
            return -1;
        }
        else {
            return arr[front];
        }
    }
    
    bool isEmpty() {
        return (front == rear);
    }
};