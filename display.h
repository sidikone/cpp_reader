#ifndef DISPLAY_H
#define DISPLAY_H

#include<vector>
#include<string>
#include<map>

using data_typ = std::pair <std::map<std::string, std::vector<std::string>>, std::map<std::string, std::vector<float>>>;

class CSVReader;

class display
{
    std::vector <std::string> colNames;
    data_typ data2save;

protected:
    void unit_printing(std::vector<std::string>, data_typ, int);

public:
    display();
    void get_data(CSVReader);
    void get_data(data_typ, std::vector <std::string>);
    void show ();
    void head(int);
    void tail(int);

};

#endif // DISPLAY_H
