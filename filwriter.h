#ifndef FILWRITER_H
#define FILWRITER_H

#include "csvwriter.h"

class CSVReader;
class FILwriter : public CSVwriter
{
public:
    FILwriter(std::string, char = ',');
    void get_data_pointer(CSVReader *);
    void get_data_reference(CSVReader &);
};

#endif // FILWRITER_H
