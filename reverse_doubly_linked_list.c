class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        Node *temp1=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        Node *dup=temp1;
        while(dup!=NULL){
            if(dup->next==NULL){
                dup->next=dup->prev;
                dup->prev=NULL;
            }
            else if(dup->prev==NULL){
                dup->prev=dup->next;
                dup->next=NULL;
            }
            else{
                Node *temp3=dup->next;
                dup->next=dup->prev;
                dup->prev=temp3;
            }
            dup=dup->next;
        }
        return temp1;
    }
};

//https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
