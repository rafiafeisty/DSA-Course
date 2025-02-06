#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
        parent=NULL;
    }
};

class bst{
public:
    Node* root;
    bst(){
        root=NULL;
    }
    void set_root(int x){
        if(root==NULL){
            Node* temp=new Node(x);
            root=temp;
        }
    }
    Node* insertion(Node* n, int x, Node* parent=NULL){
        if(n==NULL){
            n=new Node(x);
            n->parent=parent;
            return n;
        }
        else if(n->data<x){
            n->right=insertion(n->right,x,n);
        }
        else if(n->data>x){
            n->left=insertion(n->left,x,n);
        }
        else{
            cout << "Duplication" << endl;
            return NULL;
        }
    }
    void preorder(Node* n){
        if(n==NULL){
            return;
        }
        else{
            cout << n->data << " ";
            preorder(n->left);
            preorder(n->right);
        }
    }
    int counting(Node* n, int maximum, int minimum){
        if(n==NULL){
            return 0;
        }
        else{
            int counter=counting(n->left,maximum,minimum);
            int counter2=counting(n->right,maximum,minimum);
            int total=counter2+counter;
            if(n->data>=minimum && n->data<=maximum){
                total++;
            }
            return total;
        }
    }
    void insertionsimpleleft(Node* n,int x){
        Node* temp=new Node(x);
        n->left=temp;
    }
    void insertionright(Node* n, int x){
        Node* temp=new Node(x);
        n->right=temp;
    }
    int sum(Node* n){
        if(n==NULL){
            return 0;
        }
        int l=sum(n->left);
        int r=sum(n->right);
        int total=l+r;
        int temp=n->data;
        n->data=total;
        return temp+total;
    }
};
int main(){
    bst* b1=new bst();
    b1->set_root(10);
    b1->insertion(b1->root,5);
    b1->insertion(b1->root,1);
    b1->insertion(b1->root,50);
    b1->insertion(b1->root,40);
    b1->insertion(b1->root,100);
    cout << "TREE DISPLAY IN PREORDER" << endl;
    b1->preorder(b1->root);
    cout << endl;
    cout << "TASK 2" << endl << endl;
    int maxi, mini;
    cout << "Enter the maximum limit for the counting: ";
    cin >> maxi;
    cout << "Enter the minimum limit for counting: ";
    cin >> mini;
    cout << endl;
    cout << "Total Nodes in range: " << b1->counting(b1->root,maxi,mini) << endl;
    cout << "----------------------------------" << endl;
//    bst* b2=new bst();
//    b2->set_root(1);
//    b2->insertion(b2->root,2);
//    b2->insertion(b2->root,4);
//    b2->insertion(b2->root,3);
//    b2->insertion(b2->root,5);
//    b2->insertion(b2->root,7);
//    b2->insertion(b2->root,8);
//    b2->insertion(b2->root,6);
//    b2->preorder(b2->root);
//    cout << endl;
//    b2->sum(b2->root);
//    b2->preorder(b2->root);
//    return 0;
//}
