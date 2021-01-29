#include "filwriter.h"
#include"csvreader.h"

#include <iostream>
using namespace std;

FILwriter::FILwriter(string fname, char sep) : CSVwriter(fname)
{
    delimt = sep;
}


void FILwriter::get_data_pointer(CSVReader * read_point)
{
    CSVwriter::get_data(*read_point);
}


void FILwriter::get_data_reference(CSVReader & read_reft)
{
    CSVwriter::get_data(read_reft);
}
