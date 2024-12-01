#include "parse_csv.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

// using namespace std;
parse_csv::parse_csv(string file_path) {
    ifstream file(file_path);
    string line;

    while (getline (file, line))
    {
        vector<string> row = parse_line(line);
        data.push_back(row);
    }
    
    file.close();
    
}

vector<string> parse_csv::parse_line(string line) {
    vector<string> result;

    string word;
    istringstream stream(line);

    while(getline(stream, word, ',')) {
        result.push_back(word);
        cout << word << endl;
    }   

    return result;
}

void parse_csv::print_csv() {
    vector<int> column_width;
    
    for (const vector<string>& i : data) {
        for (const string& j : i) {
            cout<< j << "\t";
        }

        cout <<endl;
    }
}