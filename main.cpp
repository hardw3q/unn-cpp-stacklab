#include <iostream>
#define size 25
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// // Первая реализация с помощью массива
//class Stack{
//    private:
//        int top;
//        T mem[size]
//    public:
//        Stack(){
//            top = -1
//        }
//        void push(T val){
//            top++;
//            mem[top] = val;
//        }
//        T pop(){
//            T result = mem[top];
//            top--
//            return result;
//        }
//};

// std:vector
// push_back()
// pop_back()

class Stack{
    private:
        int top;
        std::vector<T> mem;
    public:
        void push(T val){
            top++;
            mem.push_back(val);
        }
        void pop(){
            return mem.pop_back();
        }

};