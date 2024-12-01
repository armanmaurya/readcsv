#include<string>
#include "parse_csv.hpp"

using namespace std;
int main(int argc, char const *argv[])
{
    string file_path = "example.csv";

    parse_csv csv(file_path);
    csv.print_csv();
}
