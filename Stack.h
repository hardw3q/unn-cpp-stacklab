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
    Stack() = default;

    void push(const T& value)
    {
        stack.push_back(value);
    }

    T pop()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Stack is empty");
        }

        T value = std::move(stack.back());
        stack.pop_back();
        return value;
    }

    void print() const
    {
        for (const auto& item : stack)
        {
            std::cout << item << " ";
        }
        std::cout << '\n';
    }

    bool isEmpty() const noexcept
    {
        return stack.empty();
    }

    size_t size() const noexcept
    {
        return stack.size();
    }
};

#endif // STACK_H
