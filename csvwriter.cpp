#include "csvwriter.h"
#include"csvreader.h"

#include <iostream>
#include <fstream>
//#include <string>

using namespace std;

CSVwriter::CSVwriter()
{

}


CSVwriter::CSVwriter(string fName)
{
    fileName = fName;
}


void CSVwriter::open(string fName)
{
    fileName = fName;
}


void CSVwriter::get_data(CSVReader obj_in)
{
    colNames = obj_in.colNames_vect;
    data2save = obj_in.result_out;
}


void CSVwriter::get_data(data_typ myData, vector<string> colNam)
{
    colNames = colNam;
    data2save = myData;
}


void CSVwriter::unit_writing(ofstream & f_in, vector<string> colNs, data_typ mydata, int indx=0)
{

    for (auto ptx :colNs)
    {
        if (ptx == colNs[0])
        {
            f_in <<mydata.first[ptx][indx];
        }
        else
        {
            f_in <<delimt<<mydata.second[ptx][indx];
        }
    }
    f_in <<"\n";
}


void CSVwriter::save()
{
    ofstream fout;
    vector <string>::iterator vs_int;
    int nb_lign = data2save.first[colNames[0]].size();

    fout.open(fileName);

    bool first_ele = false;
    for (auto ptx:colNames)
    {
        if (!first_ele){
            fout <<ptx;
            first_ele = true;}
        else{fout <<delimt<<ptx;}
    }
    fout<<"\n";

    for (int idx=0; idx<nb_lign; idx++)
    {
        unit_writing(fout, colNames, data2save, idx);
    }

//    fout<<"\n";
    fout.close();

}
