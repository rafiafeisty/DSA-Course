#include<iostream>
#include<stdio.h>

using namespace std;

class DNode{
public:
    int data;
    DNode *prev;
    DNode *next;
    DNode(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
    DNode(){
    next=NULL;
    prev=NULL;
    }
};
class DList{
public:
    DNode *head;
    DNode *tail;
    DList(){
        head=NULL;
        tail=NULL;
    }


    bool isEmpty(){
        if(head==NULL && tail==NULL){
        return true;
        }
        else{
            return false;
        }
    }


    void insertAtStart(int val){
        DNode *ptr=new DNode(val);
        if(!isEmpty()){
            ptr->next=head;
            head->prev=ptr;
            head=ptr;
            return;
        }
        else{
            head=ptr;
            tail=ptr;
            return;
        }
    }


    void delteNode(int val){
    DNode *head2=head;
    bool isfound=false;
    while(head2!=NULL){
        if(val==head2->data){
            isfound=true;
            break;
        }
        head2=head2->next;
    }
    if(isfound){
        if(head2->prev==NULL){
            head=head2->next;
            head->prev=NULL;
            delete head2;
            return;
        }
        else if(head2->next==NULL){
            tail=head2->prev;
            tail->next=NULL;
            delete head2;
            return;
        }
        else{
            head2->prev->next=head2->next;
            head2->next->prev=head2->prev;
            delete head2;
            return;
        }
    }
    else{
        cout << "Value not Found" << endl;
    }
}


    void reverseDisplay(){
        DNode *tail2=tail;
        while(tail2!=NULL){
            cout << tail2->data << endl;
            tail2=tail2->prev;
        }
    }


void insertAfterSpecificNode(int index, int val){
    DNode *head2=head;
    DNode *ptr=new DNode(val);
    if(index<0){
    cout << "Invalid Index" << endl;
    return;
    }
    else if(index==0){
        insertAtStart(val);
        return ;
    }
    else{
        int i=0;
        while(i<index-1 && head2!=NULL){
            i++;
            head2=head2->next;
        }
        if(head2==NULL){
            cout << "Invalid Index" << endl;
            return;
        }
                if(head2->next==NULL){
                    tail->next=ptr;
                    ptr->prev=tail;
                    tail=ptr;
                    return;
                }
                else{
                    ptr->next=head2->next;
                    head2->next->prev=ptr;
                    ptr->prev=head2;
                    head2->next=ptr;
                    return;
                }
    }
}


    void countNodes(){
        DNode *head2=head;
        int count=0;
        while(head2!=NULL){
                head2=head2->next;
            count++;
        }
        cout << "Total Number of Nodes are: " << count << endl;
    }

    void mergeList(DList *list1, DList *list2){
        DNode *head1=list1->head;
        DList *temp=new DList();
        while(head1!=NULL){
        DNode *head2=list2->head;
            while(head2!=NULL){
                if(head1->data==head2->data){
                    temp->insertAtStart(head2->data);
                }
                head2=head2->next;
            }
            head1=head1->next;
        }
        DNode *head3=temp->head;
        while(head3!=NULL){
            if(head3->next!=NULL){
            if(head3->data==head3->next->data){
                temp->delteNode(head3->data);
            }
        }
            head3=head3->next;
        }
        temp->display();
    }

    void traverseList(){
        DNode *head2=head;
        DNode *tail2=tail;
        cout << "TRAVERSING IN FORWARD DIRECTION" << endl;
        while(head2!=NULL){
            cout << head2->data << endl;
            head2=head2->next;
        }
        cout << endl;
        cout << "TRAVERSING IN BACKWARDS DIRECTION" << endl;
        while(tail2!=NULL){
            cout << tail2->data << endl;
            tail2=tail2->prev;
        }
    }


    void display(){
        DNode *head2=head;
        while(head2!=NULL){
            cout << head2->data << endl;
            head2=head2->next;
        }
    }

};
int main(){
    cout << "INSERTION FUNCTION" << endl;
    DList* L1=new DList();
    L1->insertAtStart(90);
    L1->insertAtStart(80);
    L1->insertAtStart(60);
    L1->insertAtStart(50);
    L1->insertAtStart(40);
    DList* L2=new DList();
    L2->insertAtStart(1);
    L2->insertAtStart(50);
    L2->insertAtStart(3);
    L2->insertAtStart(40);
    L2->insertAtStart(40);
    L1->display();
    cout << "---------------------" << endl;
    cout << "DELETION FUNCTION" << endl;
    L1->delteNode(90);
    L1->display();
    cout << "---------------------" << endl;
    cout << "REVERSE DISPLAY FUNCTION" << endl;
    L1->reverseDisplay();
    cout << "---------------------" << endl;
    cout << "INSERT AT SPECIFIC INDEX FUNCTION" << endl;
    L1->insertAfterSpecificNode(2,10);
    L1->display();
    cout << "---------------------" << endl;
    cout << "COUNTING NODES FUNCTION" << endl;
    L1->countNodes();
    cout << "---------------------" << endl;
    cout << "MERGE LISTS FUNCTION" << endl;
    L1->mergeList(L1,L2);

    cout << "---------------------" << endl;
    cout << "TRAVERSING FUNCTION" << endl;
    L1->traverseList();
    return 0;
}
