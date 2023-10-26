#include "my_lib.h"
#include "deklaravimai.h"

int main()
{
    cout << "Koki konteineri naudosite? 1 - vector, 2 - list " << endl;
    int konteinerio_pasirinkimas;
    cin >> konteinerio_pasirinkimas;

    while (konteinerio_pasirinkimas != 1 && konteinerio_pasirinkimas != 2) {
        cout << "Ivestas netinkamas pasirinkimas. Bandykite dar karta: " << endl;
        cout << "Koki konteineri naudosite? 1 - vector, 2 - list " << endl;
        cout << "1 - vector, 2 - list " << endl;
        cin >> konteinerio_pasirinkimas;
    }

    if (konteinerio_pasirinkimas == 1){
        main_vector();
    }
    else{
        main_list();
    }
}