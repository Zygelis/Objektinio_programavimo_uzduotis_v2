#include "my_lib.h"

int main()
{
    studentas laikinas;
    vector<studentas> grupe;
    cout << "Kiek studentu norite ivesti?";
    int n;
    cin >> n;

    char choice;
    cout << "Skaiciuoti galutini bala vidurkiu (v) arba mediana (m)? ";
    cin >> choice;
    if (choice != 'v' && choice != 'm')
    {
        cout << "Neteisinga pasirinkimo reiksme. Naudojamas vidurkis." << endl;
        choice = 'v';
    }

    for (int j = 0; j < n; j++)
    {
        cout << "Iveskite varda ir pavarde:";
        cin >> laikinas.vardas >> laikinas.pavarde;

        cout << "Iveskite pazymius viena po kito ir paspauskite Enter, kai baigsite. Arba iveskite 'baigti' kai baigsite pazymiu ivedima." << endl;
        string input;
        cin.ignore();
        while (true)
        {
            getline(cin, input);

            if (input == "baigti" || input.empty())
            {
                break;
            }

            try
            {
                int grade = std::stoi(input);

                if (grade < 0 || grade > 10)
                {
                    cout << "Neteisinga ivestis. Iveskite skaicius nuo 0 iki 10." << std::endl;
                    continue;
                }
                laikinas.paz.push_back(grade);
            }
            catch (const std::invalid_argument &)
            {
                cout << "Neteisinga ivestis. Iveskite naturalu skaiciu tarp 1 ir 10: " << std::endl;
            }
            catch (const std::out_of_range &)
            {
                cout << "Ivestas skaicius per didelis. Iveskite mazesni skaiciu." << std::endl;
            }
        }

        // spausdinami ivesti pazymiai
        cout << "Ivedei pazymius: ";
        for (auto &a : laikinas.paz)
            cout << a << " ";
        cout << endl;

        // ivedamas egzamino rezultatas
        while (true)
        {
            cout << "Iveskite egzamino rezultata: ";
            string egzrez_laikinas;
            cin >> egzrez_laikinas;

            try
            {
                int input = std::stoi(egzrez_laikinas);

                if (input < 1 || input > 10)
                {
                    cout << "Egzamino rezultatas turi buti tarp 1 ir 10: " << endl;
                }
                else
                {
                    laikinas.egz = input;
                    break;
                }
            }
            catch (const std::invalid_argument &)
            {
                // jei ivestis yra ne skaicius, prasoma ivesti is naujo
                cout << "Neteisinga ivestis. Iveskite naturalu skaiciu tarp 1 ir 10: " << endl;
            }
            catch (const std::out_of_range &)
            {
                cout << "Ivestas skaicius per didelis. Iveskite mazesni skaiciu." << std::endl;
            }
        }

        cout << "Ivedei egzamina: " << laikinas.egz << endl;
        cin.ignore();

        if (choice == 'v')
        {
            // skaičiuojama pagal vidurki
            double mean = std::accumulate(laikinas.paz.begin(), laikinas.paz.end(), 0.0) / laikinas.paz.size();
            laikinas.rez = 0.4 * mean + 0.6 * laikinas.egz;
        }
        else if (choice == 'm')
        {
            // skaičiuojama pagal mediana
            laikinas.rez = 0.4 * medianos_skaiciavimas(laikinas.paz) + 0.6 * laikinas.egz;
        }
        else
        {
            // jei pasirinkimas neteisingas, naudojamas vidurkis
            cout << "Neteisinga pasirinkimo reiksme. Naudojamas vidurkis." << endl;
            double mean = std::accumulate(laikinas.paz.begin(), laikinas.paz.end(), 0.0) / laikinas.paz.size();
            laikinas.rez = 0.4 * mean + 0.6 * laikinas.egz;
        }

        grupe.push_back(laikinas);
        laikinas.paz.clear();
    }

    // spausdinama lentele
    printf("|%20s|%20s|%20s|\n", "Vardas", "Pavarde", "Galutinis (Med.)");

    // spausdinama pagal pasirinkima, arba vidurkis, arba mediana:
    if (choice == 'm')
    {
        printf("|--------------------|--------------------|--------------------|\n");
        for (auto &a : grupe)
            printf("|%20s|%20s|%20.2f|\n", a.vardas.c_str(), a.pavarde.c_str(), a.rez); // %20.2f - %20 simboliu plotis, 2f skaiciai po kablelio
        // panasiai kaip su - cout << std::fixed << std::setprecision(2) << a.rez << endl;
        printf("|--------------------|--------------------|--------------------|\n");
    }
    else
    {
        printf("|--------------------|--------------------|--------------------|\n");
        for (auto &a : grupe)
            printf("|%20s|%20s|%20.2f|\n", a.vardas.c_str(), a.pavarde.c_str(), a.rez); // %20.2f - %20 simboliu plotis, 2f skaiciai po kablelio
        // panasiai kaip su - cout << std::fixed << std::setprecision(2) << a.rez << endl;
        printf("|--------------------|--------------------|--------------------|\n");
    }
}