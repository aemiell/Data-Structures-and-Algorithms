#include <iostream>
#include <stack>
using namespace std;

class Stack {
    private:
        int top;
        int maxSize;
        int* stackArray;
        
    public:
    Stack(int size){
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1; 
    }
    
    ~Stack(){
        delete[] stackArray;
    }
    bool isEmpty(){         }
    
    bool isFull(){         }
    
    void push(int value) {        }
    
    void pop() {        }
    
    int peek() {        }
    
};

int main(){
    Stack stack(5);
    
    cout << "Is Empty?: " << stack.isEmpty() << endl;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    cout << "Is Full?: " << stack.isFull() << endl;
    
    stack.push(40);
    stack.push(50);
    
    cout << "Top Element: " << stack.peek() << endl; 
    
    cout << "Is Full?: " << stack.isFull() << endl;
    
    stack.pop();
    
    return 0;
}

//int main() {
    //cout << "";

    //return 0;
