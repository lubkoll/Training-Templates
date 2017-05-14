#pragma once

#include <iostream>
#include <memory>

struct Base
{
    virtual ~Base() = default;
    virtual void foo() const = 0;
    virtual void bar() const = 0;
};

struct Derived : Base
{
    // Always use 'override' when overriding virtual functions.
    void foo() const override
    {
        std::cout << "Derived::foo" << std::endl;
    }

    // Use 'final' when 'bar' should not be overwritten in classes deriving from 'Derived'
    void bar() const final override
    {
        std::cout << "Derived::bar should not be overwritten" << std::endl;
    }
};

void final_and_override_example()
{
    std::unique_ptr<Base> base = std::make_unique<Derived>();
    base->foo();
    base->bar();
}
