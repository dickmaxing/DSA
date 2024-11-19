#include <iostream>
using namespace std;

class Node {
public:
    int coeff;  
    int exp;    
    Node* next; 

    Node(int c, int e){
        this->coeff=c;
        this->exp=e;
        this->next=nullptr;
    }
};

class Expression {
public:
    Node* head;

    Expression(){
        head=nullptr;
    }

    void addElm(int coeff, int exp) {
        Node* nn = new Node(coeff, exp);
        if (head == nullptr) {
            head = nn;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nn;
        }
    }

    void printPoly() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->coeff << "x^" << temp->exp;
            if (temp->next != nullptr)
                cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }

    
    Expression operator+ (Expression poly2) {
        Expression result;

        Node* p1 = head;
        Node* p2 = (&poly2)->head;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->exp == p2->exp) {
                result.addElm(p1->coeff + p2->coeff, p1->exp);
                p1 = p1->next;
                p2 = p2->next;
            }

            else if (p1->exp > p2->exp) {
                result.addElm(p1->coeff, p1->exp);
                p1 = p1->next;
            }
            else {
                result.addElm(p2->coeff, p2->exp);
                p2 = p2->next;
            }
        }

        while (p1 != nullptr) {
            result.addElm(p1->coeff, p1->exp);
            p1 = p1->next;
        }

        while (p2 != nullptr) {
            result.addElm(p2->coeff, p2->exp);
            p2 = p2->next;
        }

        return result;
    }
};

int main() {
    Expression poly1, poly2;
    int pol1[2][3]={
        {7,8,3},
        {7,2,1}
        };
    int pol2[2][3]={
        {1,2,4},
        {7,3,1}
        };

    for(int i=0;i<=2;i++)
        poly1.addElm(pol1[0][i],pol1[1][i]);    

    for(int i=0;i<=2;i++)
        poly2.addElm(pol2[0][i],pol2[1][i]);

    cout << "Polynomial I: ";
    poly1.printPoly();

    cout << "Polynomial II: ";
    poly2.printPoly();

    Expression result = poly1+poly2;

    cout << "\nResulting Polynomial: ";
    result.printPoly();

    return 0;
}
