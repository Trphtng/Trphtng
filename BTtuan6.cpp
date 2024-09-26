#include <iostream>
using namespace std;
struct Node {
	int data;
	Node * next;
};typedef struct Node * node;

node createNode (int x){
	node p = new Node();
	p->data = x;
	p->next = NULL;
	return p;
}
void push (node &top,int x){
	node p = createNode(x);
	if (p!=NULL)
	{
		p->next = top;
		top = p;
	}
	
}
int pop (node &top){
	int x;
	if (top!= NULL)
	{
		node tmp = top;
		top = tmp->next;
		x=tmp->data;
		delete tmp;
	}
	return x;
}
int top(node top){
	if(top!= NULL)
		return top->data;
}
int main (){
	node st = NULL;
	push(st,5);
	push(st,6);
	push(st,1);
	while (st!=NULL)
	{
		cout<< top(st)<< endl;
		pop(st);
	}
	
}
