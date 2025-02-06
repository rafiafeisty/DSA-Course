//#include<iostream>
//using namespace std;
//
//int multiplication(int a, int b){
//    if(a==0||b==0){
//        return 0;
//    }
//    else if(b==1){
//        return (a*b);
//    }
//    else{
//        int result= multiplication(a,b-1);
//        return (result+a);
//    }
//}
//
//int power(int a, int p){
//    if(p==1){
//        return a;
//    }
//    else{
//        int s=power(a,p-1);
//        return a*s;
//    }
//}
#include<iostream>
using namespace std;


class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int data){
        val=data;
        next=NULL;
        prev=NULL;
    }
};


class Queue{
public:
    Node *rear;
    Node*fronting;
    Queue(){
        rear=NULL;
        fronting=NULL;
    }
    bool isempty(){
        if(rear==NULL&& fronting==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    bool enque(int x){
        Node* temp=new Node(x);
        if(isempty()){
            rear=temp;
            fronting=temp;
            return true;
        }
        else{
            rear->next=temp;
            temp->prev=rear;
            rear=temp;
            return false;
        }
    }
    int dequeing(){
        if(isempty()){
            return -1;
        }
        else{
            int x=fronting->val;
            Node* todelete=fronting;
            fronting->prev=fronting->next;
            fronting=fronting->next;
            delete todelete;
            return x;
        }
    }
    void display(){
        Node* head1=fronting;
        while(head1!=NULL){
            cout << head1->val << " ";
            head1=head1->next;
        }
        cout << endl;
    }
};
//
//void removing(Node* &head){
//    if(head==NULL){
//        return;
//    }
//    else{
//        if(head->val<0){
//            Node* todelete=head;
//            head->prev=head->next;
//            head=head->next;
//            delete todelete;
//            removing(head);
//        }
//        else{
//            removing(head->next);
//        }
//    }
//}
//bool comparison(Node*& head1,Node*& head2){
//    bool found=false;
//    if(head1==NULL&&head2==NULL){
//        return true;
//    }
//    if(head1!=NULL && head2!=NULL){
//    if(head1->val==head2->val){
//        found=comparison(head1->next, head2->next);
//        }
//    else{
//        return false;
//    }
//    }
//    return found;
//}
//
//class NodeList{
//public:
//    int data;
//    NodeList* next;
//    NodeList(int val){
//        data=val;
//        next=NULL;
//    }
//};
//
//
//class List{
//public:
//    NodeList* head;
//    List(){
//        head=NULL;
//    }
//    bool isEmpty(){
//        if(head==NULL){
//            return true;
//        }
//        else{
//            return false;
//        }
//    }
//    bool inserting(int x){
//        NodeList* temp=new NodeList(x);
//        if(isEmpty()){
//            head=temp;
//        }
//        else{
//            temp->next=head;
//            head=temp;
//        }
//    }
//    void display(){
//        NodeList* head1=head;
//        while(head1!=NULL){
//            cout << head1->data << " ";
//        }
//    }
//};
//
//
//int main(){
//    cout << "MULTIPLICATION RESULT" << endl;
//    cout << multiplication(3,4) << endl;
//    cout << "POWER RESULT" << endl;
//    cout << power(5,3) << endl;
//    cout << "REMOVING RESULT" << endl;
//    Queue *s1=new Queue();
//    s1->push(3);
//    s1->push(-5);
//    s1->push(6);
//    s1->push(-7);
//    //removing(s1->fronting);
//    //s1->display();
//    //cout << s1->pop();
//    Queue *s2=new Queue();
//    s2->push(3);
//    s2->push(-5);
//    s2->push(6);
//   s2->push(-8);
//    cout << endl;
//    if(comparison(s1->fronting,s2->fronting)){
//        cout << "Identical Queus" << endl;
//    }
//    else{
//        cout << "Not identical" << endl;
//    }
//    return 0;
//}
//
//#include <iostream>
//using namespace std;
//
//
//struct Node {
//    int data;
//    int precedence;
//    Node* next;
//};
//
//class PriorityQueue {
//
//public:
//     Node* head;
//    PriorityQueue() : head(NULL) {}
//
//    ~PriorityQueue() {
//        while (head != NULL) {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//
//    void enqueue(int data, int precedence) {
//        Node* newNode = new Node;
//        newNode->data = data;
//        newNode->precedence = precedence;
//        newNode->next = NULL;
//
//        if (head == NULL || precedence > head->precedence) {
//            newNode->next = head;
//            head = newNode;
//        } else {
//            Node* current = head;
//            while (current->next != NULL && current->next->precedence >= precedence) {
//                current = current->next;
//            }
//            newNode->next = current->next;
//            current->next = newNode;
//        }
//    }
//
//    int dequeue() {
//        if (head == NULL) {
//            std::cerr << "Priority queue is empty!" << std::endl;
//            return -1;
//        }
//
//        int data = head->data;
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//        return data;
//    }
//
//    void printQueue() {
//        Node* current = head;
//        while (current != NULL) {
//            std::cout << "Data: " << current->data << ", Precedence: " << current->precedence << std::endl;
//            current = current->next;
//        }
//    }
//};
//void sorting(Node* head) {
//    Node* head1 = head;
//    while (head1 != NULL) {
//        Node* temp = head1->next;
//        while (temp != NULL) {
//            if (head1->precedence > temp->precedence) {
//                int tempPrecedence = temp->precedence;
//                int tempData = temp->data;
//                temp->precedence = head1->precedence;
//                temp->data = head1->data;
//                head1->precedence = tempPrecedence;
//                head1->data = tempData;
//            }
//            temp = temp->next;
//        }
//        head1 = head1->next;
//    }
//}
//
//
//int main() {
//    PriorityQueue pq;
//
//    pq.enqueue(1, 3);
//    pq.enqueue(2, 1);
//    pq.enqueue(3, 2);
//    pq.enqueue(4, 4);
//
//    //pq.printQueue();
//
////    std::cout << "Dequeued: " << pq.dequeue() << std::endl;
//  //  std::cout << "Dequeued: " << pq.dequeue() << std::endl;
//
//    //pq.printQueue();
//    sorting(pq.head);
//    pq.printQueue();
//
//    return 0;
//}
//#include<iostream>
//#include<stack>
//using namespace std;
//
//class Node{
//public:
//    int data;
//    Node*next;
//    Node(int val){
//        data=val;
//        next=NULL;
//    }
//};
//
//class Stack{
//public:
//    Node* head;
//    int sizes;
//    Stack(int s){
//        sizes=s;
//        head=NULL;
//    }
//    bool isempty(){
//        if(head==NULL){
//            return true;
//        }
//        else{
//            return false;
//        }
//    }
//    void push(int x){
//        Node* temp=new Node(x);
//        if(isempty()){
//            head=temp;
//        }
//        else{
//            temp->next=head;
//            head=temp;
//        }
//    }
//        int pop(){
//            if(isempty()){
//                return 0;
//            }
//            else{
//                int temp=head->data;
//                Node *todelete=head;
//                head=head->next;
//                delete todelete;
//                return temp;
//            }
//        }
//        void display(){
//            Node* head1=head;
//            while(head1!=NULL){
//                cout << head->data << " ";
//                head1=head1->next;
//            }
//        }
//    };
int main(){
//    int n=29;
//    Stack s(10);
//    while(n>0){
//        s.push(n%2);
//        n=n/2;
//    }
//    while(!s.isempty()){
//        cout << s.pop() << "\t";
//    }
//    return 0;
int n=5;
Queue *q=new Queue();
q->enque(3);
q->enque(5);
for(int i=0; i<n; i++){
    int a=q->dequeing();
    cout << a << endl;
    int b=q->fronting->val;
    q->enque(a+b);
}

}
