#include "my_lib.h"

double medianos_skaiciavimas(vector<int> vektorius) {
    int vektoriaus_ilgis = vektorius.size();

    if (vektoriaus_ilgis == 0) {
        return 0; // jei vektoriaus dydis lygus 0, grazinamas 0
    }

    std::sort(vektorius.begin(), vektorius.end()); // vektoriaus elementai surusiuojami didejimo tvarka

    if (vektoriaus_ilgis % 2 == 0) {
        // jei vektoriaus dydis lyginis, grazinamas vidurkis tarp dvieju viduriniu elementu
        return (vektorius[vektoriaus_ilgis / 2 - 1] + vektorius[vektoriaus_ilgis / 2]) / 2.0;
    } else {
        // jei vektoriaus dydis nelyginis, grazinamas vidurinis elementas
        return (vektorius[vektoriaus_ilgis / 2]);
    }
}
