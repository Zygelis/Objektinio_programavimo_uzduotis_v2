#include "headers/my_lib.h"
#include "headers/deklaravimai.h"

int main()
{
    cout << "Koki konteineri naudosite? 1 - vector, 2 - list " << endl;
    int konteinerio_pasirinkimas;
    cin >> konteinerio_pasirinkimas;

    if (konteinerio_pasirinkimas != 1 && konteinerio_pasirinkimas != 2){
        cout << "Blogai ivestas pasirinkimas, programa baigia darba" << endl;
        return 0;
    }

    if (konteinerio_pasirinkimas == 1){
        main_vector();
    }
    else{
        main_list();
    }
}