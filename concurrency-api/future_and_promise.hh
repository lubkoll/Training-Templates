#pragma once

#include <future>
#include <iostream>

namespace future_and_promise
{
    void write()
    {
        std::cout << "Finished waiting." << std::endl;
    }

    void signals(std::promise<void> promise)
    {
        std::this_thread::sleep_for(1s); // 'std::literals::1s' available in C++14

        std::cout << "Notifying threads..." << std::endl;
        promise.set_value();
        std::this_thread::sleep_for(100ms);
    }


    void futures_for_one_shot_communication()
    {
    }

    void shared_futures_for_one_shot_communication()
    {
    }


    void packaged_task_example()
    {
    }


    void example()
    {
        futures_for_one_shot_communication();
//        shared_futures_for_one_shot_communication();
//        packaged_task_example();
        /* Note:
         * The last future referring to a shared state for a non-deferred task
         * launched via std::async blocks until the task completes! */
    }
}
