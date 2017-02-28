#include <iostream>
#include <string>
using namespace std;

string* addEntry(string *dynamicArray, int &size, string newEntry){
    string *newArray = new string[size+1];
    for (int i=0; i<size; i++)
        newArray[i] = dynamicArray[i];
    newArray[size++] = newEntry;
    delete[] dynamicArray;
    return newArray;
}

string* deleteEntry(string *dynamicArray, int &size, string entryToDelete){
    string *newArray;
    for (int i=0; i<size; i++){
        if (dynamicArray[i] == entryToDelete){
            newArray = new string[size-1];
            for (int j=0; j<i; j++)
                newArray[j] = dynamicArray[j];
            for (int j=i+1; j<size; j++)
                newArray[j-1] = dynamicArray[j];
            size--;
            delete[] dynamicArray;
            return newArray;
        }
    }
    return dynamicArray;
}

void printArray(const string *strArr, int size){
    for (int i=0; i<size; i++){
        cout << strArr[i] << (i != size-1 ? " " : "");
    }
    cout << endl;
}

int main(){
    string* dynamicArr  = new string[5];
    int size = 5;
    int opt;
    string tmp;
    for (int i=0; i<5; i++)
        cin >> dynamicArr[i];
    while (cin >> opt >> tmp){
        if (opt == 1){
            dynamicArr = addEntry(dynamicArr, size, tmp);
        }
        if (opt == 2){
            dynamicArr = deleteEntry(dynamicArr, size, tmp);
        }
        printArray(dynamicArr, size);
    }
    return 0;
}
