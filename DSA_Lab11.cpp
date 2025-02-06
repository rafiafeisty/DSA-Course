#include<iostream>
using namespace std;

class Node{
public:
    int id;
    string name;
    string disease;
    Node* left;
    Node* right;
    Node(int a, string b, string c){
        id=a;
        name=b;
        disease=c;
        left=NULL;
        right=NULL;
    }
};

class Patient{
public:
    Node* root;
    Patient(){
        root=NULL;
    }
    void insertion(Node*& n, int x,string y, string z){
        if(n==NULL){
            Node* temp=new Node(x,y,z);
            n=temp;
            return;
        }
        else if(n->id<x){
            insertion(n->right,x,y,z);

        }
        else{
            insertion(n->left,x,y,z);
        }
    }
    void set_root(int x, string y, string z){
        if(root==NULL){
            root=new Node(x,y,z);
        }
    }
    void display(Node* n){
        cout << "Patient ID: " << n->id << endl;
        cout << "Patient Name: " << n->name << endl;
        cout << "Patient Disease: " << n->disease << endl;
        cout << "---------------------------------" <<endl;
    }
    void inorder(Node* n){
        if(n==NULL){
            return;
        }
        cout << "Patient ID: " << n->id << endl;
        cout << "Patient Name: " << n->name << endl;
        cout << "Patient Disease: " << n->disease << endl;
        cout << "---------------------------------" <<endl;
        inorder(n->left);
        inorder(n->right);
    }
    Node* searching(Node* n, int x){
        if(n==NULL){
            return NULL;
        }
        else if(n->id==x){
            return n;
        }
        else if(n->id<x){
            searching(n->right,x);
        }
        else{
            searching(n->left,x);
        }
    }
    Node* inoprc(Node* p){
        if(p->left==NULL){
            return p;
        }
        inoprc(p->left);
    }
    Node* deletion(Node* n, int x){
        Node* todel=searching(n,x);
        if(n==NULL){
            cout << "No such id found for deletion" << endl;
        }
        else if(n->id>x){
            n->left=deletion(n->left,x);
        }
        else if(n->id<x){
            n->right=deletion(n->right,x);
        }
        else{
            if(n->left==NULL && n->right==NULL){
                delete n;
                return NULL;
            }
            Node* pro=inoprc(n->right);
            n->id=pro->id;
            n->name=pro->name;
            n->disease=pro->disease;
            n->right=deletion(n->right, pro->id);
        }
        return n;
    }
    void descending(Node* ni){
        if(ni==NULL){
            return;
        }
        descending(ni->left);
        cout << "Patient ID: " << ni->id << endl;
        cout << "Patient Name: " << ni->name << endl;
        cout << "Patient Disease: " << ni->disease << endl;
        cout << "---------------------------------" <<endl;
        descending(ni->right);
    }
    int height(Node*n){
        if(n==NULL){
            return 0;
        }
        else{
            int right_data=height(n->right);
            int left_data=height(n->left);
            int h=(right_data<left_data)?left_data:right_data;
        return h++;
        }
    }
};

int main(){
    Patient *p1=new Patient();
    p1->set_root(23,"Liza","cancer");
    while(1){
        int n;
        string a,b;
        cout << "Enter the patient ID: ";
        cin >> n;
        cin.ignore();
        cout << "Enter the patient name: ";
        getline(cin,a);
        //cin.ignore();
        cout << "Enter the patient disease: ";
        getline(cin,b);
        p1->insertion(p1->root,n,a,b);
        char y;
        cout << "You want to enter more data?(y/n): ";
        cin >> y;
        if(y=='y'){
            continue;
        }
        else{
            break;
        }
    }
    p1->descending(p1->root);
    p1->deletion(p1->root,12);
    cout << endl << endl;
    p1->inorder(p1->root);
    cout <<"Height: " << p1->height(p1->root) << endl;
    return 0;
}
