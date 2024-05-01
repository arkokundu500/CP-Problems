//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
public:
    struct Node* arrangeCV(Node *head) {
        // Initialize two queues for vowels and consonants
        queue<char> vowels, consonants;
        
        // Pointer to traverse the linked list
        Node* current = head;
        
        // Traverse the linked list and separate vowels and consonants
        while (current) {
            char ch = current->data;
            current = current->next;
            if (ch == 'a' ||  ch == 'e' || ch == 'i' || ch == 'o' ||  ch == 'u') {
                // If the character is a vowel, push it into the vowel queue
                vowels.push(ch);
            } else {
                // If the character is a consonant, push it into the consonant queue
                consonants.push(ch);
            }
        }
        
        // Reset the pointer to the head of the linked list
        current = head;
        
        // Reconstruct the linked list with vowels followed by consonants
        while (current) {
            if (!vowels.empty()) {
                // If there are still vowels left, replace the current node's data with the front of the vowel queue
                current->data = vowels.front();
                vowels.pop();
            } else {
                // If there are no more vowels, replace the current node's data with the front of the consonant queue
                current->data = consonants.front();
                consonants.pop();
            }
            // Move to the next node
            current = current->next;
        }
        
        // Return the head of the updated linked list
        return head;
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends