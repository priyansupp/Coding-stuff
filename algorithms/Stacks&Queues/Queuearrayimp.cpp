#include<bits/stdc++.h>
using namespace std;

int head = 0, tail = 0;    // head points at the start of the queue and tail at the position where new element would be Enqueued.
//  1     3   5   6   
//  head              tail

class Q{
    public:
    vector<int>Queue;
    void Enqueue(int x){
        Queue.push_back(x);
        tail++;
    }
    int Dequeue(){          // pops the first element and returns it. In queue STL, .front() only returns and .pop() only pops the firt element.
        if(head == tail) {
            cout << "Nothing to deque";
            return 0;
        }
        int x = Queue[head];
        head++;
        return x;
    }
    bool isEmpty(){
        return head == tail;
    }
    int size(){
        return tail - head;
    }
};



int main()
{
    Q queue;
    queue.Enqueue(9);
    queue.Enqueue(1);
    queue.Enqueue(3);
    queue.Enqueue(5);
    queue.Enqueue(6);
    cout << queue.Dequeue() << " " << queue.isEmpty() << " " << queue.size();
    return 0;
}