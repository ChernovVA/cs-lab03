#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED

#include <vector>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <string>


using namespace std;

struct Input {
    vector<double> numbers;
    size_t bin_count;
};

void find_minmax(const vector<double> numbers, double& min, double& max);
void svg_begin(double width, double height);
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "red");
void svg_text(double left, double baseline, string text);
void svg_end();
void show_histogram_svg(const vector<size_t>& bins, size_t number_count);
string make_info_text();
int input_width(size_t number_count, double BLOCK_WIDTH,  istream& in);

#endif // HISTOGRAM_H_INCLUDED
