#include<iostream>
using namespace std;

int vowelcounting(string a,char b, int &vowels, int index=0){
    if(!(index<=a.length())){
        return vowels;
    }
    else if(b=='A'||b=='a'||b=='e'||b=='E'||b=='i'||b=='I'||b=='O'||b=='o'||b=='u'||b=='U'){
        vowels++;
        int s=0;
         s+=vowelcounting(a,a[index+1],vowels,index+1);
        return s;
    }
    else{
            int s=0;
        s+=vowelcounting(a,a[index+1],vowels,index+1);
        return s;
    }
}
class Node2{
public:
    string issue;
    string name;
    Node2* next;
    Node2(string a, string b){
        issue=a;
        name=b;
    }
};

class Node{
public:
    string issue;
    string name;
    int id;
    string status;
    Node* next;
    Node(string a, string b, string c,int d){
        issue=a;
        name=b;
        status=c;
        id=d;
    }
};
class archive{
public:
    Node* head;
    archive(){
        head=NULL;
    }
    bool isempty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void add(Node* temp){
        if(isempty()){
            head=temp;
        }
        else{
            head->next=temp;
            head=temp;
        }
    }
    void retrieve(int id){
        Node* head1=head;
        int i=0;
        while(head1!=NULL){
            if(head1->id==id){
            cout << "Customer Name: " << head1->name << endl;
            cout << "Customer ID: " << head1->id << endl;
            cout << "Customer Issue: " << head1->issue << endl;
            Node* todelete=head1;
            head1=head1->next;
            delete todelete;
            break;

            }
            else{
                head1=head1->next;
            }
        }
    }
    void display(){
        Node* head1=head;
        while(head1!=NULL){
            cout << "Customer Name: " << head1->name << endl;
            cout << "Customer ID: " << head1->id << endl;
            cout << "Customer Issue: " << head1->issue << endl;
            cout << "---------------------------" << endl;
            head1=head1->next;
        }
    }
};

class inquiryQueue{
public:

    Node* fronting;
    Node* rear;
    inquiryQueue(){
        fronting=NULL;
        rear=NULL;
    }
    bool isempty(){
        if(fronting==NULL && rear==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void addqueue(string a, int c,string b){
        string s="waiting";
        Node* temp=new Node(a,b,s,c);
        if(isempty()){
            rear=temp;
            fronting=temp;
        }
        else{
            rear->next=temp;
            rear=temp;
        }
    }
    void processqueue(archive*& a1){
        if(isempty()){
            cout << "No Queue to be processed" << endl;
        }
        else{
            string s="completed";
            fronting->status=s;
            cout << "Customer Name: " << fronting->name << endl;
            cout << "Customer ID: " << fronting->id << endl;
            cout << "Customer Issue: " << fronting->issue << endl;
            cout << "Inquiry Status: " << fronting->status << endl;
            Node* todelete=fronting;
            if(fronting->next==NULL){
                fronting=NULL;
                rear=NULL;
               // a1->add(todelete);
            delete todelete;
            }
            else{
            fronting=fronting->next;
                //a1->add(todelete);
            delete todelete;
            }
        }
    }
    void display(){
        Node* head=fronting;
        while(head!=NULL){
            cout << "Customer Name: " << head->name << endl;
            cout << "Customer ID: " << head->id << endl;
            cout << "Customer Issue: " << head->issue << endl;
            cout << "Inquiry Status: " << head->status << endl;
            cout << "-------------------------" << endl;
            head=head->next;
        }

    }
};





class Stack{
public:
    Node2* head;
    Stack(){
        head=NULL;
    }
    bool isempty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void addissue(string a, string b){
        Node2* temp=new Node2(a,b);
        if(isempty()){
            head=temp;
        }
        else{
            temp->next=head;
            head=temp;
        }
    }
    void undo(){
        if(isempty()){
            cout << "No action has been entered" << endl;
        }
        else{
            cout << "Customer Name: " << head->name << endl;
            cout << "Issue Encountered: " << head->issue << endl;
            Node2* todelete=head;
            head=head->next;
            delete todelete;
        }
    }
    void display(){
        Node2* head1=head;
        while(head1!=NULL){
            cout << "Customer Name: " << head1->name << endl;
            cout << "Issue Encountered: " << head1->issue << endl;
            cout << "-------------------------" << endl;
            head1=head1->next;
        }
    }
};




int main(){
    string n;
    cout << "Enter a string for vowel counting: ";
    getline(cin,n);
    char ch=n[0];
    int counting=0;
  cout << vowelcounting(n,ch,counting) << endl;
inquiryQueue *q1=new inquiryQueue();

archive *a1=new archive();
while(1){
    string n1,n2;
    int n3;
    cout << "Enter customer Name: ";
    getline(cin,n1);
    cout << "Enter Customer Issue: ";
    getline(cin, n2);
    cout << "Enter Customer ID: ";
    cin >> n3;
    char ch;
    cout << "You want to enter more data?(y/n)";
    cin >> ch;
    cin.ignore();
    q1->addqueue(n1,n3,n2);
    if(ch=='y'){
        continue;
    }
        break;
}
cout << "----------------------------" << endl;
cout << "Completed Inquiry Detail" << endl;
q1->processqueue(a1);
cout << "-----------------------" << endl;
cout << "PENDING" << endl;
q1->display();
Stack* s1=new Stack();
//while(1){
//    string n1,n2;
//    cout << "Enter customer Name: ";
//    getline(cin,n1);
//    cout << "Enter Issue Encountered: ";
//    getline(cin, n2);
//    char ch;
//    cout << "You want to enter more data?(y/n)";
//    cin >> ch;
//    cin.ignore();
//    s1->addissue(n1,n2);
//    if(ch=='y'){
//        continue;
//    }
//        break;
//}
//cout << "-------------------------" << endl;
//cout << "UNDO ACTION" << endl;
//s1->undo();
//cout << "------------------------" << endl;
//cout << "ALL ISSUES FROM LATEST TO OLD" << endl;
//s1->display();
//a1->display();
//cout << "SPECIFIC USER" << endl;
//a1->retrieve(34);
//cout << "---------------------" << endl;
    return 0;
}
