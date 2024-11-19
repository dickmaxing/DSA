#include <iostream>

using namespace std;


struct group{
    int num;
    int ppl;
    string name;
    group *next;
};

class WaitList{
    group *front;
    group *rear;

    int cnt;

    int len;

    public:
    WaitList(){
        front = NULL;
        rear = NULL;
        len = 0;
        cnt = 0;
    }

    void AddParty(string name, int ppl){
        group *newGroup = new group;
        if(!newGroup)   return;
        cnt++;
        newGroup->num = cnt;
        newGroup->ppl = ppl;
        newGroup->name = name;
        newGroup->next = NULL;
        len++;

        if(front == NULL){
            front = rear = newGroup;
            return;
        }
        rear->next = newGroup;
        rear = newGroup;
    }

    void Displaylist(){
        cout<<"-------------------------------------------------------"<<endl;
        group *temp = front;
        while(temp != NULL){
            cout<<"Group: "<<front->num<<endl;
            cout<<"Number of people: "<<temp->ppl<<endl;
            cout<<"Name: "<<temp->name<<endl;
            cout<<endl;

            temp = temp->next;
        }    
    }

    void SeatParty(){
        group *temp = front;
        cout<<"Group "<<front->num<<" is seated."<<endl;
        front = front->next;
        len--;
        delete(temp);
    }

    void NextParty(){
        if(front == NULL) return;

        cout<<"Next up: "<<endl;
        cout<<"Group: "<<front->num<<endl;
        cout<<"Number of people: "<<front->ppl<<endl;
        cout<<"Name: "<<front->name<<endl;
        cout<<endl;

    }

};

int main(){
    WaitList w;

    w.AddParty("A", 1);
    w.AddParty("B", 2);
    w.AddParty("C", 3);
    w.AddParty("D", 4);


    int name;
    string  nameStr; 
    int c = -1;
    do{
        cout<<"Choice: ";
        cin>>c;

        switch(c){
            case  1:
                cout<<"Name? ";
                cin>>nameStr;
                cout<<"Number of people? ";
                cin>>name;
                w.AddParty(nameStr,name);
                break;

            case 2:
            w.NextParty(); break;
            case 3:
            w.SeatParty(); break;
            case 4:
            w.Displaylist(); break;
            
            default:
            cout<<"Invalid choice. Please choose again."<<endl;

        }
    }while(c != 0);
}