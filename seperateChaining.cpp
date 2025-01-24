#include<iostream>
#include<string>
#include<cmath>

using namespace std;

const int Table_size =13;
class Node{
    public:
        string word;
        string meaning;
        Node* next;

        Node(string w, string m){
            word= w;
            meaning=m;
            next = nullptr;
        }
};

int hashFunction(string word){
    int hashValue =0;
    int length = word.length();
    for(int i=0;i<length;i++){
        char ch =word[length-i-1]
        hashValue += int (ch) * pow(10,i);
    }
    return hashValue%Table_size;
}
void insert(Node* hashTable[],string word, string meaning){
    int index = hashFunction(word);
    Node * newNode = new Node(word, meaning);
    if(hashTable[index]== nullptr){
        hashTable[index]=newNode;
    }
    else{
        newNode->next=hashTable[index];
        hashTable[index]=newNode;
    }
}
string search(Node* hashTable[],string word){
    int index = hashFunction(word);
    Node * temp = hashTable[index];
    while(temp!=nullptr){
        if(temp->word == word){
            return temp->meaning;
        }
        temp= temp->next;
    }
    return "Word not found";
}
void deleteWord(Node * hashTable[], string word){
    int index=hashFunction(word);
    Node * temp =hashTable[index];
    node* prev = nullptr;
    while(temp!=nullptr){
        if(temp->word == word){
            if(prev ==nullptr){
                hashTable[index]=temp->next;
            }
            else{
                prev->next=temp->next;
            }
            delete temp;
            cout<<"Word '"<<word<<"' deleted."<<endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout<<"Word not found!"<<endl;
}
void display(Node * hashTable[]){
    bool isEmpty = true;
    for(int i=0;i<Table_size;i++){
        if(temp == nullptr){
            cout<<"Empty";
        }
        else{
            isEmpty= false;
            while(temp!=nullptr){
                cout<<temp->word<<":"<<temp->meaning<<endl;
                temp = temp->next;
            }
        }
        cout<<endl;
    }
    if(isEmpty){
        cout<<"The dictionary is empty!"<<endl;
    }
}

int main(){
    Node * hashTable[Table_size]={nullptr};
    insert(hashTable, "AIT", "Army Institute of technology, Pune.");
    insert(hashTable, "TIA", "CAn be name of a girl.");
    insert(hashTable, "apple", "A fruit that is typically red or green.");
    insert(hashTable, "banana", "A long yellow fruit.");
    insert(hashTable, "grape", "A small, round, purple or green fruit.");
    insert(hashTable, "mango", "A tropical fruit with a sweet taste.");

    cout << "Meaning of 'AIT': " << search(hashTable, "AIT") << endl;
    cout << "Meaning of 'apple': " << search(hashTable, "apple") << endl;
    cout << "Meaning of 'grape': " << search(hashTable, "grape") << endl;
    cout << "Meaning of 'orange': " << search(hashTable, "orange") << endl;

    cout << "\nDictionary Contents:" << endl;
    display(hashTable);

    deleteWord(hashTable, "banana");

    cout << "\nDictionary after deletion:" << endl;
    display(hashTable);

    return 0;

}


















// #include <iostream>
// #include <string>
// #include <cmath>
// using namespace std;

// // Define the hash table size (changed to 13)
// const int TABLE_SIZE = 13;

// // Define Node class to store word, meaning, and the next pointer
// class Node {
// public:
//     string word;
//     string meaning;
//     Node* next;

//     Node(string w, string m) {
//         word = w;
//         meaning = m;
//         next = nullptr;
//     }
// };

// // Modified hash function
// int hashFunction(string word) {
//     int hashValue = 0;
//     int length = word.length();

//     // Iterate through each character from right to left
//     for (int i = 0; i < length; i++) {
//         char ch = word[length - i - 1]; // Start from the last character
//         hashValue += int(ch) * pow(10, i); // Multiply ASCII value by 10^i
//     }

//     // Return hash value modulo table size (13)
//     return hashValue % TABLE_SIZE;
// }

// // Function to insert a word and its meaning into the dictionary
// void insert(Node* hashTable[], string word, string meaning) {
//     int index = hashFunction(word);
//     Node* newNode = new Node(word, meaning);

//     if (hashTable[index] == nullptr) {
//         // If the bucket is empty, place the node there
//         hashTable[index] = newNode;
//     } else {
//         // Otherwise, add the node at the beginning of the linked list
//         newNode->next = hashTable[index];
//         hashTable[index] = newNode;
//     }
// }

// // Function to search for a word and its meaning in the dictionary
// string search(Node* hashTable[], string word) {
//     int index = hashFunction(word);
//     Node* temp = hashTable[index];

//     while (temp != nullptr) {
//         if (temp->word == word) {
//             return temp->meaning;
//         }
//         temp = temp->next;
//     }
//     return "Word not found";
// }

// // Function to delete a word from the dictionary
// void deleteWord(Node* hashTable[], string word) {
//     int index = hashFunction(word);
//     Node* temp = hashTable[index];
//     Node* prev = nullptr;

//     while (temp != nullptr) {
//         if (temp->word == word) {
//             if (prev == nullptr) {
//                 // Word is the first node in the list
//                 hashTable[index] = temp->next;
//             } else {
//                 // Word is somewhere after the first node
//                 prev->next = temp->next;
//             }
//             delete temp;  // Free memory
//             cout << "Word '" << word << "' deleted." << endl;
//             return;
//         }
//         prev = temp;
//         temp = temp->next;
//     }
//     cout << "Word not found!" << endl;
// }

// // Function to display the dictionary (hash table)
// void display(Node* hashTable[]) {
//     bool isEmpty = true;
//     for (int i = 0; i < TABLE_SIZE; i++) {
//         cout << i << ": ";
//         Node* temp = hashTable[i];
//         if (temp == nullptr) {
//             cout << "Empty";
//         } else {
//             isEmpty = false;
//             while (temp != nullptr) {
//                 cout << "(" << temp->word << ": " << temp->meaning << ") -> ";
//                 temp = temp->next;
//             }
//         }
//         cout << endl;
//     }
//     if (isEmpty) {
//         cout << "The dictionary is empty!" << endl;
//     }
// }

// int main() {
//     // Initialize hash table as an array of pointers to Node
//     Node* hashTable[TABLE_SIZE] = { nullptr };

//     // Insert words and their meanings into the dictionary
//     insert(hashTable, "apple", "A fruit that is typically red or green.");
//     insert(hashTable, "banana", "A long yellow fruit.");
//     insert(hashTable, "grape", "A small, round, purple or green fruit.");
//     insert(hashTable, "mango", "A tropical fruit with a sweet taste.");

//     // Search for words
//     cout << "Meaning of 'apple': " << search(hashTable, "apple") << endl;
//     cout << "Meaning of 'grape': " << search(hashTable, "grape") << endl;
//     cout << "Meaning of 'orange': " << search(hashTable, "orange") << endl;

//     // Display dictionary
//     cout << "\nDictionary Contents:" << endl;
//     display(hashTable);

//     // Delete a word
//     deleteWord(hashTable, "banana");

//     // Display dictionary after deletion
//     cout << "\nDictionary after deletion:" << endl;
//     display(hashTable);

//     return 0;
// }

