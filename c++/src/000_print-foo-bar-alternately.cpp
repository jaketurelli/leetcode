///////////////////////////////////////////////
/// @file 000_print-foo-bar-alternately.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/print-foobar-alternately/
/// @version 0.1
/// @date 2022-02-07
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

class FooBar
{
private:
    int n;
    mutex m;
    condition_variable cv;
    bool fooTurn = true;

public:
    FooBar(int n)
    {
        this->n = n;
    }

    void foo(function<void()> printFoo)
    {

        for (int i = 0; i < n; i++)
        {
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this]
                    { return fooTurn; });

            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();

            fooTurn = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar)
    {

        for (int i = 0; i < n; i++)
        {

            unique_lock<mutex> lk(m);
            cv.wait(lk, [this]
                    { return !fooTurn; });

            // printBar() outputs "bar". Do not change or remove this line.
            printBar();

            fooTurn = true;
            cv.notify_one();
        }
    }
};

void print_foo()
{
    printf("foo");
}

void print_bar()
{
    printf("bar");
}

int main(int argc, char const *argv[])
{
    FooBar foobar(2);

    thread th1(&foobar->foo, []
               { printf("foo"); });
    thread th2(foobar.foo());

    th1.join();
    th2.join();
    return 0;
}
