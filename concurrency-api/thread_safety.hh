#pragma once

#include <iostream>
#include <mutex>
#include <stack>
#include <thread>

namespace thread_safety
{
    template <class T>
    class Stack
    {
    public:
        const T& top() const
        {
            return data.top();
        }

        void push(const T& t)
        {
            data.push(t);
        }

        void pop()
        {
            data.pop();
        }

        std::size_t size() const
        {
            return data.size();
        }

        bool empty() const
        {
            return data.empty();
        }

    private:
        std::stack<T> data;
    };


    void do_something(int value)
    {
        static std::mutex mutex;
        std::lock_guard<std::mutex> lock(mutex);
        std::cout << "value = " << value << std::endl;
    }

    void example()
    {
        Stack<int> stack;
        stack.push(1);
        stack.push(2);

        auto task = [&stack]
        {
            if(!stack.empty())
            {
                const auto value = stack.top();
                stack.pop();
                do_something(value);
            }
        };

        std::thread t1(task),
                    t2(task);
        t1.join();
        t2.join();
    }
}
