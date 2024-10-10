#include<iostream>
using namespace std;

class Queue{
public:
    int max_size;
    int *arr;
    Queue(int x){
        max_size=x;
        arr=new int(max_size);
    }
    int fronting=-1;
    int rear=-1;
    int numberofelements=0;
    bool isfull(){
        if(numberofelements==max_size){
            return true;
        }
        else{
            return false;
        }
    }
    bool isempty(){
        if(numberofelements==0){
            return true;
        }
        else{
            return false;
        }
    }
    void display(){
        int count=0;
        int i=(fronting+1)%max_size;
        while(count<numberofelements){
            cout << arr[i] <<" ";
            i=(i+1)%max_size;
            count++;
        }
        cout << endl;
    }
    bool enque(int val){
        if(isfull()){
            return false;
        }
        else{
        rear=(rear+1)%max_size;
        arr[rear]=val;
        numberofelements++;
        return true;
        }
    }
    int dequeing(){
        if(isempty()){
            return -1;
        }
        else{
            fronting=(fronting+1)%max_size;
            numberofelements--;
            return arr[fronting];
        }
    }
};
class node{
public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

class List{
public:
    node *fronting;
    node* rear;
    int counter=0;
    List(){
        fronting=NULL;
        rear=NULL;
    }
    bool isempty(){
        if(fronting==NULL&& rear==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    bool queueing(int x){
        node *temp=new node(x);
        if(isempty()){
            fronting=temp;
            rear=temp;
            return true;
        }
        else{
            rear->next=temp;
            rear=temp;
            return true;
        }
    }
    int dequeing(){
        if(isempty()){
            return -1;
        }
        else{
            node *todelete=fronting;
            int data=fronting->data;
            fronting=fronting->next;
            if(fronting==NULL){
                rear=NULL;
            }
            delete todelete;
            return data;
        }
    }
    void display(){
        node *front1=fronting;
        while(front1!=NULL){
            cout << front1->data << " ";
            front1=front1->next;
        }
    }
};

class nodeprior{
public:
    int val;
    int priority;
    nodeprior* next;
    nodeprior(int data, int prior){
        val=data;
        priority=prior;
        next=NULL;
    }
};

class priority{
public:
    nodeprior *fronting;
    nodeprior *rear;
    int countering=0;
    priority(){
        fronting=NULL;
        rear=NULL;
    }
    bool isempty(){
        if(fronting==NULL&& rear==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    bool queueing(int a, int b){
        nodeprior *temp=new nodeprior(a,b);
        if(isempty()){
            fronting=temp;
            rear=temp;
            countering++;
            return true;
        }
        else{
            rear->next=temp;
            rear=temp;
            countering++;
            return true;
        }
    }int dequeing(){
    int comparing=fronting->priority;
    int index=0;
    nodeprior *front1=fronting;
    nodeprior *prev=NULL;
    int value;
    int counter=0;
    while(front1!=NULL){
        if(comparing > front1->priority){
            comparing=front1->priority;
            index=counter;
        }
        counter++;
        prev=front1;
        front1=front1->next;
    }
    front1=fronting;
    if(index==0){
        value=fronting->val;
        fronting=fronting->next;
        if(fronting==NULL){
            rear=NULL;
        }
    }
    else if(index==countering-1){
        int j=0;
        while(j<index-1){
            front1=front1->next;
            j++;
        }
        value=front1->next->val;
        front1->next=NULL;
        rear=front1;
    }
    else{
        front1=fronting;
        int j=0;
        while(j<index-1){
            front1=front1->next;
            j++;
        }
        value=front1->next->val;
        front1->next=front1->next->next;
    }
    countering--;
    return value;
}
    void display(){
        nodeprior *front1=fronting;
        while(front1!=NULL){
            cout << "(" << front1->val << "," << front1->priority << ")" << endl;
            front1=front1->next;
        }
    }
};
int main(){
    Queue *q1=new Queue(5);
    q1->enque(5);
    q1->enque(4);
    q1->enque(3);
    q1->enque(2);
    q1->enque(6);
    q1->display();
    cout << "------------------" << endl;
    cout << q1->dequeing() << endl;
    cout << q1->dequeing()<< endl;
    cout << q1->dequeing()<< endl;
    cout << "------------------" << endl;
    q1->display();
    cout << "------------------" << endl;
    List *l1=new List();
    l1->queueing(40);
    l1->queueing(30);
    l1->queueing(20);
    l1->queueing(10);
    l1->display();
    cout << endl;
    cout << "--------------------" << endl;
    cout << endl;
    cout << l1->dequeing()<< endl;
    cout << l1->dequeing()<< endl;
    cout << l1->dequeing()<< endl;
    cout << "----------------" << endl;
    l1->display();
    cout << endl;
    cout << "------------------" << endl;
    priority *p1=new priority();
    p1->queueing(555,2);
    p1->queueing(554,1);
    p1->queueing(553,4);
    p1->queueing(552,3);
    p1->display();
    cout << endl;
    cout << "--------------------" << endl;
    cout <<"Highest precision Value: " << p1->dequeing() << endl;
    cout <<"Highest precision Value: " << p1->dequeing()<< endl;
    cout << endl;
    cout << "--------------" << endl;
    p1->display();
    cout << "-----------------------" << endl;
    return 0;
}
