#include "BST.h"
int main() {
    BST obj;
    obj.insert(50);
    obj.insert(30);
    obj.insert(70);
    obj.insert(23);
    obj.insert(35);
    obj.insert(80);
    cout << "Preorder: ";
    obj.displayPreorder();
    cout << endl;
    cout << "Postorder: ";
    obj.displayPostorder();
    cout << endl;
    cout << "Inorder: ";
    obj.displayInorder();
    cout << endl;
    obj.deleteNumber(50);
    obj.deleteNumber(30);
    cout << "After deletion " << endl;
    cout << "Inorder: ";
    obj.displayInorder();
    cout << endl;
    return 0;
}