#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class LinkedList{
public:
    Node*head;
    LinkedList(){
        head=NULL;
    }
    void insertAtHead(int val){
        Node *mynode=new Node(val);
        if(head==NULL){
            head=mynode;
        }
        else{
            mynode->next=head;
            head=mynode;
        }
    }

    void insertAtLast(int val){
        Node *head2=head;
        Node *temp=new Node(val);
        Node *prev=head;
        while(head2!=NULL){
                prev=head2;
            head2=head2->next;
        }
        prev->next=temp;
        temp->next=NULL;
        head2=temp;
    }
    void update(int index, int newval){
        Node *head2=head;
        if(index<0){
            cout << "Not valid index" << endl;
        }
        int i=0;
        while(i!=index){
        if(head2->next==NULL){
            cout << "Invalid Index" << endl;
            return;
        }
            head2=head2->next;
            i++;
        }
        head2->data=newval;
    }
    void searching(int val){
        Node *head2=head;
        int i=0;
        while(head2!=NULL){
            if(head2->data==val){
                cout << "Value Found at " << i << " index" << endl;
                return;
            }
            head2=head2->next;
        }
        cout << "Value not found";

    }

    void insertAfterIndex(int index, int val){
        Node *head2=head;
        Node *prev=head;
        Node *temp=new Node(val);
        int i=0;
        while(i<=index){
            prev=head2;
            head2=head2->next;
            i++;
        }
        prev->next=temp;
        temp->next=head2;
    }
    void deleted(int val){
        Node *head2=head;
        Node *prev=head;
        bool found=false;
        while(head2!=NULL){
            if(head2->data==val){
                found=true;
                cout << "Value found" << endl;
                break;
            }
            prev=head2;
            head2=head2->next;
        }
        if(found){
            if(head2==head){
                head=head->next;
                delete head2;
            }
            else if(head2->next==NULL){
                prev->next=NULL;
                delete head2;
            }
            else{
                prev->next=head2->next;
                delete head2;
            }
        }
        else{
            cout << "Value not found" << endl;
        }
    }
    void sorting(){
        Node *head2=head;
        int temp=0;
        for(Node *i=head; i!=NULL; i=i->next){
            for(Node *j=i->next; j!=NULL; j=j->next){
                if(i->data > j->data){
                    temp=i->data;
                    i->data=j->data;
                    j->data=temp;
                }
            }
        }
        while(head2!=NULL){
            cout << head2->data << endl;
            head2=head2->next;
        }
    }
    void display(){
        if(head==NULL){
            cout << "Head is empty" << endl;
        }
        while(head!=NULL){
            cout << head->data << endl;
            head=head->next;
        }
    }
};
int main(){
    LinkedList L;
    L.insertAtHead(20);
    L.insertAtHead(30);
    L.insertAtHead(40);
    L.insertAtHead(50);
    L.insertAtLast(70);
    L.insertAtLast(90);
    L.update(4,45);
   L.searching(45);
   L.insertAfterIndex(2,1);
   L.deleted(45);
   // L.display();
   cout << endl;
   L.sorting();
}
