#include <iostream>
using namespace std;
const int labCount = 4;
const int labSize[labCount] = {5, 6, 4, 3};
string* lab[4];

void displayMenu(){
    cout << endl;
    cout << "      Menu" << endl;
    cout << "[1] User logon" << endl;
    cout << "[2] User logoff" << endl;
    cout << "[3] Search" << endl;
    cout << "[4] Exit" << endl;
}

void displayUsers(){
    cout << "Lab Number  " << "Computer Stations" << endl;
    for (int i=0; i<labCount; i++){
        cout << i+1 << "           ";
        for (int j=0; j<labSize[i]; j++){
            cout << j+1 << ":" << (lab[i][j].empty()?"empty":lab[i][j]) << " ";
        }
        cout << endl;
    }
}

int main(){
    int action;
    string id;
    unsigned labNum, stationNum;
    for (int i=0; i<labCount; i++)
        lab[i] = new string[labSize[i]];
    while (true){
        displayMenu();
        if (cin >> action){
            switch (action){
            case 1:
                cout << "Please input: userID labnum stationnum" << endl;
                if (cin >> id >> labNum >> stationNum){
                    labNum--; stationNum--;
                    if (id.length() != 5 || labNum >= labCount || stationNum >= labSize[labNum]){
                        cout << "Please input valid data!" << endl;
                        break;
                    }
                    lab[labNum][stationNum] = id;
                    displayUsers();
                } else {
                    cout << "Please input valid data!" << endl;
                }
                break;
            case 2:
                cout << "Please input: labnum stationnum" << endl;
                if (cin >> labNum >> stationNum){
                    labNum--; stationNum--;
                    if (labNum >= labCount || stationNum >= labSize[labNum]){
                        cout << "Please input valid data!" << endl;
                        break;
                    }
                    lab[labNum][stationNum].clear();
                    displayUsers();
                } else {
                    cout << "Please input valid data!" << endl;
                }
                break;
            case 3:
                cout << "Please input: userID" << endl;
                if (cin >> id){
                    if (id.length() != 5){
                        cout << "Please input a valid ID";
                        break;
                    } else {
                        for (int i=0; i<labCount; i++){
                            for (int j=0; j<labSize[i]; j++){
                                if (lab[i][j] == id){
                                    cout << "Lab: " << i+1 << ", " << "machine num: " << j+1 << endl;
                                    goto nextloop;
                                }
                            }
                        }
                        cout << "None" << endl;
                    }
                } else {
                    cout << "Please input a valid ID!" << endl;
                }
                break;
            case 4:
                goto endp;
                break;
            }
        } else {
            cout << "Please input a valid number!" << endl;
        }
nextloop:;
    }

endp:
    for (int i=0; i<labCount; i++)
        delete[] lab[i];
    return 0;
}
