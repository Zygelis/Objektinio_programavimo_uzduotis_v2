#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>

using std::cout; 
using std::string;
using std::cin;
using std::endl;
using std::vector;

struct studentas {
  string vardas, pavarde;
  vector <int> paz;
  int egz;
  float rez;
};

double medianos_skaiciavimas(vector<int> vec);
vector<int> random_skaicius(int n);