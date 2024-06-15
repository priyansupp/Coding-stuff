//PRIYANSHU KUMAR JAISWAL
//200123043
//QUESTION 1
//LAB 4
//Write a program to convert an infix expression to postfix expression and
//evaluate the postfix expression and prints the value. The given infix expression need not be fully paranthesized. So your program should handle
//the precedence of operators.


#include<bits\stdc++.h>
using namespace std;
bool isoprtr(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^') return true;
    return false;
}
bool openparanthesis(char c){
    if(c=='(' || c=='{' || c=='[') return true;
    return false;
}
bool closeparanthesis(char c){
    if(c==')' || c=='}' || c==']') return true;
    return false;
}
int GetOperatorWeight(char op)
{
	int weight = -1;
	if(op=='+' || op=='-') weight=1;
	else if(op=='*' || op=='/') weight=2;
	else if(op=='^') weight=3;
	return weight;
}
bool highprecedence(char operator1, char operator2){
    int op1Weight = GetOperatorWeight(operator1);
	int op2Weight = GetOperatorWeight(operator2);

	return op1Weight > op2Weight ?  true: false;
}

//calculating postfix expression

string  inftopost(string str){
    stack<char>oprtr;
    int l=str.length();
    string postfix="";
    for(int i=0;i<l;i++){
        if(str[i]==' ' || str[i]==',') continue;
        else if(isoprtr(str[i])){
            while(!oprtr.empty() && highprecedence(oprtr.top(),str[i]) && !openparanthesis(oprtr.top())){
                postfix=postfix+oprtr.top();
                oprtr.pop();
            }
            oprtr.push(str[i]);
        }
        else if(openparanthesis(str[i])) oprtr.push(str[i]);
        else if(closeparanthesis(str[i])){
            while(!oprtr.empty() && !openparanthesis(oprtr.top())){
                postfix=postfix+oprtr.top();
                oprtr.pop();
            }
            oprtr.pop();
        }
        else postfix=postfix+str[i];
    }
    while(!oprtr.empty()){
        postfix=postfix+oprtr.top();
        oprtr.pop();
    }
    return postfix;
}

// calculating value of expression

int applyOp(int a, int b, char op){
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
}

int value(string exp){
    int i;
    stack<int>integers;
    stack<char>oprtr;
    for(int i=0;i<exp.length();i++){
        if(exp[i]==' ' || exp[i]==',') continue;
        else if(openparanthesis(exp[i])) oprtr.push(exp[i]);
        else if(isdigit(exp[i])){
            int val=0;
            while(i<exp.length() && isdigit(exp[i])){
                val=(val*10)+(exp[i]-'0');
                i++;
            }
            integers.push(val);
            i--;
        }
        else if(closeparanthesis(exp[i])){
            while(!oprtr.empty() && !openparanthesis(oprtr.top())){
                int val2=integers.top();
                integers.pop();
                int val1=integers.top();
                integers.pop();
                char op=oprtr.top();
                oprtr.pop();
                integers.push(applyOp(val1,val2,op));
            }
            if(!oprtr.empty()) oprtr.pop();
        }
        else {
            while(!oprtr.empty() && GetOperatorWeight(oprtr.top()) >= GetOperatorWeight(exp[i])){
                int val2=integers.top();
                integers.pop();
                int val1=integers.top();
                integers.pop();
                char op=oprtr.top();
                oprtr.pop();
                integers.push(applyOp(val1,val2,op));
            }
            oprtr.push(exp[i]);
        }
    }
    while(!oprtr.empty()){
        int val2=integers.top();
        integers.pop();
        int val1=integers.top();
        integers.pop();
        char op=oprtr.top();
        oprtr.pop();
        integers.push(applyOp(val1,val2,op));
    }
    return integers.top();
}
int main()
{
    string s;
    cout<<"Enter the INFIX expression:  "<<endl;
    cin>>s;
    cout<<"POSTFIX expression:  "<<inftopost(s)<<endl;
    cout<<"Value of expression: "<<value(s)<<endl;
    return 0;
}
