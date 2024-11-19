#include <iostream>
using namespace std;

struct node{
    public:

    string word;
    node *next;
    node *prev;

    node(){
        next = NULL;
        prev = NULL;
    }
};

class doc{
    node *header;
    node *tail;
    int len;

    public:
    doc(){
        header = NULL;
        tail = NULL;
        len=0;
    }

    void insert(string s){
        node *nn = new node();
        if(!nn){
            cout<<"your mom";
            return;
        }
        nn->word = s;
        nn->next = NULL;
        nn->prev = NULL;
        len++;

        if(!header){
            header = nn;
            tail = nn;
        }
        else{
            tail->next = nn;
            tail->next->prev = tail;
            tail = nn;
        }
    }

    void display(){
        node *temp = header;

        while(temp != NULL){
            cout<<temp->word<<"\n";
            temp = temp->next;
        }
    }
    void display_rev(){
        node *temp = tail;

        while(temp != NULL){
            cout<<temp->word<<"\n";
            temp = temp->prev;
        }
    }
    
    void backspace(){
        if(header == NULL){
            cout<<"Your mom 2";
            return;
        }
        if(header == tail){
            free(header);
            header = tail = NULL;
            return;
        }
        len--;
        node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
    void delet(string seg){
        node *temp = header;
        bool wordFlg = false;

        while(!wordFlg){
            if(temp->word.compare(seg)==0){
                wordFlg = !wordFlg;
                return;
            }

            temp = temp->next;
        }

        if(wordFlg){
            len--;
            node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
        }
        else{
            cout<<"\n Word not found";
        }
    }
};

int main(){

    doc d;
    d.insert("Chicken");
    d.insert("is");
    d.insert("Very");
    d.insert("Good");


    cout<<"0)Add word\n1)Display all words\n2)Display all words in reverse\n3)Delete specific word\n4)Backspace";
    int choice=0;
    do{
        cout<<"\nChoice: ";
        cin>>choice;
        string wrd;

        switch (choice)
        {
        case 0:
            cout<<"\nWord to add: ";
            cin>>wrd;

            d.insert(wrd);
            break;
        case 1:
            cout<<"\nAll Words:\n";
            d.display();
            break;
        case 2:
            cout<<"\nAll Words in reverse\n";

            d.display_rev();
            break;
        case 3:
            cout<<"\nWhich word to Delete:";
            cin>>wrd;
            d.delet(wrd);
            break;
        case 4:
            cout<<"\n";
            d.backspace();
            break;
        default:
            break;
        }
    }while(choice != -1);

    return(0);
}