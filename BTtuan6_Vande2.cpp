#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct Node {
	float data;
	Node * next;
};typedef struct Node * node;

node createNode (float x){
	node p = new Node();
	p->data = x;
	p->next = NULL;
	return p;
}
void push (node &top,float x){
	node p = createNode(x);
	if (p!=NULL)
	{
		p->next = top;
		top = p;
	}
	
}
int pop (node &top){
	float x;
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
void DocTu(char s[], char tu[], int&vt)
{
	for(int i = 0; i<strlen(tu); i++)
		tu[i]= ' ';
	int i = 0;
	while(s[vt] != ' ')
	{
		tu[i] = s[vt];
		vt++;
		i++;
	}
}
int LaToanTu(char s[])
{
	char c = s[0];
	if((c == '+') || (c == '-') || (c == '*') || (c == '/'))
		return 1;
	return 0;
} 
float TinhToan(float a, float b, char toanTu)
{
	float kq;
	switch (toanTu)
	{
	case '+': kq = a + b; break;
	case '-': kq = a - b; break;
	case '*': kq = a * b; break;
	case '/': kq = a / b; 
	}
	return kq;
} 
float TinhBieuThuc(node &s, char bieuThuc[])
{
	float kq;
	char t[10] ;
	int i=0;
	do
	{
		DocTu(bieuThuc, t, i);
		if(LaToanTu(t))
		{
			char toanTu = t[0]; 
			float toanHang1 = pop(s);
			float toanHang2 = pop(s);
			kq = TinhToan(toanHang2, toanHang1, toanTu);
			push(s, kq);
		}
		else
		{
			float toanHang = atof(t);
			push(s, toanHang);
		}
		i++;
	}while(bieuThuc[i]!='#'); 
	return pop(s);
}

int main (){
	node st = NULL;
	char bt[100] = {"5"," ","1","7"," ","3"," ","+"," ","*"," ","6"," ","-"," ","#"};
	TinhBieuThuc(st,bt);
	
}
