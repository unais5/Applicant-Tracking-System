#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
template <class a>
class node{
	public:
		a data;
		node* next;
			node(){
			next=NULL;}
		node(a m,node *n){
			data=m;
			next=n;
		}
};
template <class t>
class list{
	private:
		node<t> *head,*tail;
	public:
		class Iterator;
		list<t>(){
			head=NULL;
			tail=NULL;
		}
		list<t>(int n,node<t> *no=node<t>()){
			head=no;
			tail=no;
			no->next=NULL;
			for(int i=1;i<n;i++){
				node<t> *n2=new node<t> (no->data,NULL);
				tail->next=n2;
				tail=n2;
			}
			tail->next=NULL;
		}
		list<t> (Iterator first,Iterator last){
			head=new node<t>(*first,NULL);
			tail=head;
			first++;
			while(first!=last){
				node<t> *n2=new node<t> (*first,NULL);
				tail->next=n2;
				first++;
				tail=n2;
			}
				node<t> *n2=new node<t> (*first,NULL);
				tail->next=n2;
				first++;
				tail=n2;
		}
		
		class Iterator {
			private:
				node<t> *c_node;
			public:
				Iterator(){
					c_node=NULL;
				}
				Iterator(node<t> *p){
					c_node=p;
				}
				Iterator& operator=(node<t> *p) { 
            		this->c_node = p; 
            		return *this; 
        		} 
        		node<t>* getref(){
        			return c_node;
				}
        		Iterator& operator++(int){ 
           			if (c_node!=NULL){
                	 c_node= c_node->next; 
            		}
					return *this; 
        		} 
				bool operator!=(Iterator& p){ 
        		    return c_node != p.c_node; 
				} 
				t operator*(){
					return c_node->data;
				}
		};
		public:
		node<t>* gethead(){
			return head;
		}
		node<t>* getail(){
			return tail;
		}
		Iterator begin(){
			return Iterator(head);
		}
		Iterator end(){
			return Iterator(NULL);
		}
		const Iterator begin()const{
			return Iterator(head);
		}
		const Iterator end()const{
			return Iterator(NULL);
		}
		void addtohead(t a){
			if(head!=NULL){
				node<t> *temp;
				temp=head;
				node<t> *n2=new node<t>(a,temp);
				head=n2;
			}else{
				node<t> *n2=new node<t>(a,NULL);
				head=n2;
				tail=n2;
			}
		}
		void addtotail(t a){
			if(head!=NULL){
			node<t> *temp;
			for( temp=head;temp->next != NULL;){
				temp=temp->next;
			}
			node<t> *n2=new node<t>(a,NULL);	
			temp->next=n2;
			tail=n2;
			}else{
				node<t> *n2=new node<t>(a,NULL);
				head=n2;
				tail=n2;
			}
		
		}
		void printlist(){
			if(head==NULL){
				cout<<"empty list"<<endl;
				return;
			}
			node<t> *temp;
			cout<<head->data<<endl;
			for(temp=head;temp->next!=NULL;){
				temp=temp->next;
				cout<<temp->data<<endl;
			}
		}
		void addtoindex (t a,t b){
			node<t> *temp=head;
			while(temp->data!=a){
				if(temp->next==NULL){
					cout<<"node not found"<<endl;
				}
			temp=temp->next;
			}
			node<t> *n2=new node<t>(b,temp->next);
			temp->next=n2;
		}
		void clear(){
			node<t> *temp;
			node<t> *temp2=head;
			while(temp2!=NULL){
				temp=temp2;
				temp2=temp2->next;
				delete temp;
			}
			head=NULL;
			tail=NULL;
		}
		void addnode(node<t> *n){
			if(head!=NULL){
				tail->next=n;
				tail=n;
				n->next=NULL;
			}else{
				head=n;
				tail=head;
				n->next=NULL;
			}
		}
		void assign (Iterator first,Iterator last){
			list<t> newlist;
			while(first!=last){
				newlist.addtotail(*first);
				first++;
			} 
			newlist.addtotail(*first);
			this->clear();
			head=newlist.gethead();
			tail=newlist.getail();
		}
		void assign(int n,node<t> *no=node<t>()){
			list<t> newlist;
			for(int i=0;i<n;i++){
				newlist.addtotail(no->data);
			}
			this->clear();
			head=newlist.gethead();
			tail=newlist.getail();
		}
		t& front(){
			return head->data;
		}
		const t& front() const{
			return head->data;
		}
		t& back(){
			node<t> *ta=head;
			while(ta->next!=NULL){
				ta=ta->next;
			}
			return ta->data;
		}
		const t& back()const {
			node<t> *ta=head;
			while(ta->next!=NULL){
				ta=ta->next;
			}
			return ta->data;
		}
		bool empty()const{
			if(head==NULL){
				return true;
			}else{
				return false;
			}
		}
		Iterator erase(Iterator i){
			node<t> *temp=head;
			node<t> *temp2=i.getref();
			while(temp->next!=i.getref()){
				temp=temp->next;
			}
			i++;
			temp->next=temp2->next;
			delete temp2;
			return i;
		}
		Iterator erase(Iterator first,Iterator last){
			node<t> *temp=head;
			node<t> *temp2=last.getref();
			while(temp->next!=first.getref()){
				temp=temp->next;
			}
			last++;
			temp->next=temp2->next;
			return last;
		}
		Iterator insert(Iterator i,node<t> *no=node<t>()){
			node<t> *temp=head;
			while(temp->next!=i.getref()){
				temp=temp->next;
			}
				node<t> *temp2=new node<t>(no->data,i.getref());
				temp->next=temp2;
			return Iterator(temp2);
		}
		void insert(Iterator i,int n,node<t> *no=node<t>()){
			node<t> *temp=head;
			while(temp->next!=i.getref()){
				temp=temp->next;
			}
			for(int i=0;i<n;i++){
				node<t> *n2=new node<t> (no->data,temp->next);
				temp->next=n2;
				temp=n2;
			}
		}
		void insert(Iterator i,Iterator first,Iterator last){
			node<t> *temp=head;
			while(temp->next!=i.getref()){
				temp=temp->next;
			}
			list<t> newlist;
			while(first!=last){
				newlist.addtotail(*first);
				first++;
			} 
			temp->next=newlist.gethead();
			temp=newlist.getail();
			temp->next=last.getref();
		}
};

