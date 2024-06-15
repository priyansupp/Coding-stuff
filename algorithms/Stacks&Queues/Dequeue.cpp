#include<bits/stdc++.h>
using namespace std;



class DQ{
    int Deque[1000000];
    // Dequeue is a DS that has all pushback and pushfront and popback and popfront and .front and .back
    int head = 499999, tail = 500000;    // head points at 1 less than the start of the queue, i.e at the position where new element would be pushed(front) and tail points at 1 more than the end of the queue, i.e at the position where new element would be pushed(back).
    //         1   3   5   6
    //  head                    tail

    
    public:
    void pushfront(int x){
        Deque[head] = x;
        head--;
    }
    void pushback(int x){
        Deque[tail] = x;
        tail++;
    }
    int front(){
        return Deque[head + 1];
    }
    int back(){
        return Deque[tail - 1];
    }
    void popfront(){
        head++;
    }
    void popback(){
        tail--;
    }
    int size(){
        return tail - head - 1;
    }
    bool isEmpty(){
        return tail - head <= 1;
    }
};



int main()
{
    DQ deque;
    deque.pushback(9);
    deque.pushfront(1);
    deque.pushfront(3);
    deque.pushback(5);
    deque.pushfront(6);
    // 6 3 1 9 5
    cout << deque.front() << " " << deque.back() << " " << deque.isEmpty() << " " << deque.size() << '\n';
    deque.popback();
    deque.popfront();
    deque.popfront();
    // 1 9
    cout << deque.front() << " " << deque.back() << " " << deque.isEmpty() << " " << deque.size() << '\n';
    return 0;
}

