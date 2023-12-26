#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "date.h"
#include "income.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    vector<Income> objects;
    ifstream file_stream("resources.txt");

    if (!file_stream.is_open()) {
        cerr << "cant open file" << endl;
        return 1;
    }

    while (!file_stream.eof()){
        Income file;
        file.read(file_stream);
        objects.push_back(file);
    }

    for (const Income& obj : objects)
        obj.print();

    return 0;
}