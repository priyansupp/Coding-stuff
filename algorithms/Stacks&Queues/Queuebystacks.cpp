#include<bits/stdc++.h>
using namespace std;

class Q{
    public:
    stack<int>stack1, stack2;
    void Enqueue(int x){
        stack2.push(x);
    }
    int Dequeue(){          // pops the first element and returns it. In queue STL, .front() only returns and .pop() only pops the firt element.
        if(stack1.empty()){
            while(!stack2.empty()){
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        int x = stack1.top();
        stack1.pop();
        return x;
    }
    bool isEmpty(){
        return stack1.empty() && stack2.empty();
    }
    int size(){
        return stack1.size() + stack2.size();
    }
};



int main()
{
    Q queue;
    queue.Enqueue(-32);
    queue.Enqueue(9);
    queue.Enqueue(1);
    queue.Enqueue(3);
    queue.Enqueue(5);
    queue.Enqueue(6);
    queue.Enqueue(4);
    cout << queue.Dequeue() << " " << queue.isEmpty() << " " << queue.size() << " " << queue.Dequeue();
    return 0;
}

