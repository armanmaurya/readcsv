#include<string>
#include<vector>

using namespace std;
class parse_csv {
    public:
        parse_csv(string file_path);
        void print_csv();

    private:
        vector<vector<string>> data;
        vector<string> parse_line(string line);
        void print_line();
        vector<int> column_width();
        int num_columns;
	bool is_number(const string& str);
};

