#include "parse_csv.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cctype>

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

    num_columns = data[0].size();
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

        cout << GREEN << data[0][i]  << RESET<< setw(num_spaces) << "\t" << RESET;
    }

	cout << endl;
	cout << endl;

    int rows = data.size();
    for (int i = 1; i < rows; i++) {
	    int columns = data[i].size();
	    for (int j = 0; j < columns; j++) {
		int current_string_len = data[i][j].length();
            	int num_spaces = 0;

            	if (current_string_len < widths[j])
            	{
                	num_spaces = widths[j] - current_string_len;
            	}
		
		if (is_number(data[i][j])) 
		{
			cout << RED << data[i][j] << setw(num_spaces) << "\t" << RESET;		
		}
		else
		{
          	 	cout << GREEN << data[i][j] << setw(num_spaces) << "\t" << RESET;
		}
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

bool parse_csv::is_number(const string& str){
	for (char ch : str) {
       		if (!std::isdigit(static_cast<unsigned char>(ch))) {
	            	return false; // Found a non-numeric character
        	}
    	}
    return !str.empty();
}

void parse_csv::print_line() {
    
}
