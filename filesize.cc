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
    std::cout << "./filesize" << '\n';

    // just to get you started, this is how to refer to the arguments that were passed
    for (int arg = 1; arg < argc; ++arg) {
        string filename;
        filename.assign(argv[arg]);
        std::cout << argv[arg] << ": " << countLines(filename) << '\n' ;
    }

    exit(0); // this means that the program executed correctly!
}

int countLines(string filename) {
    int lines = -1;
    string line;

    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        return -1;
        
    }

    do {
        lines++;
        getline(file, line);
    } while (!file.eof());

    return lines;

}