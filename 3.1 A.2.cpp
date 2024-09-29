#include <iostream>
#include <utility>
using namespace std;

class Node{
public:
    char data;
    Node *next;
    Node *prev;
    //constructor to easily declare a node with data but no position
    Node(int data) : data(data), next(NULL), prev(NULL){}
};

//
void ListTraversal(Node *head){
    Node *curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

//
Node *InsertatHead(Node *head, char data){
    Node *new_node = new Node(data);
    new_node->next = head;
    if (head != NULL){
        head->prev = new_node;
    }
    return new_node;
}

//
Node *InsertatAnywhere(Node *head, int pos, char new_data){
    Node *new_node = new Node(new_data);
    if (pos == 1){
        new_node->next = head;
        if (head != NULL)
            head->prev = new_node;
        head = new_node;
        return head;
    }
    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; ++i){
        curr = curr->next;
    }
    if (curr == NULL){
        cout << "Position is out of bounds." << endl;
        delete new_node;
        return head;
    }
    new_node->prev = curr;
    new_node->next = curr->next;
    curr->next = new_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
    return head;
}

//
Node *InsertatEnd(Node *head, char new_data){
    Node *new_node = new Node(new_data);
    if (head == NULL){
        head = new_node;
    }
    else{
          Node *curr = head;
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = new_node;
        new_node->prev = curr;
    }
    return head;
}

//
Node *deleteNode(Node * head, int pos){
    if (!head)
        return head;
    Node * curr = head;
    for (int i = 1; curr && i < pos; ++i){
        curr = curr -> next;
    }
    if (!curr)
        return head;
    if (curr -> prev)
        curr -> prev -> next = curr -> next;
    if (curr -> next)
        curr -> next -> prev = curr -> prev;
    if (head == curr)
        head = curr -> next;
    delete curr;
    return head;
}

int main(){
    Node *head = new Node('A');
    Node *second = new Node('P');
    Node *third = new Node('E');
    Node *fourth = new Node ('0');
    Node *fifth = new Node ('1');
    Node *sixth = new Node ('0');

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;
    fifth->next = sixth;

    cout << "Traversing the list:" << endl;
    ListTraversal(head);
    
    cout<<endl;
    cout << "Inserting a node at the head of the list: " << endl;
    char data = 'C';
    head = InsertatHead(head, data);
    ListTraversal(head);
    
    cout<<endl;
    cout << "Inserting a node anywhere in the list: " << endl;
    data = 'G';
    int pos = 3;
    head = InsertatAnywhere(head, pos, data);
    ListTraversal(head);
    
    cout<<endl;
    cout << "Inserting a node at end of the list: " << endl;
    data = '1';
    head = InsertatEnd(head, data);
    ListTraversal(head);
    
    cout<<endl;
    cout << "Deleting a node in a list: " << endl;
    pos = 4;
    head = deleteNode(head, pos);
    ListTraversal(head);

    return 0;
}

