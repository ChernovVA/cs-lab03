#include "histogram.h"

void find_minmax(vector<double> numbers, double& min, double& max)
{
    if(numbers.size()==0)
    {
        return;
    }
    min = numbers[0];
    max = numbers[0];

    for(double elem: numbers)
    {
        if(elem > max)
        {
            max = elem;
        }
        else if(elem < min)
        {
            min = elem;
        }
    }
}
