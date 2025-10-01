#include<iostream>
using namespace std;


struct Node{
    int data;
    Node* next;
};
Node* top =nullptr;
//push 
void push(int value){
    
    Node * newNode= new Node();
    newNode-> data = value;
    newNode-> next = top;
    top = newNode;

        cout << value<<"ditambahkan dalam stack.\n";
    }


//pop
void  pop(){
    if (top= nullptr){
        cout<<"stack kosong!\n";

    }else {
        Node * temp= top;
        cout <<"\n"<<temp->data<<" dihapus dari stack.\n";
        top = top-> next;
        delete temp;

    }
}
//nampilin stack
void display(){
    if(top== nullptr){
        cout<<"stack kosong!\n";
            return ;
    }
        cout<<"\n isi stack:\n";
       Node * current= top;
       while (current != nullptr){
        cout<< current-> data<<" ";
        current = current-> next;

       }
       cout<<endl;
    }

 int main(){
    push(10);
    push(20);
    push(30);
   
    display();
    pop();
    display();
    return 0;

}
 

