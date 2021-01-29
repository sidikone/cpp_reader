#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <utility>
#include <string>
#include <vector>
#include <map>
#include <fstream>


using data_typ = std::pair <std::map<std::string, std::vector<std::string>>, std::map<std::string, std::vector<float>>>;

class CSVReader;

class CSVwriter
{
    std::string fileName;
    std::vector <std::string> colNames;
    data_typ data2save;


protected:
    char delimt = ',';
    void unit_writing(std::ofstream &, std::vector<std::string>, data_typ, int);


public:
    CSVwriter();
    CSVwriter(std::string);

    void open (std::string);
    void get_data (CSVReader);
    void get_data(data_typ, std::vector<std::string>);
    void save ();

};

#endif // CSVWRITER_H
