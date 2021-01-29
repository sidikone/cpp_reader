#include "display.h"
#include "csvreader.h"
#include <iostream>

using namespace std;
display::display()
{

}


void display::get_data(CSVReader obj_in)
{
    colNames = obj_in.colNames_vect;
    data2save = obj_in.result_out;
}


void display::unit_printing(vector<string> colNs, data_typ mydata, int indx=0)
{

    for (auto ptx :colNs)
    {
        if (ptx == colNs[0])
        {
            cout <<mydata.first[ptx][indx];
        }
        else
        {
            cout <<"\t"<<mydata.second[ptx][indx];
        }
    }
    cout <<"\n";
}


void display::show()
{
    vector <string>::iterator vs_int;
    int nb_lign = data2save.first[colNames[0]].size();

    bool first_ele = false;
    for (auto ptx:colNames)
    {
        if (!first_ele){
            cout <<ptx;
            first_ele = true;}
        else{cout <<"\t"<<ptx;}
    }
    cout<<"\n";

    for (int idx=0; idx<nb_lign; idx++)
    {
        unit_printing(colNames, data2save, idx);
    }

    cout<<"\n";
}


void display::get_data(data_typ data_in, vector<string> col_in)
{
    data2save = data_in;
    colNames = col_in;
}


void display::head(int nb)
{
    int count = 0;
    vector <string>::iterator vs_int;
    int nb_lign = data2save.first[colNames[0]].size();

    bool first_ele = false;
    for (auto ptx:colNames)
    {
        if (!first_ele){
            cout <<ptx;
            first_ele = true;}
        else{cout <<"\t"<<ptx;}
    }
    cout<<"\n";

    for (int idx=0; idx<nb_lign; idx++)
    {   ++count;
        unit_printing(colNames, data2save, idx);

        if (count == nb){break;}
    }

    cout<<"\n";

}


void display::tail(int nb)
{
    vector <string>::iterator vs_int;
    int nb_lign = data2save.first[colNames[0]].size();

    int nb_start = nb_lign - nb;

    bool first_ele = false;
    for (auto ptx:colNames)
    {
        if (!first_ele){
            cout <<ptx;
            first_ele = true;}
        else{cout <<"\t"<<ptx;}
    }
    cout<<"\n";

    for (int idx=nb_start; idx<nb_lign; idx++)
    {
        unit_printing(colNames, data2save, idx);
    }

    cout<<"\n";
}


