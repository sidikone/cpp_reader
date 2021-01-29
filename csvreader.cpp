#include "csvreader.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>
#include <iterator>
#include <tuple>
#include <map>
#include <numeric>

using namespace std;

// Constructors

CSVReader::CSVReader()
{
 /* Constructor used to built the class
  * Use the function open to load a file */
    cout << "\n Object created, to process your data, you need : " << endl;
    cout << " ---------------------------------------------- " << endl;
    cout << " 1. Open file with <open function>" << endl;
    cout << " 2. Load file with <loadData function>" << endl;
    cout << " 3. Return data to your own variable with <getData function>" << endl;
}


CSVReader::CSVReader(string fname, bool indx)
{
/* Constructor used with file name as parameter, no need to use the open methos
 * fname : string : name of the file to be load
 */
    initialisation(fname);
    loadData();

    if (indx)
        add_indx_numbr();

    info();
}


void CSVReader::initialisation(string fname)
{
/* Initialisation function, private function use to initialise the object */
    fileName = fname;
    get_columns(fname);
    columns_stl();

}


void CSVReader::open(string fname)
{
/* Open the file used after default reader constructor */
    initialisation(fname);
}


void CSVReader::info()
{
    int colsiz = colNames_vect.size();
    int linsiz = result_out.first[colNames_vect[0]].size();

    cout << "\n File info" << endl;
    cout << " ---------" << endl;
    cout << " * file name : " << fileName <<endl;
    cout << " * file shape (lines x cols) = " <<"(" << linsiz << " x " << colsiz <<")" << endl;
    cout << " * columns names :";
    col_names_displ();
    cout << "\n";
}


void CSVReader::get_columns(string fName)
{
/*private function used to get and save the columns in string variable
used on the initialisation methods*/
    fstream fin;
    string myText;

    fin.open(fName);
    getline(fin, myText);
    fin.close();

    colNames = myText;

}


vector<string> CSVReader::columns()
{
 /* Allow to access to the columns name in a string vector */
    return colNames_vect;
}


void CSVReader::col_names_displ()
{
    for (auto intx : colNames_vect)
    {
        cout << "  " << intx;
    }
    cout <<endl;
}


void CSVReader::columns_stl()
{
 /* tokeninzing the string columns name int a string vector */
    string unit_string;
    istringstream string2stream (colNames);

    while (getline(string2stream, unit_string, delimeter))
    {
        colNames_vect.push_back(unit_string);
    }
}


vector<string> CSVReader::string2vect(string str_in)
{
    /*tokeninzing a string into a vector of string */
    string unit_string;
    istringstream string2stream(str_in);
    vector <string> vect_str;

    while(getline(string2stream, unit_string, delimeter))
    {
        vect_str.push_back(unit_string);
    }
    return vect_str;
}


void CSVReader::loadData()
{
/* load the data into object private data, but the data are not return to the user*/
    fstream fin;
    string myText;
    vector <string> myVect;
    vector <string> col_vect = colNames_vect;

    int col_siz = col_vect.size();
    --col_siz;

    vector<string> index_vect;
    vector<vector <float>> data_values(col_siz);
    vector<string>::iterator vs_tr; // iterator for read

    vector<string>::iterator col_it;

    map<string, vector<float>> result_data;
    map<string, vector<string>> result_index;
//    pair <map<string, vector<string>>, map<string, vector<float>>> result_synt;
    data_typ result_synt;

    int count = 0;
    int col_count;

    fin.open(fileName);

    while (fin)
    {
        getline(fin, myText);
        if (count && fin.good())
        {
            myVect = string2vect(myText);
            index_vect.push_back(*(myVect.begin()));
            col_count = 0;
            for (vs_tr=myVect.begin()+1; vs_tr<myVect.end(); vs_tr++)
            {
                data_values[col_count].push_back(stof(*vs_tr));
                ++col_count;
            }
        }

        count++;
 //       cout <<myText<<"\n"<<endl;
    }

    fin.close();


    col_it = col_vect.begin();
    result_index.insert({*col_it, index_vect});
    col_vect.erase(col_it);

    for (int i=0; i<col_vect.size(); i++)
    {
        result_data.insert({col_vect[i], data_values[i]});
    }
    result_synt = make_pair(result_index, result_data);


    result_out = result_synt;
}


void CSVReader::add_indx_numbr()
{
    int linSiz = result_out.first[colNames_vect[0]].size();
    vector <float> num_data(linSiz);
    string colNam = "indx";
    colNames_vect.push_back(colNam);

    float init = 1; // Initialising starting value
    iota(begin(num_data), end(num_data), init);
    result_out.second.insert({colNam, num_data});

}


data_typ CSVReader::getData()
{
/*return the data to the user */
    return result_out;
}
