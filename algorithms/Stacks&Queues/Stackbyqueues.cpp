#include<bits/stdc++.h>
using namespace std;


// q1 is used to hold all the push inputs and when popping, all elements from q1 is transferred into q2 and last element is then popped out, followed by a name change of q1 and q2.

class S{
    public:
    queue<int>q1, q2;
    void Push(int x){
        q1.push(x);
    }
    int Top(){
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q2.push(q1.front());
        q1.pop();
        queue<int>q;        // just changing the names of the queues.
        q = q1;
        q1 = q2;
        q2 = q;
        return x;
    }
    void Pop(){
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        queue<int>q;
        q = q1;
        q1 = q2;
        q2 = q;
    }
    bool isEmpty(){
        return q1.empty();
    }
    int size(){
        return q1.size();
    }
};



int main()
{
    S stack;
    stack.Push(1);
    stack.Push(3);
    stack.Push(5);
    stack.Push(6);
    cout << stack.Top() << " " << stack.isEmpty() << '\n';
    stack.Pop();
    cout << stack.Top() << " " << stack.isEmpty() << '\n';
    return 0;
}