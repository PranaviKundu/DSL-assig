//Pinnacle club
//Add and delete the member as well as president or even secretary.
//Compute total number of members of club.
//Display members
//Display list in reverse orderusing recursion.
//Two linkedlist exist for two divisions. Concaenate two list.
//write the c++ progam to maintain the list of its members using single linkedlist. Store student PRN and name


#include <iostream>
#include <string>

using namespace std;

struct Member {
    string name;
    int prn;
    Member* next;
};

class PinnacleClub {
private:
    Member* head;
    Member* president;
    Member* secretary;

    void displayReverseHelper(Member* node) {
        if (node == nullptr) return;
        displayReverseHelper(node->next);
        cout << "PRN: " << node->prn << ", Name: " << node->name << endl;
    }

public:
    PinnacleClub() : head(nullptr), president(nullptr), secretary(nullptr) {}

    // Add a member to the end of the list
    void addMember(const string& name, int prn) {
        Member* newMember = new Member{name, prn, nullptr};
        if (head == nullptr) {
            head = newMember;
        } else {
            Member* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newMember;
        }
    }

    // Delete a member by PRN
    void deleteMember(int prn) {
        Member* temp = head;
        Member* prev = nullptr;

        while (temp != nullptr && temp->prn != prn) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Member not found." << endl;
            return;
        }

        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        if (temp == president) president = nullptr;
        if (temp == secretary) secretary = nullptr;

        delete temp;
        cout << "Member deleted." << endl;
    }

    // Set president
    void setPresident(int prn) {
        Member* temp = head;
        while (temp != nullptr && temp->prn != prn) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            president = temp;
        } else {
            cout << "Member not found." << endl;
        }
    }

    // Set secretary
    void setSecretary(int prn) {
        Member* temp = head;
        while (temp != nullptr && temp->prn != prn) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            secretary = temp;
        } else {
            cout << "Member not found." << endl;
        }
    }

    // Compute total number of members
    int getTotalMembers() const {
        int count = 0;
        Member* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Display members
    void displayMembers() const {
        Member* temp = head;
        while (temp != nullptr) {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    // Display members in reverse order
    void displayReverse() const {
        displayReverseHelper(head);
    }

    // Concatenate two linked lists
    static Member* concatenate(Member* list1, Member* list2) {
        if (list1 == nullptr) return list2;
        Member* temp = list1;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = list2;
        return list1;
    }

    ~PinnacleClub() {
        while (head != nullptr) {
            Member* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PinnacleClub division1;
    PinnacleClub division2;

    // Add members to division 1
    division1.addMember("Alice", 101);
    division1.addMember("Bob", 102);
    division1.addMember("Charlie", 103);

    // Add members to division 2
    division2.addMember("David", 201);
    division2.addMember("Eve", 202);

    cout << "Division 1 members:" << endl;
    division1.displayMembers();

    cout << "Division 2 members:" << endl;
    division2.displayMembers();

    // Concatenate divisions
    Member* concatenatedList = PinnacleClub::concatenate(division1.head, division2.head);

    cout << "Concatenated list members:" << endl;
    PinnacleClub concatenatedClub;
    concatenatedClub.head = concatenatedList;
    concatenatedClub.displayMembers();

    // Display in reverse order
    cout << "Concatenated list in reverse order:" << endl;
    concatenatedClub.displayReverse();

    // Set president and secretary
    division1.setPresident(101);
    division1.setSecretary(102);
    cout << "President PRN: " << (division1.president ? division1.president->prn : -1) << endl;
    cout << "Secretary PRN: " << (division1.secretary ? division1.secretary->prn : -1) << endl;

    // Total members in concatenated club
    cout << "Total members in concatenated club: " << concatenatedClub.getTotalMembers() << endl;

    return 0;
}
