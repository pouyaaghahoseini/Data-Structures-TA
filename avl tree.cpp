#include <iostream>
using namespace std;
class node{
	public:
	int data;
	int height;
	node* leftchild;
	node* rightchild;
};
int height(node *n)  
{  
    if (n == NULL)  
        return 0;  
    return n->height;  
} 
int balance(node *n)
{
	return (height(n->leftchild) - height(n->rightchild));
}
node *rightright(node* n)
{
	node *n1=(n->leftchild)->rightchild;
	(n->leftchild)->rightchild=n;
	n->leftchild=n1;
	n->height=max(height(n->rightchild),height(n->leftchild));
	(n->leftchild)->height=max(height((n->leftchild)->rightchild),height((n->leftchild)->leftchild));
	return n->leftchild;
}
node *leftleft(node *n)
{
	node *n1=(n->rightchild)->leftchild;
	(n->rightchild)->leftchild=n;
	n->rightchild=n1;
	n->height=max(height(n->rightchild),height(n->leftchild));
	(n->rightchild)->height=max(height((n->rightchild)->rightchild),height((n->rightchild)->leftchild));
	return n->rightchild;
}
void balancing(node *n)
{
	n->height=max(height(n->leftchild),height(n->rightchild))+1; 
	if(balance(n)>1 && -1<balance(n->leftchild)<2)
	{
		//right
		cout<<"balancing "<<n->data;
		rightright(n);
	}
	else if(balance(n)<-1 && -2<balance(n->rightchild)<1)
	{
		//left
		cout<<"balancing "<<n->data;
		leftleft(n);
	}
	else if(balance(n)>1 && balance(n->leftchild)==-1)
	{
		//leftright
		cout<<"balancing "<<n->data;
		n->leftchild=leftleft(n->leftchild);
		rightright(n);
	}
	else if(balance(n)<-1 && balance(n->rightchild)==1)
	{
		//rightleft
		cout<<"balancing "<<n->data;
		n->rightchild=(n->rightchild);
		leftleft(n);
	}
}
void add(node *n,double d)
{
	if(n==NULL)
	{
		n= new node(); 
    	n->data = d;  
   		n->height =1;
    	n->leftchild = NULL;  
    	n->rightchild = NULL; 
		cout<<"added";
	}
	else
	{
	if((n->data)>d)
	{
		add(n->leftchild,d);
	}
	else if((n->data)<d)
	{
		add(n->rightchild,d);
	}
	else if((n->data)==d)
	{
		cout<<"already in there";
	}
	}
balancing(n);
}
node *minright(node *n)
{
	node *m=n->rightchild;
	while((m->leftchild)!=NULL)
	m=m->leftchild;
	return m;
}
void removee(node *n,double d)
{
	if(n==NULL)
	{
		cout<<"does not exist";
	}
	else
	{
	if((n->data)>d)
	{
		removee(n->leftchild,d);
	}
	else if((n->data)<d)
	{
		removee(n->rightchild,d);
	}
	else if((n->data)==d)
	{
		if(n->leftchild==NULL && n->rightchild==NULL)
		{
			n=NULL;
		}
		else if(n->leftchild==NULL && n->rightchild!=NULL)
		{
			*n=*n->rightchild;
		}
		else if(n->leftchild!=NULL && n->rightchild==NULL)
		{
			*n=*n->leftchild;
		}
		else
		{
			node *t1=minright(n);
			n->data=t1->data;
			removee(n->rightchild,t1->data);
		}
		cout<<"removed";
	}
	}
balancing(n);	
}
void findd(node *n,double d)
{
	if(n==NULL)
	{	
		cout<<"not found";	
	}
	else
	{
	if((n->data)==d)
	cout<<d;
	else if((n->data)>d)
	{
		findd(n->leftchild,d);
	}
	else if((n->data)<d)
	{
		findd(n->rightchild,d);
	}
	}
}
int main()
{
	int a;
	cin>>a;
	string s;
	node* n=NULL;
	double value;
	for(int i=0;i<a;i++)
	{
		cin>>s;
		cin>>value;
		if(s=="add")
		{
			add(n,value);
		}
		else if(s=="remove")
		{
			removee(n,value);
		}
		else if(s=="find")
		{
			findd(n,value);
		}
	}
}
