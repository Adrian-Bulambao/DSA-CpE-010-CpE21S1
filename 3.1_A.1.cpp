#include <iostream>
#include <utility>
using namespace std;

class Node{
public:
    char data;
    Node* next;
};

//List Traversal
void ListTraversal(Node *n){
  while(n!=NULL){
    cout<<n->data<<" ";
    n=n->next;
}
  cout<<endl;}

//Insert in front
Node* FrontInsertion (Node* head, char new_data)
{
  // Create a new node with the given data
  Node* new_node = new Node;
  new_node->data = new_data;
  new_node->next = head;
  return new_node;
}


//Insert anywhere
Node* insertPos(Node *head, int pos, char new_data) {

    if (pos < 1)
        return head;

    // head will change if pos=1
    if (pos == 1) {
      Node *new_node = new Node;
      new_node->data = new_data;
      new_node->next = head;
      return new_node;
    }

    Node *curr = head;

    // Traverse to the node that will be
    // present just before the new node
    for (int i = 1; i < pos - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }

    // If position is greater than the 
    // number of nodes
    if (curr == nullptr) 
        return head;

    Node *new_node = new Node;
    new_node->data = new_data;

    // update the next pointers
    new_node->next = curr->next;
    curr->next = new_node;

    return head;
}

Node* deleteAtPosition(Node*& head, int pos) {
    if (head == nullptr || pos < 1) {
        cout << "Invalid position or list is empty." << endl;;
    }
    // Deleting head node
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Traverse to the node before the target position
    Node* current = head;
    for (int i = 1; i < pos - 1 && current != nullptr; i++) {
        current = current->next;
    }

    // If position is greater than the number of nodes
    if (current == nullptr || current->next == nullptr) {
        cout << "Position exceeds list length." << endl;
    }

    // Delete the node at the target position
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    return head;
}

// Implementation
int main(){
    //step 1
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;
    Node *fifth = NULL;
    Node *last = NULL;
    //step 2
    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;
    fifth = new Node;
    last = new Node;
    //step 3
    head->data = 'C';
    head->next = second;

    second->data = 'P';
    second->next = third;

    third->data = 'E';
    third->next = fourth;

    fourth->data = '0';
    fourth->next = fifth;

    fifth->data = '1';
    fifth->next = last;

    //step 4
    last->data = '0';
    last->next = nullptr;

    cout<<"List Traversal:"<<endl;
    ListTraversal(head);
    cout<<" "<<endl;
    cout<<"Head Insertion:"<<endl;
    char data = 'G';
    head = FrontInsertion(head, data);
    ListTraversal(head);
    cout<<" "<<endl;
    cout<<"Insertion at any position:"<<endl;
    int pos = 4;
    char new_data = 'E';
    head = insertPos(head, pos, new_data);
    ListTraversal(head);
    cout<<" "<<endl;
    cout<<"Deletion of C"<<endl;
    int del_c = 2;
    head = deleteAtPosition(head, del_c);
    ListTraversal(head);
    cout<<" "<<endl;
    cout<<"Deletion of P:"<<endl;
    int del_p = 2;
    head = deleteAtPosition(head, del_p);
    ListTraversal(head);

  return 0;
}
