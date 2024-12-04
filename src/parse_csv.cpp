#include "parse_csv.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

// ANSI color codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// using namespace std;
parse_csv::parse_csv(string file_path)
{
    ifstream file(file_path);
    string line;

    while (getline(file, line))
    {
        vector<string> row = parse_line(line);
        data.push_back(row);
    }

    file.close();

    int num_columns = data[0].size();
}

vector<string> parse_csv::parse_line(string line)
{
    vector<string> result;

    string word;
    istringstream stream(line);

    while (getline(stream, word, ','))
    {
        result.push_back(word);
    }

    return result;
}

void parse_csv::print_csv()
{

    vector<int> widths = column_width();

    for (int i = 0; i < num_columns; i++)
    {
        string current_string = data[0][i];

        int current_string_len = current_string.length();
        int num_spaces = 0;
        if (current_string_len < widths[i])
        {
            num_spaces = widths[i] - current_string_len;
        }

        cout << GREEN << data[0][i] << "\t" << endl;
    }

    for (const vector<string> &i : data)
    {
        int itr = 0;
        for (const string &j : i)
        {
            int current_string_len = j.length();
            int num_spaces = 0;

            if (current_string_len < widths[itr])
            {
                num_spaces = widths[itr] - current_string_len;
            }

            cout << GREEN << j << setw(num_spaces) << "\t" << RESET;
            itr++;
        }
        cout << endl;
    }
}

vector<int> parse_csv::column_width()
{

    vector<int> column_widths;

    for (int i = 0; i < num_columns; i++)
    {
        column_widths.push_back(0);
    }

    for (const vector<string> &i : data)
    {
        int itr = 0;
        for (const string &j : i)
        {
            const int current_string_width = j.length();
            if (current_string_width > column_widths[itr])
            {
                column_widths[itr] = current_string_width;
            }
            itr++;
        }
    }

    return column_widths;
}


void parse_csv::print_line() {
    
}