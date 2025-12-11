#include <iostream>
#define msize 7
using namespace std;
int stack[msize];
int top =-1;//if value is -1, that means the stack is empty
void push (int item){
    //validation for full stack
    if(top==msize-1){
        cout<<"***overflow***"<<endl;
        return;
    }
    stack[++top]=item;
    cout<<"pushed element " <<item<<endl;
}

int pop(){
    //validation for empty stack
    if(top==-1){
        cout<<"***underflow***"<<endl;
        return -1;
    }
return stack[top--];
}

int peek (){
    //validation for empty stack
    if(top==-1){
        cout<<"***underflow***"<<endl;
        return -1;
    }
return stack[top];
}

int main(){
    pop();
    peek();
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);
    cout<<"top element : "<<peek()<<endl;
    cout<<"poped element : "<<pop()<<endl;
    cout<<"top element : "<<peek()<<endl;

}
