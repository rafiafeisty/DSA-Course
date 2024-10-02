#include<iostream>
#include<string>
using namespace std;


class Stack{
public:
    char *arr;
    int arr_size;
    int top;
    Stack(int val){
        top=-1;
        arr_size=val;
        arr=new char[arr_size];
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(){
        if(top==arr_size){
            return true;
        }
        else{
            return false;
        }
    }
    bool Push(char val){
        if(isFull()){
            return false;
        }
        else{
            top++;
            arr[top]=val;
        return true;
        }

    }
    char Pop(){
        if(!isEmpty()){
            char a=arr[top];
            top--;
            return a;
        }
    }

    int size_array(){
        if(isEmpty()){
            cout << "Array is empty" << endl;
            return -1;
        }
        else{
        return top;
        }
    }

    void display(){
        for(int i=top; i>=0; i--){
            cout << arr[i] << endl;
        }
    }
};

class Node{
public:
    Node* next;
    char data;
    Node(char val){
        next=NULL;
        data=val;
    }
};

class List{
public:
    Node *head;
    int top;
    List(){
        top=-1;
        head=NULL;
    }
    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    bool Push(char val){
        Node *temp=new Node(val);
        if(isEmpty()){
            head=temp;
            top++;
            return true;
        }
        else{
            temp->next=head;
            head=temp;
            top++;
            return true;
        }
    }
    char Pop(){
        char temp=head->data;
        Node *todelete=head;
        head=head->next;
        delete todelete;
        return temp;
    }
    int size_list(){
        if(isEmpty()){
        return -1;
        }
        else{
            return top;
        }
    }
    void display(){
        Node* head1=head;
        while(head1!=NULL){
            cout << head1->data << endl;
            head1=head1->next;
        }
    }

};
void isBalanced(Stack *s1, string str) {
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            s1->Push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s1->isEmpty()) {
                cout << "Invalid sequence" << endl;
                return;
            }
            char top = s1->Pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                cout << "Invalid sequence" << endl;
                return;
            }
        }
    }

    if (!s1->isEmpty()) {
        cout << "Invalid sequence: Too many opening brackets" << endl;
    } else {
        cout << "Valid sequence" << endl;
    }
}

int main(){
    Stack *L1=new Stack(5);
    if(L1->isEmpty()){
        cout << "Array is Empty" << endl;
    }
    L1->Push('A');
    L1->Push('B');
    L1->Push('C');
    L1->Push('D');
    L1->Push('E');
    cout << L1->Pop() << endl << endl;
    L1->display();
    if(L1->isEmpty()){
        cout << "Array is Empty" << endl;
    }
    else{
        cout << "Array is not empty" << endl;
    }
    cout << "SIZE OF THE ARRAY: " << L1->size_array() << endl;
    cout << "---------------------" << endl;
    List *L2=new List();
    if(L2->isEmpty()){
        cout << "List is empty" << endl;
    }
    L2->Push('A');
    L2->Push('B');
    L2->Push('C');
    L2->Push('D');
    L2->Push('E');
    L2->Push('F');
    cout << "SIZE OF THE LIST: " << L2->size_list() << endl;
    cout << L2->Pop() << endl;
    cout << L2->Pop() << endl;
    cout << L2->Pop() << endl;
    cout << L2->Pop() << endl;
    cout << L2->Pop() << endl;
    cout << L2->Pop() << endl;
    cout << "-----------------" << endl;
    string str;
    cout << "Enter the bracket sequence: ";
    getline(cin,str);
    Stack *s1=new Stack(str.length());
    isBalanced(s1, str);
    return 0;
}
