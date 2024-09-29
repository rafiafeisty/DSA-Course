#include<iostream>
using namespace std;

class DNode{
public:
    DNode *prev;
    DNode* next;
    int data;
    DNode(int val){
        next=NULL;
        prev=NULL;
        data=val;
    }
};
class DList{
public:
    DNode* head;
    DNode* tail;
    DList(){
        head=NULL;
        tail=NULL;
    }
    void insertAtStart(int val){
        DNode* temp=new DNode(val);
        if(head==NULL&& tail==NULL){
            head=temp;
            tail=temp;
        }
        else{
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
    }

    void pairSum(int x){
        DNode* head1=head;
        while(head1!=NULL){
            DNode* head2=head;
            while(head2!=NULL){
                if((head1->data+head2->data)==x){
                    cout << "( " << head1->data << ", " << head2->data << " )" << endl;
                }
                head2=head2->next;
            }
            head1=head1->next;
        }
    }

    void display(){
        DNode* head1=head;
        while(head1!=NULL){
            cout << head1->data << endl;
            head1=head1->next;
        }
    }
};

class Node{
public:
    Node* next;
    int data;
    Node(int val){
        next=NULL;
        data=val;
    }
};

class List{
public:
    Node* head;
    List(){
        head=NULL;
    }
    void insertAtStart(int val){
        Node* temp=new Node(val);
        if(head==NULL){
            head=temp;
        }
        else{
            temp->next=head;
            head=temp;
        }
    }

    Node* partitioning(int x){
        Node* head1=head;
        List* temp=new List();
        while(head1!=NULL){
            if((head1->data)>x){
                temp->insertAtStart(head1->data);
            }
            head1=head1->next;
        }
        head1=head;
        while(head1!=NULL){
            if(head1->data==x){
                temp->insertAtStart(head1->data);
            }
            head1=head1->next;
        }
        head1=head;
        while(head1!=NULL){
            if(head1->data<x){
                temp->insertAtStart(head1->data);
            }
            head1=head1->next;
        }
        return temp->head;
    }

    void display(){
        Node* head1=head;
        while(head1!=NULL){
            cout << head1->data << endl;
            head1=head1->next;
        }
    }
};


int main(){
    cout << "QUESTION NUMBER 1" << endl;
    DList *L1=new DList();
    L1->insertAtStart(1);
    L1->insertAtStart(2);
    L1->insertAtStart(4);
    L1->insertAtStart(5);
    L1->insertAtStart(6);
    L1->insertAtStart(8);
    L1->insertAtStart(9);
    cout << "ORIGINAL LIST" << endl;
    L1->display();
    cout << "------------------" << endl;
    cout << "PAIR SUM" << endl;
    L1->pairSum(7);
    cout << endl;
    cout << "QUESTION NUMBER 2" << endl;
    List *L2=new List();
    L2->insertAtStart(1);
    L2->insertAtStart(4);
    L2->insertAtStart(3);
    L2->insertAtStart(2);
    L2->insertAtStart(5);
    L2->insertAtStart(2);
    L2->insertAtStart(3);
    cout << "--------------------" << endl;
    cout << "ORGINAL LIST" << endl;
    L2->display();
    cout << "--------------------" << endl;
    cout << "AFTER PARTIONING" << endl;
    L2->head=L2->partitioning(3);
    L2->display();
    return 0;
}
