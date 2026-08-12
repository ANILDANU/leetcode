// Design Circular Queue
// https://leetcode.com/problems/design-circular-queue/
// Difficulty: Medium
// Language: cpp
// Runtime: 3
// Memory: 23508000

class MyCircularQueue {
public:
  int front=-1;
  int back=-1;
  vector<int> v;
  int n=-1;
    MyCircularQueue(int k) {
      //cout<<k<<endl;
        v.resize(k,0);
      n=k;
    }
    
    bool enQueue(int value) {
      if(isFull())
        return false;
      if(front==-1)
        front=front+1;
  
      back=(back+1)%n;
      v[back]=value;
      return true;
    }
    
    bool deQueue() {
        if(isEmpty())
          return false;
      bool k=front==back;
      
      
      front=(front+1)%n;
      if(k)
        front=-1,back=-1;
      return true;
    }
    
    int Front() {
        if(front==-1)
          return -1;
      int val=v[front];
      //front=(front+1)%n;
      return val;
    }
    
    int Rear() {
      if(back==-1)
        return -1;
      int val=v[back];
      return val;
    }
    
    bool isEmpty() {
        if(front==-1)
          return true;
      return false;
    }
    
    bool isFull() {
      //cout<<back<<" "<<front<<endl;
        if((back+1)%n==front)
          return true;
      return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
