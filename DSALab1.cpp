#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<string>

using namespace std;
int sizes=8;
int *arrays=new int[sizes];
int indexs=0;

void display(){
    for(int i=0; i<sizes; i++){
        cout << arrays[i] << " ";
    }
}

bool backwards(){
    if(indexs==0){
        return false;
    }
    else{
        return true;
    }
}


bool fronts(){
    if(indexs==sizes){
        return false;
    }
    else{
        return false;
    }
}

void inserting(){
    if(indexs==0){
        int n;
    cout << "Enter a Value: ";
    cin >> n;
        arrays[0]=n;
        indexs++;
        cout << endl << "Value inserted successfully" << endl;
        display();
    }
    else if(indexs==sizes){
        cout << "array is completely Filled";
    }
    else{
        int n;
    cout << "Enter a Value: ";
    cin >> n;
        for(int i=indexs; i>0; i--){
            arrays[i]=arrays[i-1];
        }
        arrays[0]=n;
        indexs++;
        cout << endl << "Value inserted successfully" << endl;
        display();
    }
}

void update(){
    int n;
    cout << "Enter the index number: ";
    cin >> n;
    if(n<0 || n>sizes){
        cout << "Invalid Index Number";
        return;
    }
    else{
        int value;
    cout << "Enter the value: ";
    cin >> value;
    arrays[n]=value;
    cout << endl << "Value updated successfully" << endl;
    display();
    }
}

void searching(){
    int n;
    cout << "Enter a value to find: ";
    cin >> n;
    for(int i=0; i<sizes; i++){
        if(n==arrays[i]){
            cout << "The value "<<n << " is at the index " << i << endl;
            return;
                   }
    }
    cout << "There is no such value in the array" << endl;
}

void index_at(){
    int n;
    cout << "Enter the Index Number(0-7): ";
    cin >> n;
    if(n<0||n>sizes-1){
        cout << "Invalid Number";
    }
    else{
            cout << arrays[n] << endl;
    }
}

void removing(){
    int n;
    cout << "Enter a value to remove: ";
    cin >> n;
    for(int i=0; i<sizes; i++){
        if(n==arrays[i]){
            if(i==0){
                    cout << endl << "Value deleted successfully" << endl;
                    display();
                for(int i=0; i<sizes-1; i++){
                    arrays[i]=arrays[i+1];
                }
                sizes--;
            }
            else{
                cout << endl << "Value deleted successfully" << endl;
                display();
                for(int j=i; j<sizes-1; j++){
                    arrays[j]=arrays[j+1];
                }
                sizes--;
            }
        }
    }
}

int main(){
   here: system("cls");
    cout << "Press 1 to insert a value in an array" << endl;
    cout << "Press 2 to remove a value in an array" << endl;
    cout << "Press 3 to find a value in an array" << endl;
    cout << "Press 4 to find an index in an array"<< endl;
    cout << "Press 5 to update a value in an array" << endl;
    cout << "Press 6 to display an array"<< endl;
    cout << "Press 7 to exit" << endl;
    int n;
    cout << "Enter your choice: ";
    cin >> n;
    system("cls");
    switch(n){
    case 1:
        {
            system("cls");
            inserting();
            char yes;
            cout << endl;
            cout << "Press y if you want to go back: ";
            cin >> yes;
            switch(yes){
            case 'y':{
                goto here;
                break;
            }
            }
            break;
        }
    case 2:
        {
            system("cls");
            removing();
            char yes;
            cout << endl;
            cout << "Press y if you want to go back: ";
            cin >> yes;
            switch(yes){
            case 'y':{
                goto here;
                break;
            }
            }
            break;
        }
    case 3:
        {
            system("cls");
            searching();
            char yes;
            cout << endl;
            cout << "Press y if you want to go back: ";
            cin >> yes;
            switch(yes){
            case 'y':{
                goto here;
                break;
            }
            }
            break;
        }
    case 4:
        {
            system("cls");
            index_at();
            char yes;
            cout << endl;
            cout << "Press y if you want to go back: ";
            cin >> yes;
            switch(yes){
            case 'y':{
                goto here;
                break;
            }
            }
            break;
        }
    case 5:
        {
            system("cls");
            update();
            char yes;
            cout << endl;
            cout << "Press y if you want to go back: ";
            cin >> yes;
            switch(yes){
            case 'y':{
                goto here;
                break;
            }
            }
            break;
        }
    case 6:
        {
            system("cls");
            display();
            char yes;
            cout << endl;
            cout << "Press y if you want to go back: ";
            cin >> yes;
            switch(yes){
            case 'y':{
                goto here;
                break;
            }
            }
            break;
        }
    case 7:
        {
            system("cls");
            delete [] arrays;
            exit;
        }
    }
}
