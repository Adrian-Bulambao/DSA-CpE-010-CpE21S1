#include <iostream>
#include <utility>
using namespace std;

class Node{
public:
    string data;
    Node* next;
};

//List Traversal
void ListTraversal(Node *n){
// make the list count start with 1    
  int count = 1;
  cout<<" "<<endl;
  cout<<"Current Playlist:"<<endl;
  while(n!=NULL){
    cout<<count<<". "<<n->data<<endl;
    n=n->next;
    count++;
}
  cout<<endl;}

//Insert in front
Node* FrontInsertion (Node* head, string new_data)
{
  // Create a new node with the given data
  Node* new_node = new Node;
  new_node->data = new_data;
  new_node->next = head;
  return new_node;
}


//Insert anywhere
Node* insertPos(Node *head, int pos, string new_data) {

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

Node* insertAtEnd(Node* head, string end_data) {

    // Create a new node
    Node* new_node = new Node;

    // If the Linked List is empty, make
    // the new node as the head and return
    if (head == nullptr) {
        return new_node;
    }

    // Store the head reference in a temporary variable
    Node* last = head;

    // Traverse till the last node
    while (last->next != nullptr) {
        last = last->next;
    }

    // Change the next pointer of the last node
    // to point to the new node
    new_node->data = end_data;
    last->next = new_node;

    // Return the head of the list
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
    head->data = "Heavy is The Crown";
    head->next = second;

    second->data = "Wildfire";
    second->next = third;

    third->data = "Rise";
    third->next = fourth;

    fourth->data = "Pokemon: Driftveil City Music";
    fourth->next = fifth;

    fifth->data = "Bury The light";
    fifth->next = last;

    //step 4
    last->data = "Rapunzel";
    last->next = nullptr;
    
    
    cout<<"Playlist Traversal:"<<endl;
    ListTraversal(head);
    cout<<" "<<endl;
    cout<<"Song Insertion to Top of Playlist:"<<endl;
    string data = "The Man Who Can\'t Be Moved";
    head = FrontInsertion(head, data);
    ListTraversal(head);
    cout<<" "<<endl;
    cout<<"Adding a song to random playlist order:"<<endl;
    int pos = 4;
    string new_data = "Rise";
    head = insertPos(head, pos, new_data);
    ListTraversal(head);
    cout<<" "<<endl;
    cout<<"Song insertion at end of playlist:"<<endl;
    string end_data = "Die With a Smile";
    head = insertAtEnd(head, end_data);
    ListTraversal(head);
    cout<<" "<<endl;
    cout<<"Removing song to playlist:"<<endl;
    int del_pos = 4;
    head = deleteAtPosition(head, del_pos);
    ListTraversal(head);

  return 0;
}
