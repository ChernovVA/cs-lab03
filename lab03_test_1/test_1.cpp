#include "histogram.h"

#include <cassert>
#include <sstream>

void test1 ()
{
    stringstream in_t ("400");
    double res = input_width (5, 10, in_t);
    assert(res == 400);
}
void test2 ()
{
    stringstream in_t ("1000");
    double res = input_width (5, 10, in_t);
    stringstream im ("500");
    res = input_width (5, 10, in_t);
    assert(res == 500);

}
void test3 ()
{
    stringstream in_t ("30");
    double res = input_width (5, 10, in_t);
    assert(res == 30);
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}

