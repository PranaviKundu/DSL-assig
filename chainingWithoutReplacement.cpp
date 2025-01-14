#include<iostream>
#include<vector>
using namespace std;
int hashFunction(int key){
    return key%10;
}
vector<int> table;

void insert(int key, arr){
    int index= hashFunction(int key);
    if(arr[index][0]==-1){
        arr[index][0]==key;
        cout<<"Inserted successfully";
    }
    else{
        j=index+1;
        while(j!=index){
            if(arr[j][0]==-1){
                arr[j][0]=key;
                cout<<"Inserted successfully";
                if(hashFunction(key==hashFunction(arr[index]))){
                    arr[index][1]=j;
                    cou<<"Chain column updated";
                }
            }
            j=((j+1)%10);
        }
    }
}
void search(int key, arr){
    int cnt=0;
    int i=0;
    int val=key%10;
    while(i<10){
        if(arr[val][0]==key){
            cout<<"Element found at index: "<<val;
            cout<<"Number of comparsions: "<<cnt;
            return;
        }
        else if(hashFunction(key)==val){
            if(arr[val][1]==-1){
                cout<<"Element not found!"<<endl;
                return;
            }
            else if(arr[val][0]==-1){
                cout<<"Element not found!"<<endl;
                return;
            }
            else{
                val=arr[val][1];
            }
        }
        else if(hashFunction(key)!=val){
            int j=val+1;
            while(j!=val){
                if(arr[j][0]==key){
                    cout<<"Element found at index: "<<val;
                    cout<<"Number of comparsions: "<<cnt;
                    return;
                }

                j=(j+1)%10;
            }
        }
        i++;
    }
}
void load_factor(){
    //number of elements in table/size of table
    int elements=0;
    for(int i=0;i<10;i++){
        if(arr[i][0]!=-1){
            elements++;
        }
        else{
            continue;
        }
    }
    int loadFactor=elements/10;
    return loadFactor;
}
void display(){
    cout<<"The hash table is: "<<endl;
    for(int i=0;i<10;i++){
        cout<<arr[i][0];
    }
}
void delete(int key){

}
int main(){
    int arr[10][2];
    for(int i=0;i<10;i++){
        arr[i][0]=-1;
        arr[i][1]=-1;
    }

}
