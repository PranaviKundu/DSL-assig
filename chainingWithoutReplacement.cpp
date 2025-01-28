#include <iostream>
#include <vector>
using namespace std;

int hashFunction(int key) {
    return key % 10;
}

void insert(int key, int arr[10][2]) {
    int index = hashFunction(key);
    if (arr[index][0] == -1) {
        arr[index][0] = key;
        cout << "Inserted "<< key <<" successfully" << endl;
    } else {
        int j = index + 1;
        while (j != index) {
            if (arr[j][0] == -1) {
                arr[j][0] = key;
                cout << "Inserted "<<key<<" successfully" << endl;
                if (hashFunction(key) == hashFunction(arr[index][0])) {
                    arr[index][1] = j;
                    cout << "Chain column updated" << endl;
                }
                return;
            }
            j = (j + 1) % 10;
        }
    }
}

int search(int key, int arr[10][2]) {
    int cnt = 0;
    int i = 0;
    int val = key % 10;
    while (i < 10) {
        cnt++;
        if (arr[val][0] == key) {
            cout << key <<"found at index: " << val << endl;
            cout << "Number of comparisons: " << cnt << endl;
            return val;
        } else if (hashFunction(key) == val) {
            if (arr[val][1] == -1) {
                cout <<key << " not found!" << endl;
                return -1;
            } else if (arr[val][0] == -1) {
                cout << key <<" not found!" << endl;
                return -1;
            } else {
                val = arr[val][1];
            }
        } else if (hashFunction(key) != val) {
            int j = val + 1;
            while (j != val) {
                cnt++;
                if (arr[j][0] == key) {
                    cout << key <<" found at index: " << j << endl;
                    cout << "Number of comparisons: " << cnt << endl;
                    return j;
                }
                j = (j + 1) % 10;
            }
        }
        i++;
    }
    return -1;
}

float load_factor(int arr[10][2]) {
    int elements = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i][0] != -1) {
            elements++;
        }
    }
    return static_cast<float>(elements) / 10;
}

void display(int arr[10][2]) {
    cout << "The hash table is: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr[i][0] << " ";
    }
    cout << endl;
}

void delete_key(int key, int arr[10][2]) {
    int index = search(key, arr);
    
    if (index != -1) {
        arr[index][0] = -1;
        arr[index][1] = -1; 
        cout << "Element " << key << " deleted successfully!" << endl;
    } else {
        cout << "Element " << key << " not found in the hash table!" << endl;
    }
}


int main() {
    int arr[10][2];
    for (int i = 0; i < 10; i++) {
        arr[i][0] = -1;
        arr[i][1] = -1;
    }

    insert(25, arr);
    insert(35, arr);
    insert(45, arr);
    display(arr);

    search(35, arr);
    search(50, arr);

    cout << "Load factor: " << load_factor(arr) << endl;

    return 0;
}
