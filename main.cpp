#include <iostream>
#include <typeinfo>
#include "csvreader.h"
#include "csvwriter.h"
#include "display.h"

#include "filreader.h"
#include "filwriter.h"

#include <tuple>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <iterator>
#include <map>

#include <sstream>
#include <eigen3/Eigen/Dense>
#include <ctime>
#include <chrono>


using namespace std;

using namespace Eigen;

int main(int argc, const char* argv[])

{
//    int ab = 3;
//    int *p_int;
//    p_int = &ab;

//    cout << "\t\t"<< &ab << endl;
//    cout << "\t\t"<< *p_int <<"\n"<< endl;

//    int & r_int = ab;
////    r_int = ab;

//    cout << "\t\t"<< &r_int << endl;
//    cout << "\t\t"<< r_int <<"\n"<< endl;


    auto tim_start = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout <<"Debut du prog : "<< ctime(&tim_start) << endl;

    CSVReader myData3("data/mon_fichier_3.csv", true);

//    CSVReader myData4();

    FILreader myData10("data/mon_fichier_42.txt", '\t', true);
    myData10.info();






//    read_point = &myData3;
//    read_point->info();
//    CSVReader & read_ref = myData3;
//    cout <<"\t\t\t\t\t\t"<< &read_ref << endl;
//    read_ref.info();


    CSVwriter write("data/mon_fichier_42.csv");
    write.get_data(myData3);
    write.save();

//    FILwriter write2("data/mon_fichier_42.txt", '\t');
//    write2.get_data(myData3);
//    write2.save();

//    FILwriter write3("data/mon_fichier_21.txt", '\t');
//    write3.get_data_pointer(read_point);
//    write3.save();


//    FILwriter write4("data/mon_fichier_32.txt", '\t');
//    write4.get_data_reference(myData3);
//    write4.save();

//    CSVReader myData4 = myData3;

//    MyFil myData5("data/mon_fichier_4.csv");

//    display disp;
//    disp.get_data(myData3);
////    disp.show();
//    cout <<"\n\n\n";
//    disp.head(3);

//    cout <<"\n\n\n";
//    disp.tail(3);

    auto tim_end = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout <<"Fin du prog : "<< ctime(&tim_end) << endl;


    return 0;
}


