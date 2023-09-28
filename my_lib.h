#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>

using std::cout; 
using std::string;
using std::cin;
using std::endl;
using std::vector;

struct studentas {
  string vardas, pavarde;
  vector <int> paz;
  int egz;
  double rez;
};

double medianos_skaiciavimas(vector<int> vec);
vector<int> random_skaicius(int n);
bool palyginimas_pagal_varda(const studentas &a, const studentas &b);
void ivedimas_is_file(vector<studentas>& grupe, char vm_pasirinkimas);
studentas rankinis_ivedimas();
studentas atsitiktinis_ivedimas();
double galutinio_balo_skaiciavimas(char vm_pasirinkimas, studentas& laikinas);