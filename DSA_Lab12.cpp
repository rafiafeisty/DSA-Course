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

class avl{
public:
    Node* root;
    avl(){
        root=NULL;
    }
    int get_height(Node* n){
        if(n==NULL){
            return 0;
        }
        else{
            int l=get_height(n->left)+1;
            int r=get_height(n->right)+1;
            int h=(l<r)?r:l;
            return h;
        }
    }
    int get_balance(Node* n){
        if(n==NULL){
            return 0;
        }
        else{
            int left=get_height(n->left);
            int right=get_height(n->right);
            int b=left-right;
            return b;
        }
    }
    Node* left_rotation(Node* n){
        Node* rightchild=n->right;
        rightchild->parent=n->parent;
        n->right=rightchild->left;
        if(rightchild->left!=NULL){
            rightchild->left->parent=n;
        }
        if(n->parent==NULL){
            root=rightchild;
        }
        else if(n->parent->right==n){
            n->parent->right=rightchild;
        }
        else{
            n->parent->left=rightchild;
        }
        rightchild->left=n;
        n->parent=rightchild;
        return rightchild;
    }
    void set_root(int x){
        if(root==NULL){
            root=new Node(x);
        }
    }
    Node* right_rotation(Node* n){
        Node* leftchild=n->left;
        leftchild->parent=n->parent;
        n->left=leftchild->right;
        if(leftchild->right!=NULL){
            leftchild->right!=NULL;
        }
        if(n->parent==NULL){
            root=leftchild;
        }
        else if(n->parent->right==n){
            n->parent->right=leftchild;
        }
        else{
            n->parent->left=leftchild;
        }
        leftchild->right=n;
        n->parent=leftchild;
        return leftchild;
    }
    Node* insertion(Node* n, int x, Node* parent=NULL){
        if(n==NULL){
           n=new Node(x);
           n->parent=parent;
           return n;
        }
        else{
            if(x>n->data){
                n->right=insertion(n->right,x,n);
            }
            else if(x<n->data){
                n->left=insertion(n->left,x,n);
            }
            else{
                cout << "Duplication" << endl;
                return n;
            }
        }
        int balance=get_balance(n);
        if(balance<-1 && x>n->right->data){
            return left_rotation(n);
        }
        if(balance> 1 && x<n->left->data){
            return right_rotation(n);
        }
        if(balance> 1 && x>n->left->data){
            n->left=left_rotation(n->left);
            return right_rotation(n);
        }
        if(balance<-1 && x<n->right->data){
            n->right=right_rotation(n->right);
            return left_rotation(n);
        }
        return n;
    }
    Node* searching(Node* n, int x){
        if(n==NULL){
            return NULL;
        }
        else{
            if(x>n->data){
                searching(n->right, x);
            }
            else if(x<n->data){
                searching(n->left,x);
            }
            else{
                return n;
            }
        }
    }
    Node* find_min(Node* n){
        if(n->left==NULL){
            return n;
        }
        else{
            return find_min(n->left);
        }
    }
    Node* deletion(Node* n, int x){
        if(n==NULL){
            return NULL;
        }
        else{
            Node* todel=searching(n,x);
            if(todel==NULL){
                cout << "No such value found" << endl;
                delete todel;
            }
            else if(todel->left==NULL && n->right==NULL){
                if(todel->parent->right==todel){
                    todel->parent->right=NULL;
                    delete todel;
                }
                else{
                    todel->parent->left=NULL;
                    delete todel;
                }
            }
            else if(todel->right!=NULL && todel->left==NULL){
                todel->right->parent=todel->parent;
                if(todel->parent->right==todel){
                    todel->parent->right=todel->right;
                    delete todel;
                }
                else{
                    todel->parent->left=todel->right;
                    delete todel;
                }
            }
            else if(todel->right==NULL && todel->left!=NULL){
                todel->left->parent=todel->parent;
                if(todel->parent->right==todel){
                    todel->parent->right=todel->left;
                    delete todel;
                }
                else{
                    todel->parent->left=todel->left;
                    delete todel;
                }
            }
            else{
                Node* ipre=find_min(n->right);
                todel->data=ipre->data;
                deletion(todel->right,ipre->data);
            }
            int balance=get_balance(n);
        if(balance<-1 && x>n->right->data){
            return left_rotation(n);
        }
        if(balance> 1 && x<n->left->data){
            return right_rotation(n);
        }
        if(balance> 1 && x>n->left->data){
            n->left=left_rotation(n->left);
            return right_rotation(n);
        }
        if(balance<-1 && x<n->right->data){
            n->right=right_rotation(n->right);
            return left_rotation(n);
        }
        return n;
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
    void inorder(Node* n){
        if(n==NULL){
            return;
        }
        else{
            inorder(n->left);
            cout << n->data << " ";
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
            cout << n->data << " ";
        }
    }
};

int main(){
    avl* t1=new avl();
    t1->set_root(5);
    t1->insertion(t1->root,4);
    t1->insertion(t1->root,3);
    t1->insertion(t1->root,2);
    t1->insertion(t1->root,8);
    t1->insertion(t1->root,7);
    t1->insertion(t1->root,6);
    t1->preorder(t1->root);
    cout << endl;
    t1->deletion(t1->root,3);
    t1->preorder(t1->root);
    return 0;
}
