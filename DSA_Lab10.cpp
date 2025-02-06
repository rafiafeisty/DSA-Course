#include<iostream>
using namespace std;

class Node{
public:
    int id;
    string name;
    string disease;
    Node* left;
    Node* right;
    Node* parent;
    Node(int a, string b, string c){
        id=a;
        name=b;
        disease=c;
        left=NULL;
        right=NULL;
        parent=NULL;
    }
};

class Patient{
public:
    Node* root;
    Patient(){
        root=NULL;
    }
    void bst_insertion(Node*& c, int x, string y, string z){
        if(c==NULL){
            Node* temp=new Node(x,y,z);
            c=temp;
            return;
        }
        else{
            if(c->id<x){
                bst_insertion(c->right,x,y,z);
            }
            if(c->id>x){
                bst_insertion(c->left,x,y,z);
            }
        }
    }
    void insert_root(int x, string y, string z){
        if(root==NULL){
            Node* temp=new Node(x,y,z);
            root=temp;
        }
    }
    void set_parent(Node* c, int x, string y, string z){
        Node* temp=new Node(x,y,z);
        c->parent=temp;
    }
    Node* get_root(){
        if(root!=NULL){
            Node* temp=root;
            return temp;
        }
    }
    void display(Node* nodes){
        cout << "Patient ID: " << nodes->id << endl;
        cout << "Patient Name: " << nodes->name << endl;
        cout << "Patient Disease: " << nodes->disease << endl;
        cout << "--------------------------------" << endl;
    }
    void bstsearch(Node* n,int x){
        if(n==NULL){
            cout << "There is no patient with this id" << endl;
            return;
        }
        else{
            if(n->id==x){
        cout << "Patient ID: " << n->id << endl;
        cout << "Patient Name: " << n->name << endl;
        cout << "Patient Disease: " << n->disease << endl;
        cout << "-----------------------------" << endl;
            }
            if(n->id>x){
                bstsearch(n->left,x);
            }
            if(n->id<x){
                bstsearch(n->right,x);
            }
        }
    }
    void maximum(Node* n){
        if(n->right==NULL){
        cout << "Patient ID: " << n->id << endl;
        cout << "Patient Name: " << n->name << endl;
        cout << "Patient Disease: " << n->disease << endl;
        cout << "-----------------------------" << endl;
        }
        else{
            maximum(n->right);
        }
    }
    Node* inorderpre(Node* ni){
        ni=ni->left;
        while(ni->right!=NULL){
            ni=ni->right;
        }
        return ni;
    }
    Node* deletion(Node* n, int x){
        if(n==NULL){
            return NULL;
        }
        else if(n->id>x){
            n->left=deletion(n->left,x);
        }
        else if(n->id<x){
            n->right=deletion(n->right,x);
        }
        else{
            if(n->right==NULL && n->left==NULL){
                delete n;
                return NULL;
            }
            Node* ipre=inorderpre(n);
            n->id=ipre->id;
            n->name=ipre->name;
            n->disease=ipre->disease;
            n->left=deletion(n->left,ipre->id);
        }
        return n;
    }
};

void preorder(Node* n){
    if(n==NULL){
        return;
    }
    else{
        cout << "Patient ID: " << n->id << endl;
        cout << "Patient Name: " << n->name << endl;
        cout << "Patient Disease: " << n->disease << endl;
        cout << "-----------------------------" << endl;
        preorder(n->left);
        preorder(n->right);
    }
}

void inorder(Node* n){
    if(n==NULL){
        return;
    }
    else{
        inorder(n->left);
        cout << "Patient ID: " << n->id << endl;
        cout << "Patient Name: " << n->name << endl;
        cout << "Patient Disease: " << n->disease << endl;
        cout << "-----------------------------" << endl;
        inorder(n->right);
    }
}

void postorder(Node* n){
    if(n==NULL){
        return;
    }
    else{
        postorder(n->left);
        postorder(n->right);
        cout << "Patient ID: " << n->id << endl;
        cout << "Patient Name: " << n->name << endl;
        cout << "Patient Disease: " << n->disease << endl;
        cout << "-----------------------------" << endl;
    }
}

int main(){
    Patient* p=new Patient();
    p->insert_root(23,"Diana","Cancer");
    Node* root=p->root;
    p->bst_insertion(p->root,25,"Liza","Constipation");
    p->bst_insertion(p->root,20,"Albert","Appendix");
    int ch;
    cout << "Press 1 to execute preorder"<< endl;
    cout << "Press 2 to execute postorder" << endl;
    cout << "Press 3 to execute inorder" << endl;
    cout << "Enter your choice: ";
    cin >> ch;
    cout << endl;
    switch(ch){
    case 1:{
        preorder(p->root);
        break;
    }
    case 2:{
        postorder(p->root);
        break;
    }
    case 3:{
        inorder(p->root);
        break;
    }
    }
    cout << endl;
    int n;
    cout<< "Enter an id to find the patient: ";
    cin >> n;
    p->bstsearch(p->root,n);
    cout << endl;
    cout << "PATIENT WITH MAXIMUM ID" << endl;
    p->maximum(p->root);
    cout << endl;
    cout << "DELETION" << endl;
    p->deletion(p->root,25);
    inorder(p->root);
    return 0;
}
