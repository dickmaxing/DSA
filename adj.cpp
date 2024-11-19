#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class pairwiseSwapClass{
    Node* head;

    public:
        pairwiseSwapClass(){
            head = NULL;
        }

        void insert(int data){
            Node* newNode = new Node();
            newNode -> data = data;
            newNode -> next = NULL;

            if (head == NULL){
                head = newNode;
                return;
            }

            Node* temp = head;
            while (temp -> next != NULL)    temp = temp -> next;
            
            temp -> next = newNode;
        }

        void printList(){
            Node* temp = head;
            while (temp -> next != NULL){
                cout << temp -> data << "  ->  ";
                temp = temp -> next;
            }
            cout << temp -> data << endl;
        }

        void pairwiseSwap(){
            // Empty List or one element only case
            if (head == NULL || head -> next == NULL)   return;

            Node* prev = head;
            Node* curr = head -> next;

            head = curr;

            while (true){
                Node* first = curr -> next;
                curr -> next = prev;

                // Last element case
                if (first == NULL || first -> next == NULL){
                    prev -> next = first;
                    break;
                }

                // Updating the previous node pointer
                prev -> next = first -> next;

                // Move to the next pair
                prev = first;
                curr = prev -> next;
            }
        }
};

int main(){
    pairwiseSwapClass p;
    p.insert(1);
    p.insert(2);
    p.insert(3);
    p.insert(4);
    p.insert(5);


    cout << "Original list: ";
    p.printList();

    p.pairwiseSwap();

    cout << "List after pairwise swap: ";
    p.printList();

    return 0;
}