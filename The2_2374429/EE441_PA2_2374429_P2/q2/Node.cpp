#include "Node.hpp"


template <class T>
Node<T>* Xor(Node<T>* x, Node<T>* y)
{
 return reinterpret_cast<Node<T>*>(
 reinterpret_cast<uintptr_t>(x)
 ^ reinterpret_cast<uintptr_t>(y));
}


template <class T>
void insert(Node<T>* &head_ref, T data)
{
 // Allocate memory for the new node
 Node<T>* new_node = new Node<T>();
 new_node -> data = data;

 // Since the new node is inserted at the
 // start, xnode of new node will always be
 // Xor of current head and NULL
 new_node -> xnode = head_ref;
 // If the linkedlist is not empty, then xnode of
 // present head node will be XOR of the new node
 // and node next to current head */
 if (head_ref != NULL)
 {
 // *(head_ref)->xnode is Xor of (NULL and next).
 // If we XOR Null with next, we get next
 head_ref->xnode = Xor(new_node, head_ref->xnode);
 }
 // Change head
 head_ref = new_node;
}


template <class T>
void printList(Node<T>* head){
 Node<T>* currPtr = head;
 Node<T>* prevPtr = NULL;
 Node<T>* nextPtr;

 cout << "The nodes of Linked List are: \n";
 // Till condition holds true
 while (currPtr != NULL) {
 // print current node
 cout << currPtr -> data << " ";

 // get the address of next node: currPtr->xnode is
 // {nextPtr (XOR) prevPtr}, so {currPtr->xnode (XOR) prevPtr} will
 // be {nextPtr (XOR) prevPtr (XOR) prevPtr}, which is nextPtr
 nextPtr = Xor(prevPtr, currPtr -> xnode);

 // update prevPtr and currPtr for next iteration
 prevPtr = currPtr;
 currPtr = nextPtr;
 }
 cout<<endl;
}

template <class T>
void print_elements(Node<T>* last){
    Node<T>* currPtr = last;
    Node<T>* prevPtr;
    Node<T>* nextPtr = NULL;
    while(currPtr != NULL){
        cout << currPtr -> data;
        prevPtr = Xor(nextPtr, currPtr -> xnode);
        nextPtr = currPtr;
        currPtr = prevPtr;
    }
    cout << endl;
}

template <class T>
void push_frontn(Node<T>* &head, Node<T>* &rear,T data){
    Node<T>* new_node = new Node<T>();
    new_node -> data = data;
    new_node -> xnode = head;
    if(rear == NULL)rear = new_node; //Start Case
    if(head != NULL){
        head -> xnode = Xor(new_node,head ->xnode);
    }

    // change the head
    head = new_node;
}

template<class T>
void push_rearn(Node<T>* &head,Node<T>* &rear,T data){
    Node<T>* new_node = new Node<T>();
    new_node -> data = data;
    new_node -> xnode = rear;
    if(head == NULL)head = new_node; //Start Case
    if(rear != NULL){
       rear -> xnode = Xor(new_node, rear ->xnode);
    }
    rear = new_node;
}

template<class T>
T pop_frontn(Node<T>* &head,Node<T>* &rear){
    Node<T>* nextheadx;
    Node<T>* currPtr = head;
    T temp = head -> data;

    if(head == NULL){ // EMPTY CASE
        cout << "Deleting empty stackqueue from front" ;
        exit(1);
    }
    else if(head == rear){ // THERE IS 1 ELEMENT
        head = NULL;
        rear = NULL;
        return temp;
    }
    else{
        nextheadx = Xor(head->xnode->xnode,head);
        head = head ->xnode;
        head ->xnode = nextheadx;
    }
    delete currPtr;
    return temp;
}

template<class T>
T pop_rearn(Node<T>* &head,Node<T>* &rear){

    Node<T>* nextrearx;
    Node<T>* currPtr = rear;
    T temp = rear -> data;

    if(rear == NULL){ // EMPTY CASE
        cout << "Deleting empty stackqueue from front" ;
        exit(1);
    }
    else if(head == rear){ // THERE IS 1 ELEMENT
        head = NULL;
        rear = NULL;
        return temp;
    }
    else{
        nextrearx = Xor(rear->xnode->xnode,rear);
        rear = rear ->xnode;
        rear -> xnode = nextrearx;
    }
    delete currPtr;
    return temp;
}

template<class T>
T peek_frontn(Node<T>* &head){
    return head ->data;
}

/*
int main(){
    Node<int> *head = NULL, *rear= NULL;
    int a;
    push_rear(head,rear,4);
    push_rear(head,rear,5);
    push_front(head,rear,1);
    push_front(head,rear,2);
    push_front(head,rear,3);

    printList(head);
    a = peek_front(head);
    cout << "peek" << a << endl;

    a = pop_rear(head,rear);
    cout << a << endl;
    printList(head);

    a = pop_front(head,rear);
    cout << a << endl;
    printList(head);

     a = peek_front(head);
    cout << "peek" << a << endl;

    a = pop_rear(head,rear);
    cout << a << endl;
    printList(head);

    a = pop_front(head,rear);
    cout << a << endl;
    printList(head);


    return 0;
}
*/
