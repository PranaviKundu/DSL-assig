//linear probing:in case of collision(in hashing)-fills the next place if it is empty otherwise
//checks the next to next and so on, goes in circular form(last to first connected)

//for searching:linaer searching is not used, divide the number and find the remainder, search 
//the number till it is found, if not found in full array then not found

//fill the empty places with -1


#include <iostream>
#include <vector>
using namespace std;

int TABLE_SIZE = 10;

class hashing {
private:
    vector<int> table;
public:
    hashing() {
        table.resize(TABLE_SIZE, -1);
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    // Check if the table is full
    bool isFull() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] == -1) {
                return false;  // There's at least one empty slot
            }
        }
        return true;  // No empty slots, table is full
    }

    void insert(int key) {
        if (isFull()) {
            cout << "Error: Hash table is full. Cannot insert more keys." << endl;
            return;
        }

        int index = hashFunction(key);
        while (table[index] != -1) {
            cout << "Collision at index " << index << ", therefore checking the next index." << endl;
            index = (index + 1) % TABLE_SIZE;
        }
        table[index] = key;
        cout << "Key " << key << " inserted at index " << index << endl;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << table[i] << " ";
        }
        cout << endl;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int startIndex = index;
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex) {
                break;  // Prevent infinite loop if the table is full
            }
        }
        return false;
    }

    void read() {
        int key;
        cout << "Enter the key you want to insert: ";
        cin >> key;
        insert(key);
    }

    int size() {
        int count = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != -1) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    hashing hashTable;

    // Inserting keys until the table is full
    for (int i = 0; i < 10; i++) {
        hashTable.read();
    }

    hashTable.display();

    // Try to insert one more key when the table is full
    hashTable.read();  // This will fail if the table is full

    int searchKey;
    cout << "Enter the key to search in the hash table: ";
    cin >> searchKey;
    if (hashTable.search(searchKey)) {
        cout << "Key " << searchKey << " found in the hash table." << endl;
    } else {
        cout << "Key " << searchKey << " not found in the hash table." << endl;
    }

    int load_factor = hashTable.size() / TABLE_SIZE;
    cout << "Load factor: " << load_factor << endl;

    return 0;
}
