// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
    fstream infile;
    char data[100];
    string dir = "./";

    int i = 1;
    for (i; i < argc - 1; i++) {
        string dir1 = dir+argv[i];
        infile.open(dir1,ios::in);
        cout << dir1 + "\n" ;
        if (!infile) {
            cerr << "\nCan't open file!\n";
            exit(1);
        }
    }

    while(infile.getline(data,sizeof(data),'\n')){
        cout<<data<<endl;
    }


    return 0;
}
