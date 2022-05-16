#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
#include<string>
#include "CS112-2022-2nd-s15s16-20210101-20210107-20210122-A4-textfunction.h";

int option;

using namespace std;

//_______________________________________________________________________________________
int main() {
    view_menu();
    cin >> option;
    options();
    system("pause > 0");
}
//______________________________________________________________________________________

void options() {
    if (option == 1)
        add_txt();
    else if (option == 2)
        view_txt();
    else if (option == 3)
        clear();
    else if (option == 4)
        view_encryption();
    else if (option == 5)
        Decrypt();
    else if (option == 6)
        merge();
    else if (option == 7)
        countwords();
    else if (option == 8)
        countletters();
    else if (option == 9)
        countlines();
    else if (option == 10)
        findword();
    if (option == 11)
        counting_repeated_word();
    else if (option == 12)
        upper_case();
    else if (option == 13)
        lower_case();
    else if (option == 14)
        captilize_first_letter();
    else if (option == 15)
        save_file();

}
//______________________________________________________________________________________


