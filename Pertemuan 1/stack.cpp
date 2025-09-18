#include <iostream>
using namespace std;

#define max 5
int stack[max];
int top = -1;

//push 
void push(int value){
    if (top == max -1){
        cout<<"stack prnuh!\n";

    }else {
        top++;
        stack[top] = value;
        cout << value<<"ditambahkan dalam stack.\n";
    }
}

//pop
void  pop(){
    if (top==-1){
        cout<<"stack kosong!\n";

    }else {
        cout <<"\n"<<stack[top]<<" dihapus dari stack.\n";
        top--;
    }
}
//nampilin stack
void display(){
    if(top==-1){
        cout<<"stack kosong!\n";

    }else{
        cout<<"\n isi stack:\n";
        for(int i=top; i>=0;i--){
            cout<< stack [i]<<" ";
        }
    }
}
 int main(){
    push(50);
    push(40);
    push(30);
    push(20);
    push(10);
    display();
    pop();
    display();
    return 0;

}