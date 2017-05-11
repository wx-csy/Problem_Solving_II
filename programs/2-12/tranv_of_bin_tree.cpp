#include <iostream>
#include <string>
using namespace std;

string inorder, postorder;
int imap[300];

void work(int il, int ir, int pl, int pr){
    if (il > ir){
        return;
    }
    cout << postorder[pr];
    int ipvt = imap[postorder[pr]];
    work(il, ipvt - 1, pl, pl + ipvt - 1 - il);
    work(ipvt + 1, ir, pl + ipvt - il, pr - 1);
}

int main(){
    cin >> inorder >> postorder;
    for (int i=0; i<inorder.size(); i++)
        imap[inorder[i]] = i;
    work(0, inorder.size() - 1, 0, postorder.size() - 1);
    cout << endl;
    return 0;
}
