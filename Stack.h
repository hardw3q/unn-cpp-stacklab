#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

template <typename T>
class Stack
{
private:
    std::vector<T> stack;

public:
    Stack() {}

    void push(const T &value)
    {
        stack.push_back(value);
    }

    T pop()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Stack is empty");
        }

        T value = stack.back();
        stack.pop_back();
        return value;
    }

    void print() const
    {
        for (size_t i = 0; i < stack.size(); ++i)
        {
            std::cout << stack[i] << " ";
        }
        std::cout << std::endl;
    }

    bool isEmpty() const
    {
        return stack.empty();
    }

    size_t size() const
    {
        return stack.size();
    }
};

#endif