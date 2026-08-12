// Design Circular Deque
// https://leetcode.com/problems/design-circular-deque/
// Difficulty: Medium
// Language: cpp
// Runtime: 7
// Memory: 24544000

class MyCircularDeque {
public:
    vector<int> v;
    int front = 0,back = 0,n;
    MyCircularDeque(int k) {
        v.resize(k,0);
        front = -1;
        back = -1;
        n = k;
    }
    
    bool insertFront(int value) {
        if(isFull())
        return false;

        if(front == -1){
            front = 0;
            back = 0;
            v[0] = value;
        }
        else
        {
            front = (front-1 +n)%n;
            v[front] = value;
        }
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
        return false;

        if(back == -1){
            front = 0;
            back = 0;
            v[0] = value;
        }
        else
        {
            back = (back+1)%n;
            v[back] = value;
        }
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
        return false;
        if(front == back){
            front = -1;
            back = -1;
            return true;
        }
        front = (front+1)%n;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
        return false;
        if(front == back){
            front = -1;
            back = -1;
            return true;
        }
        back = (back-1 + n)%n;
        return true;
    }
    
    int getFront() {
        if(isEmpty())
        return -1;
        return v[front];
    }
    
    int getRear() {
        if(isEmpty())
        return -1;
        return v[back];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return front == (back+1)%n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
