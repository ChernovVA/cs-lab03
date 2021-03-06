#include "histogram.h"

int input_width(size_t number_count, double BLOCK_WIDTH,  istream& in)
{
    int image_width;
    cerr << "Enter SCREEN_WIDTH:";
    in >> image_width;
    while(image_width < 70 || image_width > 800 || image_width < 1/3*(number_count*BLOCK_WIDTH))
    {
        cerr << "invalid input(<70/>800/<0,33*numbers_count*BLOCK_WIDTH), please enter again";
        cerr << "Enter SCREEN_WIDTH:";
        in >> image_width;
    }
    return image_width;
}


void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
    cout << "<rect x=' " << x << " ' y=' " << y << " ' width=' " << width << " ' height=' " << height << " ' stroke= ' " << stroke << " ' fill= ' " << fill << " ' /> " << endl;
}

void svg_text(double left, double baseline, string text)
{
    cout << "<text x=' " << left << " ' y=' " << baseline << " '> " << text << " </text>" << endl;
}

void svg_end()
{
    cout << "</svg>\n";
}

void show_histogram_svg(const vector<size_t>& bins, size_t number_count)
{
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
    //const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    auto IMAGE_WIDTH = input_width(number_count, BLOCK_WIDTH, cin);
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    size_t max_count = bins[0];
    for (size_t bin : bins)
    {
        if (bin > max_count)
        {
            max_count = bin;
        }
    }
    for (size_t bin : bins)
    {
        const double bin_width = BLOCK_WIDTH * bin;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        top += BIN_HEIGHT;
    }
    top=0;
    cin.ignore();
    if (max_count > MAX_ASTERISK )
    {
        for(size_t bin : bins)
        {
            const double bin_width = static_cast <double> (IMAGE_WIDTH - TEXT_LEFT)/max_count * bin;
            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "black", "red");
            top+=BIN_HEIGHT;
        }
    }
    else
    {
        for(size_t bin : bins)
        {
            const double bin_width = BLOCK_WIDTH * bin;
            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "black", "red");
            top+=BIN_HEIGHT;
        }
    }
    svg_end();
}
