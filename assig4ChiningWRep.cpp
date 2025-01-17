#include<bits/stdc++.h>
using namespace std;

vector<int> v(10, -1);

void insert(int n) {
    int idx = n % 10;
    while (v[#include<bits/stdc++.h>
using namespace std;

vector<int> v(10, -1);

void insert(int n) {
    int idx = n % 10;
    while (v[idx] != -1 && v[idx] != n) {
        idx = (idx + 1) % 10;
    }
    v[idx] = n;
    cout << "Inserted " << n << " at index " << idx << endl;
}

void display() {
    cout << "Hash Table: " << endl;
    for (int i = 0; i < 10; i++) {
        if (v[i] != -1)
            cout << "Index " << i << ": " << v[i] << endl;
        else
            cout << "Index " << i << ": Empty" << endl;
    }
}

void search(int n) {
    int idx = n % 10;
    int startIdx = idx;
    while (v[idx] != -1) {
        if (v[idx] == n) {
            cout << "Element " << n << " found at index " << idx << endl;
            return;
        }
        idx = (idx + 1) % 10;
        if (idx == startIdx)
            break;
    }
    cout << "Element " << n << " not found." << endl;
}

int main() {
    int menu;
    while (menu != 4) {
        cout << "Enter your choice (1->Insert  2->Display  3->Search  4->Exit): ";
        cin >> menu;
        if (menu == 1) {
            int n;
            cout << "Enter value you want to enter: ";
            cin >> n;
            insert(n);
        } else if (menu == 2) {
            cout << "Displaying the Hash table" << endl;
            display();
        } else if (menu == 3) {
            int n1;
            cout << "Enter value you want to search: ";
            cin >> n1;
            search(n1);
        } else if (menu == 4) {
            cout << "Successfully exited from program" << endl;
        } else {
            cout << "Enter valid option: ";
        }
    }
}idx] != -1 && v[idx] != n) {
        idx = (idx + 1) % 10;
    }
    v[idx] = n;
    cout << "Inserted " << n << " at index " << idx << endl;
}

void display() {
    cout << "Hash Table: " << endl;
    for (int i = 0; i < 10; i++) {
        if (v[i] != -1)
            cout << "Index " << i << ": " << v[i] << endl;
        else
            cout << "Index " << i << ": Empty" << endl;
    }
}

void search(int n) {
    int idx = n % 10;
    int startIdx = idx;
    while (v[idx] != -1) {
        if (v[idx] == n) {
            cout << "Element " << n << " found at index " << idx << endl;
            return;
        }
        idx = (idx + 1) % 10;
        if (idx == startIdx)
            break;
    }
    cout << "Element " << n << " not found." << endl;
}

int main() {
    int menu;
    while (menu != 4) {
        cout << "Enter your choice (1->Insert  2->Display  3->Search  4->Exit): ";
        cin >> menu;
        if (menu == 1) {
            int n;
            cout << "Enter value you want to enter: ";
            cin >> n;
            insert(n);
        } else if (menu == 2) {
            cout << "Displaying the Hash table" << endl;
            display();
        } else if (menu == 3) {
            int n1;
            cout << "Enter value you want to search: ";
            cin >> n1;
            search(n1);
        } else if (menu == 4) {
            cout << "Successfully exited from program" << endl;
        } else {
            cout << "Enter valid option: ";
        }
    }
}