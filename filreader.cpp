#include "filreader.h"
#include "csvreader.h"
#include <iostream>
#include <algorithm>

using namespace std;

FILreader::FILreader(string fname, char sep, bool indx) : CSVReader()
{
    delimeter = sep;
    initialisation(fname);
    loadData();

    bool  indx_exist = count(colNames_vect.begin(), colNames_vect.end(), "indx");

    if (indx && !indx_exist)
        add_indx_numbr();

    info();

}

