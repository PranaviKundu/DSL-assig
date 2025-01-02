//linear probing:in case of collision(in hashing)-fills the next place if it is empty otherwise
//checks the next to next and so on, goes in circular form(last to first connected)

//for searching:linaer searching is not used, divide the number and find the remainder, search 
//the number till it is found, if not found in full array then not found

//fill the empty places with -1

#include <iostream>
#include <vector>
using namespace std;

// Define the size of the hash table
const int TABLE_SIZE = 10;

// Hash Table class
class HashTable {
private:
    vector<int> table;

public:
    // Constructor initializes the table with -1 (indicating empty)
    HashTable() {
        table.resize(TABLE_SIZE, -1);
    }

    // Hash function to determine the index
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    // Insert function to add an element to the table
    void insert(int key) {
        int index = hashFunction(key);

        // Linear probing in case of collision
        while (table[index] != -1) {
            cout << "Collision at index " << index << ", trying next index." << endl;
            index = (index + 1) % TABLE_SIZE; // Wrap around if needed
        }

        table[index] = key;
        cout << "Inserted " << key << " at index " << index << endl;
    }

    // Display the hash table
    void display() {
        cout << "Hash Table: ";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << table[i] << " ";  // Display -1 for empty slots
        }
        cout << endl;
    }

    // Search function to find an element in the table
    bool search(int key) {
        int index = hashFunction(key);
        int startIndex = index; // To prevent infinite loop

        while (table[index] != -1) {
            if (table[index] == key)
                return true;
            index = (index + 1) % TABLE_SIZE;

            // Stop searching if we have wrapped around to the start index
            if (index == startIndex)
                break;
        }
        return false;
    }

    // Read function to get input from the user
    void read() {
        int key;
        cout << "Enter the key to insert into the hash table: ";
        cin >> key;
        insert(key);
    }
};

// Main function to test the HashTable
int main() {
    HashTable hashTable;

    // Read input and insert into hash table
    hashTable.read();
    hashTable.read();

    // Display the hash table after insertion
    hashTable.display();

    // Search for a key
    int searchKey;
    cout << "Enter a key to search: ";
    cin >> searchKey;
    if (hashTable.search(searchKey)) {
        cout << "Key " << searchKey << " found in the hash table." << endl;
    } else {
        cout << "Key " << searchKey << " not found in the hash table." << endl;
    }

    return 0;
}




//vector<vector<int>>
//insert, read, display, search