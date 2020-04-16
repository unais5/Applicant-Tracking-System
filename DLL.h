#include <iostream>
using namespace std;
template <class a>
class node{
	public:
		a data;
		node* next;
		node* prev;
		node(){
			next=NULL;
			prev=NULL;
		}
		node(a m,node *Node,node *p){
			data=m;
			next=Node;
			prev=p;
		}
};
template <class t>
class DLL{
	private:
		node<t> *head,*tail;
	public:
		DLL(){
			head=NULL;
			tail=NULL;
		}
		DLL(t n){
			node<t> *no=new node<t>(n,NULL,NULL);
			head=no;
			tail=no;
		}
		void addtohead(t a){
			if(head!=NULL){
				node<t> *temp=new node<t>(a,head,NULL);
				head->prev=temp;
				head=temp;
				
			}else{
				node<t> *n2=new node<t>(a,NULL,NULL);
				head=n2;
				tail=n2;
			}
		}
		void addtotail(t a){
			if(head!=NULL){
				node<t> *temp=new node<t>(a,NULL,tail);
				tail->next=temp;
				tail=temp;
			}else{
				node<t> *n2=new node<t>(a,NULL,NULL);
				head=n2;
				tail=n2;
			}
		
		}
		void printlist(){
			node<t> *temp;
			for(temp=head;temp!=NULL;temp=temp->next){
				cout<<temp->data<<endl;
			}
		}
		int count(){
			node<t> *temp;
			int a=0;
			for(temp=head;temp!=NULL;temp=temp->next){
				a++;
			}
			return a;
		}
		t get(int n){
			node<t> *temp;
			int a=0;
			for(temp=head;temp!=NULL;temp=temp->next){
				if(a==n){
					break;
				}
				a++;
			}
			return temp->data;
		}
		~DLL<t>(){
			node<t> *temp;
			for(temp=head;temp!=NULL;){
				head=temp;
				temp=temp->next;
				delete head;
			}
		}
		
};
