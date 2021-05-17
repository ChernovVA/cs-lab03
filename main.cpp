#include <iostream>
#include <vector>

using namespace std;

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_text(double left, double baseline, string text)
{
    cout << "<text x=' " << left << " ' y=' " << baseline << " '> " << text << " </text>";
}

void svg_end()
{
    cout << "</svg>\n";
}

void show_histogram_svg(const vector<size_t>& bins)
{
    svg_begin(400, 300);
    svg_text(20, 20, to_string(bins[0]));
    svg_end();
}

vector<double> input_numbers(size_t count)
{
    vector<double> input(count);
    for (size_t i = 0; i < count; i++)
    {
        cerr << "Number " << i+1 << ") ";
        cin >> input[i];
    }
    return input;
}

void find_minmax(vector<double> numbers, double& min, double& max)
{
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

vector<size_t> make_histogram( vector<double> numbers, size_t bin_count, size_t number_count, size_t& max_in_bin)
{
    vector <size_t> bins (bin_count);

    double min, max;
    find_minmax(numbers, min, max);

    double bin_size = (max - min) / bin_count;

    for (size_t i = 0; i < number_count; i++)
    {
        bool flag = false;
        for (size_t j = 0; (j < bin_count - 1) && !flag; j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;

            if ((lo <= numbers[i]) && (numbers[i] < hi))
            {
                bins[j]++;
                flag = true;
            }
            if (bins[j]>max_in_bin)
            {
                max_in_bin=bins[j];
            }
        }
        if (!flag)
        {
            bins[bin_count - 1]++;
        }
        if (bins[bin_count - 1]>max_in_bin)
        {
            max_in_bin=bins[bin_count - 1];
        }
    }
    return bins;
}

void show_histogram_text( vector <size_t> bins, const size_t max_in_bin, const size_t MAX_HIGH)
{
    if (max_in_bin > MAX_HIGH)
    {
        for(size_t size: bins)
        {
            if(size < 10)
            {
                cout << "  ";
            }
            else
            if(size < 100)
            {
                cout << " ";
            }
            cout << size << "|";
            size_t height = MAX_HIGH * (static_cast<double>(size) / max_in_bin);
            while(height != 0)
            {
                cout << "*";
                height=height-1;
            }
            cout << endl;
        }
    }
    else
    {
        for(size_t size: bins)
        {
            if(size < 10)
            {
                cout << "  ";
            }
            else
            if(size < 100)
            {
                cout << " ";
            }
            cout << size << "|";
            while(size != 0)
            {
                cout << "*";
                size=size-1;
            }
            cout << endl;
        }
    }
}

int main()
{
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_HIGH = SCREEN_WIDTH - 3 - 1;
    size_t number_count, bin_count, max_in_bin=0;
    int i;
    cerr << "Enter number count: ";
    cin >> number_count;
    const auto numbers = input_numbers(number_count);

    cerr << "Enter bin count: ";
    cin >> bin_count;

    const auto bins = make_histogram(numbers, bin_count, number_count, max_in_bin);

    show_histogram_svg(bins);

    //show_histogram_text(bins, max_in_bin, MAX_HIGH);

    return 0;
}
