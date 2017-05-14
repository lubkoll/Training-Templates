#pragma once

#include <array>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

struct Widget;

std::vector< std::shared_ptr<Widget> > processed_widgets;

struct Widget : std::enable_shared_from_this<Widget>
{
    static std::shared_ptr<Widget> create()
    {
        return std::shared_ptr<Widget>(new Widget);
    }

    void process()
    {
        // wrong: processed_wigets.emplace_back(this);
        processed_widgets.emplace_back(shared_from_this());
    }

private:
    Widget() = default;
};

void section_shared_ptr()
{
}

