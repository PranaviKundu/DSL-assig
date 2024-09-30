#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int prn;
    string name;
    node * next;

    public:
    node(int n, string s){
        this->prn = n;
        this->name = s;
    }

    ~node(){
        int n = this->prn;
        string s= this->name;

        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }

        cout<<"Data deleted is : "<<n<<" "<<s<<endl;

    }
};

int length(node * head){
    int cnt = 0;
    node * temp = head;
    while(temp != NULL){
        cnt++;
        temp=temp->next;
    }

    return cnt;
}

void addpresident(node *&head,int n, string s){
    node * temp = new node(n,s);
    if(head == NULL){
        head = temp;
        return;
    }

    temp->next=head;
    head=temp;
}

void deletepresident(node * &head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    node * temp = head;
    head = head->next;
    temp->next=NULL;
    delete temp;

}

void addsecretary(node * &head, int n, string s){
    node * temp = new node(n,s);
    if(head == NULL){
        head = temp;
        return;
    }

    node * curr = head;
    while(curr->next!= NULL){
        curr=curr->next;
    }

    curr->next = temp;
}

void deletesecretary(node *&head){
    node * curr = head;
    node * prev = NULL;

    int posi = length(head);
    int cnt = 0;
    while(cnt<posi){
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;

}

void addmembers(node * &head, int n, string s){
    node * curr=head;
    node * prev=NULL;

    int posi = length(head);
    int cnt = 0;
    while(cnt<posi-1){
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    node * temp = new node(n,s);
    prev->next = temp;
    temp->next = curr;
}

void display(node * head){
    node * temp = head;
    while(temp != NULL){
        cout<<temp->prn<<" "<<temp->name<<endl;
        temp=temp->next;
    }
}
bool ispresident(node * head){
    int len = length(head);
    if(len<1) return false;
    return true;
}
bool issecretary(node * head){
    int len = length(head);
    if(len<2) return false;
    else return true; 
}

int main(){
    node * linked_list = NULL;
    
    while(true){
        cout<<"MENU"<<endl;
        cout<<"Enter 1 for Adding/Changing President : "<<endl;
        cout<<"Enter 2 for Adding/Changing Secretary : "<<endl;
        cout<<"Enter 3 for Adding Members : "<<endl;
        cout<<"Enter 4 for Displaying list : "<<endl;
        cout<<"Enter 0 to Exit"<<endl;
        cout<<endl;
        cout<<"Enter your choice : "<<endl;
        int choice; cin>>choice;

        if(choice == 1){
            if(linked_list == NULL){
                int n; 
                string s;
                cout<<"Enter prn number of president"<<endl;
                cin>>n;
                cout<<"Enter name of president"<<endl;
                cin>>s;
                addpresident(linked_list,n,s);
            }else{
                int n; 
                string s;
                cout<<"Enter prn number of new president"<<endl;
                cin>>n;
                cout<<"Enter name of new president"<<endl;
                cin>>s;
                deletepresident(linked_list);
                addpresident(linked_list,n,s);
            }
        }else if(choice == 2){
            if(ispresident==false){
                cout<<"Enter president first"<<endl;
                continue;
            }
            if(issecretary(linked_list)==false){
                int n; 
                string s;
                cout<<"Enter prn number of secretary"<<endl;
                cin>>n;
                cout<<"Enter name of secretary"<<endl;
                cin>>s;
                addsecretary(linked_list,n,s);
            }else{
                int n; 
                string s;
                cout<<"Enter prn number of new secretary"<<endl;
                cin>>n;
                cout<<"Enter name of new secretary"<<endl;
                cin>>s;
                deletesecretary(linked_list);
                addsecretary(linked_list,n,s);
            }
        }else if(choice == 3){
            if(linked_list == NULL || !issecretary(linked_list)){
                if(linked_list == NULL) cout<<"Enter president"<<endl;
                else cout<<"Enter secretary"<<endl;
            }else{
                int n; 
                string s;
                cout<<"Enter prn number of member"<<endl;
                cin>>n;
                cout<<"Enter name of member"<<endl;
                cin>>s;
                addmembers(linked_list,n,s);
            }
        }else if(choice == 4){
            display(linked_list);
        }else if(choice == 0){
            cout<<"Bie Bie"<<endl;
            break;
        }else{
            cout<<"Enter correct choice"<<endl;
        }
    }
}