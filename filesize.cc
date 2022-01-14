#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// output format to use IDENTICALLY:
//BSH:Saru> ./filesize input.3lines input.1line 
//program: ./filesize
// input.3lines: 3
// input.1line: 1

int countLines(string filename);

int main( int argc, char* argv[] )
{
    std::cout << "program: ./filesize" << '\n';

    for (int arg = 1; arg < argc; ++arg) {
        string filename;
        filename.assign(argv[arg]);
        std::cout << " " << argv[arg] << ": " << countLines(filename) << '\n';
    }

    exit(0); // this means that the program executed correctly!
}

int countLines(string filename) {
    int lines = 0;
    string line;

    ifstream file;
    file.open(filename);

    if (!file.is_open())
        return -1;

    while (getline(file, line))       
        lines++;
        
    return lines;
}