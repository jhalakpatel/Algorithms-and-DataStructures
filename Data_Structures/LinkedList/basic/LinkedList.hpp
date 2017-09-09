class Node {
    public:
        int data;
        Node *next;
        Node(int data);
        Node(Node* node);
};
 
class LinkedList {
    private:
        // head of the linked list
        Node *head;

    public:
        LinkedList(Node *head);
        void appendToTail(int data);
        void deleteNode(int data);
};   
