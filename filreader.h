#ifndef FILREADER_H
#define FILREADER_H

#include "csvreader.h"

class FILreader : public CSVReader
{
public:
    FILreader(std::string, char=',', bool=false);
};

#endif // FILREADER_H
