#ifndef CSVREADER_H
#define CSVREADER_H

#include "csvwriter.h"
#include "display.h"

#include <string>
#include <tuple>
#include <vector>
#include <map>

using data_typ = std::pair <std::map<std::string, std::vector<std::string>>, std::map<std::string, std::vector<float>>>;

class CSVReader
{
private:

    std::string fileName;
    int fileLength = 0;
    std::string colNames;

protected:
    data_typ result_out;
    std::vector<std::string> colNames_vect;
    char delimeter = ',';
    void initialisation(std::string);
    void columns_stl();
    std::vector<std::string> string2vect(std::string);
    void get_columns (std::string);



public:

//  Constructor
    CSVReader();
    CSVReader(std::string, bool=false);


// Methods
    std::vector <std::string> columns();
    void col_names_displ ();
    void open(std::string);
    void info ();
    void loadData();
    void add_indx_numbr();

    data_typ getData();

// friend class
    friend void CSVwriter::get_data (CSVReader);
    friend void display::get_data(CSVReader);


};

#endif // CSVREADER_H
