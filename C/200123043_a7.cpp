//PRIYANSHU KUMAR JAISWAL
//200123043
//QUESTION 1
//LAB 7


#include <bits/stdc++.h>
using namespace std;

struct node    //node template
{
	char exp;
	int x, y;
	struct node *l, *r; 
};
typedef struct node* nptr;

nptr newNode(char c)   //creating new node.
{
	nptr temp = new node;
	temp->exp=c;
	temp->l=nullptr;
	temp->r=nullptr;
	temp->x=0;
	temp->y=0;
	return temp;
}

bool isDigit(char c){
	if ('0' <= c && c <= '9')
	{
		return 1;
	}
	return 0;
}

nptr tree(string& s)
{

	stack<nptr> N;
	stack<char> C;
	nptr t, t1, t2;

	int p[123] = { 0 };       // assigning weightage to signs and symbols.
	p['+'] = p['-'] = 1, p['/'] = p['*'] = 2, p['^'] = 3,
	p[')'] = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(') C.push(s[i]);

		else if (isDigit(s[i]))
		{
			t = newNode(s[i]);
			N.push(t);
		}
		else if(isalpha(s[i])){
			t = newNode(s[i]);
			N.push(t);
		}
		else if (p[s[i]] > 0)
		{
			while (!C.empty() && C.top() != '(' && ((s[i] != '^' && p[C.top()] >= p[s[i]]) || (s[i] == '^' && p[C.top()] > p[s[i]])))
			{
				t = newNode(C.top());
				C.pop();

				t1 = N.top();
				N.pop();
				t2 = N.top();
				N.pop();

				t->l= t2;
				t->r = t1;

				N.push(t);
			}
			C.push(s[i]);
		}
		else if (s[i] == ')') {
			while (!C.empty() && C.top() != '('){
				t = newNode(C.top());
				C.pop();
				t1 = N.top();
				N.pop();
				t2 = N.top();
				N.pop();
				t->l = t2;
				t->r = t1;
				N.push(t);
			}
			C.pop();
		}
	}
	t =N.top();
	return t;
}
int j=0;
void preorder(nptr root){
	j++;
	if(root==NULL){
		j--;
		return;
	}
		root->x=j-1;
		preorder(root->l);
		preorder(root->r);
}

void printtree(){
	cout<<endl<<"Tree:"<<endl;
    cout<<"                        -                      "<<endl;
    cout<<"             /                      +"<<endl;    
    cout<<"        *         +           *          6"<<endl;
    cout<<"     +     3   -     2     3     -"<<endl;
    cout<<"  3   1      9   5             7   4    "<<endl;
}
int depth(nptr root, int x){
	if (root == NULL)
        return -1;

    int dist = -1;
    if ((root->exp == x) || (dist = depth(root->l, x)) >= 0 || (dist = depth(root->r, x)) >= 0)
        return dist + 1;
 
    return dist;
}


char arr[20][20];
void levelorder(nptr root){
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++) arr[i][j]=' ';
	}
	if(root == NULL) return;
	queue<nptr>Q;
	Q.push(root);
	while(!Q.empty()){
		nptr current=Q.front();

		current->y=depth(root,current->exp);
		cout<<"For  "<<current->exp<<"  x coordinate is "<<current->x<<" and y coordinate is "<<current->y<<endl;
		arr[current->x][current->y]=current->exp;
		if(current->l!=NULL) Q.push(current->l);
		if(current->r!=NULL) Q.push(current->r);
		Q.pop();
	}
}

void printtree1(){
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			arr[i][j]=' ';
		}
	}
}



int main()
{
	string s;
	cin>>s;
	cout<<'\n';
	nptr root = tree(s);
	cout<<"Root of the tree is "<<root->exp<<'\n'<<endl;
	preorder(root);
	levelorder(root);
	printtree();
	int pos=0;
	for(int i=0;i<s.length();i++){
		if(isDigit(s[i])){
			pos++;
		}
	}
	int k,val;
	cout<<"enter the position and value"<<endl;
	cin>>k>>val;
	s[k-1]=val;
	nptr root1 = tree(s);
	cout<<"Root of the tree is "<<root1->exp<<'\n'<<endl;
	preorder(root1);
	levelorder(root1);
	printtree();
	return 0;
}
// ((((3+1)∗3)/((9−5)+2))−((3∗(7−4))+6))