/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node *newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* copyRandomList(Node* head) {

        Node *cloneHead = NULL, *cloneTail = NULL;
        Node *temp = head;
        
        // Step 1 = Create a cloned LL
        while(temp != NULL ){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // Step 2 - Merge original and cloned LL
        temp = head;
        Node *clone = cloneHead;
        while(temp != NULL && clone != NULL){
            Node *newNode = temp->next;
            temp->next = clone;
            temp = newNode;

            newNode = clone->next;
            clone->next = temp;
            clone = newNode;
        }

        // Step 3 - Copy the random pointers from original node to clone nodes
        temp = head;
        while(temp != NULL){
            if(temp->next != NULL && temp->random != NULL){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // Step 4 - Revert/Reverse the step 2 by separating the orignal and clone LL
        temp = head;
        clone = cloneHead;
        while(temp != NULL){
            temp->next = clone->next;
            temp = temp->next;

            if(temp != NULL)
                clone->next = temp->next;
            clone = clone->next;
        }

        return cloneHead;
    }
};