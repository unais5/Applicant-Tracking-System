#include <iostream>
#include <dirent.h>
#include <fstream>
#include <sstream>
#include <string>
#include "Link_List.h"


using namespace std;
int perc_count=0;
int found=0;
int check=-1;
int w=0;
class Node  
{  
    public: 
    int key;
	string data; 
    Node *left;  
    Node *right;  
    int height;
	  
    Node(int a,string d){
    	key = a;
		data =d;  
    	left = NULL;  
    	right = NULL;  
    	height = 1;
	} 
};  
int stcomp(string a,string b){
	if(a.length()==b.length()-1){
	for(int i=0;i<a.length();i++){
		if(a[i]==b[i]){
			continue;
		}else{
			return -1;
		}	
	}
		return 0;
	}
	return -1;
}
int finds(string a,string b){
			int i;
			for( i=0;i<b.length();i++){
				if(a[i]==b[i]){
					continue;
				}else{
					break;
				}
			}
			if((i==b.length())&&(b.length()==(a.find(" ")))){
				return 0;
			}
			int j=0;
			for(i=a.find(" ")+1;i<a.length();i++,j++){
				if(a[i]==b[j]){
					continue;
				}else{
					return -1;
				}
			}
			return 0;
}
class AVL{
	private:
		Node *root;
	public:
		AVL(){
			root=NULL;
		}
		int max(int a, int b)  {  
   			return (a > b)? a : b;  
		}  
		int height(Node *N){  
    		if (N == NULL)  
        		return 0;  
    		return N->height;
		}
		Node *rightRotate(Node *y){  
    		Node *x = y->left;  
    		Node *T2 = x->right;  
  
 			x->right = y;  
    		y->left = T2;  
  
		    y->height = max(height(y->left),height(y->right)) + 1;  
    		x->height = max(height(x->left),height(x->right)) + 1;    
    		return x; 
		}  
		Node *leftRotate(Node *x){  
  			Node *y = x->right;  
    		Node *T2 = y->left;  

    		y->left = x;  
    		x->right = T2;  
  

    		x->height = max(height(x->left),height(x->right)) + 1;  
    		y->height = max(height(y->left),height(y->right)) + 1;  
    		return y;
		} 
		int getBalance(Node *N){ 
    		if (N == NULL)  
        		return 0;  
    		return height(N->left) - height(N->right);
		}  
		Node* insert(Node* node, int key,string data){  
		    if (node == NULL)  {
		        node=new Node(key,data);
				return node;
			}	  
		  
		    if (key < node->key){
		        node->left = insert(node->left, key,data);
			}else if (key > node->key){
		        node->right = insert(node->right, key,data);
			}else{
		        return node;
			}  
		  
		    
		    node->height = 1 + max(height(node->left),height(node->right));  
		    int balance = getBalance(node);  
		    if (balance > 1 && key < node->left->key){
		        return rightRotate(node);  
		    }
		    if (balance < -1 && key > node->right->key){
		        return leftRotate(node);  
			}
		    if (balance > 1 && key > node->left->key)  {  
		        node->left = leftRotate(node->left);  
		        return rightRotate(node);  
		    }  
		    if (balance < -1 && key < node->right->key){  
		        node->right = rightRotate(node->right);  
		        return leftRotate(node);  
		    }  
		    return node;  
		}
		void addnode(int a,string data){
			root = insert(root,a,data);
		}  
		void inorder(Node *N){  
		    if(N != NULL){  
		        
		        inorder(N->left);  
		        cout << N->data << " ";  
		        inorder(N->right);  
		    }  
		}
		void print(){
			inorder(root);
			cout<<endl;
		} 
		void inorderf(Node *N,fstream *f){  
		    if(N != NULL){  
		        
		        inorderf(N->left,f);  
		        *f << N->data << " ";
				if(N->data.find(".")!=-1){
					*f<<'\n';
				}  
		        inorderf(N->right,f);  
		    }  
		}
		void printfile(fstream *f){
			inorderf(root,f);
			*f<<endl;
		} 
		int function(string a){
			int b=0;
			for(int i=0;i<a.length();i++){
				b=b*10+(a[i]-48);
			}
			return b;
		}
		void inorder2(Node* nod, string word){
					if(nod != NULL){  
				        
				        inorder2(nod->left,word);  
				        
				        if(nod->data[0]>='0'&&nod->data[0]<='9'&&word[0]>='0'&&word[0]<='9'){
				        	int a,b;
							a=function(nod->data);
							b=function(word);
							if (a>=b){
								found=1;
								return;
							}
						}
						for(int i=0;i<(nod->data).length();i++){
							nod->data[i]=toupper(nod->data[i]);
						}
						if (word==nod->data){
							found=1;
							
							return;
						}
						if(word.length()<nod->data.length()){
						}else{
							check=finds(word,nod->data);
							if(check==0){
								
									found=1;
									check=-1;
							}
						}
						
				        inorder2(nod->right,word);  
				    } 
					
				}
				
		void inorder2(string word){
			found=0;
			inorder2(root,word);
			if (found==1){
				perc_count++;
			}
		}
		void destroy(Node* a){
			if(a){
				destroy(a->left);
				destroy(a->right);
				delete a;
			}
			root=NULL;
		}
		~AVL(){
			destroy(root);
		}
};

class l_node{
	public:
		string header;
		AVL data;
		l_node* next;
		l_node* prev;
		l_node(string h,l_node* n,l_node* p){
			header=h;
			next=n;
			prev=p;
		}		
};


class DLL_pro{
	private:
		l_node* head;
		l_node* tail;
	public:
		DLL_pro(){
			head=NULL;
			tail=NULL;
		}
		DLL_pro(string h){
			head= new l_node(h,NULL,NULL);
			tail=head;
		}
		void add(string header,string s){
			stringstream a;
			a.str(s);
			if (head== NULL){
				l_node* n=new l_node(header,NULL,NULL);
				head=n;
				tail=head;
				string b;
				int i=1;
				while (a>>b){
					n->data.addnode(i,b);
					i++;
				}
			}else{
				l_node* n=new l_node(header,NULL,tail);
				tail->next=n;
				tail=n;
				string b;
				int i=1;
				while (a>>b){
					n->data.addnode(i,b);
					i++;
				}
			}
		}
		void print(){
			l_node *temp;
			for(temp=head;temp!=NULL;temp=temp->next){
				cout<<temp->header<<endl;
				temp->data.print();
			}
		}
		void printfil(int i){
			stringstream ss;
			ss<<"E:/Semester 3 project/selected/Data_"<<i<<".txt";
			cout<<ss.str();
			fstream f;
			f.open(ss.str().c_str(),ios::out);
			l_node *temp;
			for(temp=head;temp!=NULL;temp=temp->next){
				f<<temp->header<<endl;
				temp->data.printfile(&f);
			}
			f.close();
		}
		
		int searching(list ACQ,list WORK_E,list EXQ){
			int n=0;
			perc_count=0;
			ACQ.print();
			WORK_E.print();
			EXQ.print();
			for(l_node *temp=head ;temp!=NULL;temp=temp->next)
			{
				if(stcomp("ACADEMIC QUALIFICATIONS:",temp->header)==0){
					cout<<"here a"<<endl;
					for(Node2 *temp2=ACQ.head;temp2!=NULL;temp2=temp2->next){
						for(int i=0;i<(temp2->str).length();i++){
							temp2->str[i]=toupper(temp2->str[i]);
						}
						 temp->data.inorder2(temp2->str);
					}
				}
				if(stcomp("WORK EXPERIENCE:",temp->header)==0){
					cout<<"here b"<<endl;
					for(Node2 *temp2=WORK_E.head;temp2!=NULL;temp2=temp2->next){
						 for(int i=0;i<(temp2->str).length();i++){
							temp2->str[i]=toupper(temp2->str[i]);
						}
						 temp->data.inorder2(temp2->str);
						
					}
				}
					for(Node2 *temp2=EXQ.head;temp2!=NULL;temp2=temp2->next){
						for(int i=0;i<(temp2->str).length();i++){
							temp2->str[i]=toupper(temp2->str[i]);
						}
						temp->data.inorder2(temp2->str);
					}
				
			}
			return perc_count;
		}
		~DLL_pro(){
			l_node *temp;
			for(temp=head;temp!=NULL;){
				head=temp;
				temp=temp->next;
				head->data.~AVL();
				delete head;
			
			}
			head=NULL;
		}
		
};
