#include <iostream>
#include <queue>
using namespace std;


class Stack{
    queue  <int> q1, q2;

    public:
    void push(int x){
        q1.push(x);
    }

    void pop(){
        if(q1.empty())  return;
        int temp = q1.front();
        q1.pop();
        while(temp !=q1.back()){
            q2.push(temp);
            temp = q1.front();
            q1.pop();
        }
        
        cout<<temp<<endl;

        if(q2.empty())  return;
        
        do{
            temp = q2.front();
            q2.pop();
            q1.push(temp);
        }while(temp !=q2.back());

    }

    void seek(){
        if(q1.empty())  return;

        cout<<q1.back()<<endl;
    }


};

int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    
    s.seek();
    cout <<"\n";
    s.pop();
    s.pop();
    s.pop();
}