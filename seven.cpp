#include <iostream>
#include <chrono>

using namespace std;

struct tab{
    string time;
    string url;
    tab *next;
};

class history{
    tab *head;
    int len;

    void disp(tab* t){
        cout<<t->url<<"\t"<<t->time<<"\n";
    }

    public:

    history(){
        head = NULL;
        len = 0;
    }

    void add(string url){
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        string time = std::ctime(&now_c);
        
        tab *nt =new tab;

        if(!nt)
            return;

        nt->url = url;
        nt->time = time;
        len++;

        if(!head){
            head = nt;
            return;
        }

        nt->next = head;
        head = nt;
    }

    void pop(){
        if(!head){
            cout<<"Empty\n";
            return;
        }

        
        if(len == 1){
            disp(head);
            head = NULL;
            len--;
            return;
        }

        disp(head);
        tab *temp = head;
        head = head->next;
        free(temp);
        len--;
    }

    void seek(){
        if(!head){
            cout<<"Empty\n";
            return;
        }

        disp(head);
    }

    void is_empty(){
        if(!head){
            cout<<"Empty";
            return;
        }

        cout<<"Available";
    }

    void seekAll(){
        if(!head){
            cout<<"Empty\n";
            return;
        }

        tab *temp = head;
        while(temp){
            disp(temp);
            temp = temp->next;
        }
    }
};

int main(){
    history b;
    b.add("bob the builder.com");
    b.add("rollnumber21.net");
    
    cout<<"0)Add Website to history\n1)Go to last website\n2)Display Current webpage\n3)Availability of History\n4)Display All History\n-1)Exit";
    int choice=0;
    do{
        cout<<"\nChoice: ";
        cin>>choice;
        string url;

        switch (choice)
        {
        case 0:
            cout<<"\nWebsite you visited: ";
            cin>>url;

            b.add(url);
            break;
        case 1:
            cout<<"\nLAst Visited:\n";
            b.pop();
            break;
        case 2:
            cout<<"\nCurrent page\n";

            b.seek();
            break;
        case 3:
            cout<<"\nHistory Status:";
            b.is_empty();
            break;
        case 4:
            cout<<"Complete History:";
            b.seekAll();
            break;
        default:
            break;
        }
    }while(choice != -1);

    return(0);
}