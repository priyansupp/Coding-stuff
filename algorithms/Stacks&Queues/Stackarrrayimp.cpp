#include<bits/stdc++.h>
using namespace std;

class S{
    public:
    vector<int>Stack;
    void Push(int x){
        Stack.push_back(x);
    }
    int Top(){
        if(!Stack.empty())
            return Stack.back();
        else
            cout << "Stack Underflow";
            return 0;
    }
    void Pop(){
        Stack.pop_back();
    }
    bool isEmpty(){
        return !Stack.size();
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

