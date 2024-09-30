#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int prn;
    string name;
    node *next;

public:
    node(int n, string s) {
        this->prn = n;
        this->name = s;
        this->next = NULL; // Initialize next to NULL
    }

    ~node() {
        int n = this->prn;
        string s = this->name;

        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }

        cout << "Data deleted is : " << n << " " << s << endl;
    }
};

int length(node *head) {
    int cnt = 0;
    node *temp = head;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void addpresident(node *&head, int n, string s) {
    node *temp = new node(n, s);
    if (head == NULL) {
        head = temp;
        return;
    }

    temp->next = head;
    head = temp;
}

void deletepresident(node *&head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void addsecretary(node *&head, int n, string s) {
    node *temp = new node(n, s);
    if (head == NULL) {
        head = temp;
        return;
    }

    node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = temp;
}

void deletesecretary(node *&head) {
    if (head == NULL) {
        cout << "No secretary to delete" << endl;
        return;
    }

    // If there is only one secretary
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    node *curr = head;
    node *prev = NULL;

    // Traverse to the last secretary
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL; // Disconnect the last node
    delete curr; // Delete the last secretary
}

void addmembers(node *&head, int n, string s) {
    node *temp = new node(n, s);
    if (head == NULL) {
        cout << "List is empty. Add a president first." << endl;
        delete temp; // Clean up the allocated memory
        return;
    }

    node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = temp; // Add the member at the end
}

void deleteMember(node *&head, int n) {
    if (head == NULL) {
        cout << "List is empty. No members to delete." << endl;
        return;
    }

    node *curr = head;
    node *prev = NULL;

    while (curr != NULL) {
        if (curr->prn == n) {
            if (prev == NULL) { // If it's the head node
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            cout << "Member with PRN " << n << " deleted." << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "Member with PRN " << n << " not found." << endl;
}

void display(node *head) {
    node *temp = head;
    while (temp != NULL) {
        cout << temp->prn << " " << temp->name << endl;
        temp = temp->next;
    }
}

bool ispresident(node *head) {
    return head != NULL; // True if there is at least one node
}

bool issecretary(node *head) {
    return head != NULL && head->next != NULL; // At least two nodes needed
}

int main() {
    node *linked_list = NULL;

    while (true) {
        cout << "MENU" << endl;
        cout << "Enter 1 for Adding/Changing President : " << endl;
        cout << "Enter 2 for Adding/Changing Secretary : " << endl;
        cout << "Enter 3 for Adding Members : " << endl;
        cout << "Enter 4 for Displaying list : " << endl;
        cout << "Enter 5 for Deleting a Member : " << endl; // New option
        cout << "Enter 0 to Exit" << endl;
        cout << endl;
        cout << "Enter your choice : " << endl;
        int choice;
        cin >> choice;

        // Input validation for choice
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore bad input
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (choice == 1) {
            if (linked_list == NULL) {
                int n; 
                string s;
                cout << "Enter prn number of president" << endl;
                cin >> n;
                cout << "Enter name of president" << endl;
                cin >> s;
                addpresident(linked_list, n, s);
            } else {
                int n; 
                string s;
                cout << "Enter prn number of new president" << endl;
                cin >> n;
                cout << "Enter name of new president" << endl;
                cin >> s;
                deletepresident(linked_list);
                addpresident(linked_list, n, s);
            }
        } else if (choice == 2) {
            if (!ispresident(linked_list)) {
                cout << "Enter president first" << endl;
                continue;
            }
            if (!issecretary(linked_list)) {
                int n; 
                string s;
                cout << "Enter prn number of secretary" << endl;
                cin >> n;
                cout << "Enter name of secretary" << endl;
                cin >> s;
                addsecretary(linked_list, n, s);
            } else {
                int n; 
                string s;
                cout << "Enter prn number of new secretary" << endl;
                cin >> n;
                cout << "Enter name of new secretary" << endl;
                cin >> s;
                deletesecretary(linked_list);
                addsecretary(linked_list, n, s);
            }
        } else if (choice == 3) {
            if (linked_list == NULL || !issecretary(linked_list)) {
                if (linked_list == NULL) cout << "Enter president" << endl;
                else cout << "Enter secretary" << endl;
            } else {
                int n; 
                string s;
                cout << "Enter prn number of member" << endl;
                cin >> n;
                cout << "Enter name of member" << endl;
                cin >> s;
                addmembers(linked_list, n, s);
            }
        } else if (choice == 4) {
            display(linked_list);
        } else if (choice == 5) { // Deleting a member
            if (linked_list == NULL) {
                cout << "List is empty. No members to delete." << endl;
            } else {
                int n;
                cout << "Enter prn number of member to delete" << endl;
                cin >> n;
                deleteMember(linked_list, n);
            }
        } else if (choice == 0) {
            cout << "Bie Bie" << endl;
            break;
        } else {
            cout << "Enter correct choice" << endl;
        }
    }
}
