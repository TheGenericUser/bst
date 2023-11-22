#include <iostream>
#define SPACE 10
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node() {
        this->value = 0;
        this->left = nullptr;
        this->right = nullptr;
    }

    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST{
public:
    Node* root;
    BST(){
        this->root = nullptr;
    }

    bool isEmpty() {
       return (root == nullptr);
    }

    void insertNode(Node* node) {
        if (root == nullptr) {
            root = node;
            cout << "Root added.\n";
        }
        else {
            Node* temp = root;
            while (temp != nullptr) {
                if (temp->value == node->value) {
                    cout << "Duplicates not allowed.\n";
                    return;
                }
                else if ((node->value < temp->value) && temp->left == nullptr) {
                    temp->left = node;
                    cout << node->value << " inserted at left of " << temp->value << "\n";
                    break;
                }
                else if (node->value < temp->value) {
                    temp = temp->left;
                }
                else if ((node->value > temp->value) && temp->right == nullptr) {
                    temp->right = node;
                    cout << node->value << " inserted at right of " << temp->value << "\n";
                    break;
                }
                else {
                    temp = temp->right;
                }
            }
        }
    }

    void printPreorder(Node* start) {
        if (start == nullptr){
            return;
        }
        cout << start->value <<" ";
        printPreorder(start->left);
        printPreorder(start->right);
    }

    void printInorder(Node* start){
        if (start == nullptr) {
            return;
        }
        printInorder(start->left);
        cout << start->value << " ";
        printInorder(start->right);
    }

    void printPostorder(Node* start) {
        if (start == nullptr) {
            return;
        }
        printPostorder(start->left);
        printPostorder(start->right);
        cout << start->value << " ";
    }

    void print2D(Node* start, int space) {
        if (start == NULL){
            return; 
        }
        space += SPACE;
        print2D(start->right, space);
        cout <<"\n";
        for (int i = SPACE; i < space; i++){
            cout << " ";
        }
        cout << start->value << "\n";
        print2D(start->left, space);
    }

    Node* search(int data) {
        if (root == nullptr) {
            return root;
        }
        Node* temp = root;
        while (temp != nullptr){
            if (temp->value == data) {
                return temp;
            }
            else if (temp->value > data) {
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        return nullptr;
    }

    Node* minValue(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* start, int data) {
        if (start == nullptr) {
            return start;
        }
        if (data < start->value) {
            start->left = deleteNode(start->left, data);
        }
        else if (data > start->value) {
            start->right = deleteNode(start->right, data);
        }
        else {
            if (start->left == nullptr) {
                Node* temp = start->right;
                delete start;
                return temp;
            }
            else if (start->right == nullptr) {
                Node* temp = start->left;
                delete start;
                return temp;
            }
            else{
                Node* temp = minValue(start->right);
                start->value = temp->value;
                start->right = deleteNode(start->right, temp->value);
            }
        }
        return start;
    }
};

int main(){
    BST bst;
    int option, value;
    do {
        cout << "What operation do you want to perform? " <<
            " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal BST values" << endl;
        cout << "5. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        Node* node = new Node();

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "INSERT" << endl;
            cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
            cin >> value;
            node->value = value;
            bst.insertNode(node);
            break;
        case 2:
            cout << "SEARCH" << endl;
            cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
            cin >> value;
            node = bst.search(value);
            if (node != nullptr) {
                cout << "Value found" << endl;
            }
            else {
                cout << "Value NOT found" << endl;
            }
            break;
        case 3:
            cout << "DELETE" << endl;
            cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
            cin >> value;
            node = bst.search(value);
            if (node != NULL) {
                bst.deleteNode(bst.root, value);
                cout << "Value Deleted" << endl;
            }
            else {
                cout << "Value NOT found" << endl;
            }
            break;
        case 4:
            cout << "Preorder:\n";
            bst.printPreorder(bst.root);
            cout << "\n";
            cout << "Inorder:\n";
            bst.printInorder(bst.root);
            cout << "\n";
            cout << "Postorder:\n";
            bst.printPostorder(bst.root);
            cout << "\n";
            cout << "PRINT 2D:\n";
            bst.print2D(bst.root, 5);
            cout << "\n";
            break;
        case 5:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);
}