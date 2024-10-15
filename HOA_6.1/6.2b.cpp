#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include <utility>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node *next;
    Node *prev;
    //constructor to easily declare a node with data but no position
    Node(T data) : data(data), next(NULL), prev(NULL){}
};
template <typename T>
Node<T> *new_node(T newData){
    Node<T> *newNode = new Node<T>(newData);
    newNode->next = NULL;
    return newNode;
}
void ListTraversal(Node<char> *head){
    Node<char> *curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void linearLS(Node<char>* head, char dataFind) {
    Node<char> *curr = head;
    int index = 0; // To track the position of the element

    // Traverse the list to search for dataFind
    while (curr != NULL) {
        if (curr->data == dataFind) {
            cout << "Element '" << dataFind << "' found at index: " << index << endl;
            return; // Exit once the element is found
        }
        curr = curr->next;
        index++;
    }
}

int main(int argc, char** argv) {

    //create linked list for linear search
    Node<char> *name1 = new_node('R');
    Node<char> *name2 = new_node('o');
    Node<char> *name3 = new_node('m');
    Node<char> *name4 = new_node('a');
    Node<char> *name5 = new_node('n');

    //linked list
    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = NULL;

    cout << "Traversing the list:" << endl;
    ListTraversal(name1);

    cout<<"Finding: ";
    //linear search
    linearLS(name1, 'n');
    cout<<" "<<endl;


    return 0;
}
