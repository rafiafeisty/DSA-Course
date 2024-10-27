#include<iostream>
using namespace std;

class CallNode{
public:
    int call_id;
    int customer_id;
    string call_time;
    string issue_type;
    string status;
    CallNode* next;
    CallNode(int a, int b, string c, string d, string e){
        call_id=a;
        customer_id=b;
        call_time=c;
        issue_type=d;
        status=e;
        next=NULL;
    }
};

class Call{
public:
    CallNode *fronting;
    CallNode *rear;
    Call(){
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
    int incomingCall(int a, int b, string c, string d){
        string val="waiting";
        CallNode *temp=new CallNode(a,b,c,d,val);
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
    void servedCall(){
        if(isempty()){
            cout << "No more calls" << endl;
            return;
        }
        else{
            string val="completed";
            fronting->status=val;
            cout << "CALL DETAILS" << endl;
            cout << "Call Id: " << fronting->call_id << endl;
            cout << "Customer Id: " << fronting->customer_id << endl;
            cout << "Call time: " << fronting->call_time << endl;
            cout << "Type Of Issue: " << fronting->issue_type << endl;
            cout << "Status: " << fronting->status << endl;
            CallNode* todelete=fronting;
            if(fronting->next==NULL){
                fronting=NULL;
                rear=NULL;
                delete todelete;
            }
            else{
                fronting=fronting->next;
                delete todelete;
            }

        }
    }
    void showCalls(){
        CallNode* head1=fronting;
        cout << "WAITING CALLs IN THE SYSTEM" << endl;
        while(head1!=NULL){
            cout << "Call Id: " << head1->call_id << endl;
            cout << "Customer Id: " << head1->customer_id << endl;
            cout << "Call time: " << head1->call_time << endl;
            cout << "Type Of Issue: " << head1->issue_type << endl;
            cout << "Status: " << head1->status << endl;
            cout << "----------------------------" << endl;
            head1=head1->next;
        }
    }
};

class FolderNode{
public:
    string folderName;
    int folderID;
    string creationDate;
    int sizes;
    int parentFolderId;
    int location;
    FolderNode* next;
    FolderNode(string a, int b, string c, int d, int e, int f){
        folderName=a;
        folderID=b;
        creationDate=c;
        sizes=d;
        parentFolderId=e;
        location=f;
        next=NULL;
    }
};


class Folder{
public:
    FolderNode *head;
    int current_location=0;
    Folder(){
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
    bool OpenFolder(string a, int b, string c, int d, int e){

        current_location++;
        FolderNode *temp=new FolderNode(a,b,c,d,e,current_location);
        if(isempty()){
            head=temp;
            return true;
        }
        else{
            current_location++;
            temp->next=head;
            head=temp;
            return true;
        }
    }
    void GoForward(){
        int loc=head->location;
        FolderNode *f1=head;
        int j=0;
        while(f1->location==(head->location+1)&& f1!=NULL){
        if(f1->location==(head->location+1)){
            break;
        }
            f1=f1->next;
        }
        if(f1==NULL){
                cout << "No folder found" << endl;
        }
        else{
                cout << "FORWARD FOLDER DETAILS" << endl;
            cout << "Folder Id: " << f1->next->folderID << endl;
            cout << "Folder Name: " << f1->next->folderName << endl;
            cout << "Creation Date: " << f1->next->creationDate << endl;
            cout << "Size: " << f1->next->sizes << "kb"<< endl;
            cout << "Folder Parent Id: " << f1->next->parentFolderId << endl;
            cout << "Current Location: " << f1->next->location << endl;
        }

    }


    void GoBack(){
        int loc=head->location;
        FolderNode *f1=head;
        int j=0;
        while(f1->location==(loc-1)){
            f1=f1->next;
        }
        if(f1==NULL){
                cout << "No folder found" << endl;
        }
        else{
                cout << "BACKWARD FOLDER DETAILS" << endl;
            cout << "Folder Id: " << f1->folderID << endl;
            cout << "Folder Name: " << f1->folderName << endl;
            cout << "Creation Date: " << f1->creationDate << endl;
            cout << "Size: " << f1->sizes << "kb"<< endl;
            cout << "Folder Parent Id: " << f1->parentFolderId << endl;
            cout << "Current Location: " << f1->location << endl;
        }

    }
    void navigation(){
        cout << "ALL FOLDER" << endl;
        FolderNode *head1=head;
        while(head1!=NULL){
            cout << "Folder Name: "<< head1->folderName << endl;
        cout <<  "Folder Id: "<<head1->folderID << endl;
        head1=head1->next;
        }

    }

};

int main(){
    Call *c1=new Call();
    c1->incomingCall(123, 789, "12:34","bank issue");
    c1->incomingCall(133, 889, "01:34","electrical issue");
    c1->incomingCall(163, 799, "02:34","home appliance issue");
    c1->servedCall();
    cout << "--------------------" << endl;
    c1->showCalls();
    delete c1;
    Folder *f1=new Folder();
    f1->OpenFolder("CS", 123,"12-12-24",12,56);
    f1->OpenFolder("Electronics", 133,"15-12-24",16,56);
    f1->OpenFolder("Basics", 153,"19-12-24",22,76);
    f1->GoBack();
cout << "----------------" << endl;
f1->navigation();
cout << "----------------" << endl;
f1->GoForward();
    return 0;
}
