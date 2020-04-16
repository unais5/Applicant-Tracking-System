#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Node2
{
	public:
		string str;
		Node2* next;
};

class list
{
    public:
    Node2 *head = NULL;
    void Insert(string extra)
	{
		if(head == NULL)
		{
			head = new Node2;
			head->str = extra;
			head->next = NULL;
		}
		else
		{
			Node2* temp = head;
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			Node2* temp1 = new Node2;
			temp1->str = extra;
			temp->next = temp1;
			temp1->next = NULL;
		}
        return;
	}
	int count(){
			Node2 *temp;
			int a=0;
			for(temp=head;temp!=NULL;temp=temp->next){
				a++;
			}
			return a;
	}
	Node2* get(){
		return head;
	}
    void print()
    {
        Node2* temp = head;
        while(temp!= NULL)
        {

            cout<<temp->str<<" ";
            temp = temp->next;
        }
    }
};
