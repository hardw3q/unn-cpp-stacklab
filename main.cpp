#include <iostream>
#define size 25
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
class Stack{
    private:
        int top;
        T mem[size]
    public:
        Stack(){
            top = -1
        }
        void push(T val){
            top++;
            mem[top] = val;
        }
        T pop(){
            T result = mem[top];
            top--
            return result;
        }
};