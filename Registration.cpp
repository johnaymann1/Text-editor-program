/*
 FCI – Programming 1 – 2022 - Assignment 4
 Program Name: Registration.cpp
 Last Modification Date: 14/05/2022
 Author1 and ID and Group: Gasser Ahmed     20210101  B
 Author2 and ID and Group: John Ayman       20210107  B
 Author3 and ID and Group: Habiba Magdy     20210122  B
 Teaching Assistant: Eng / Yousra        s15/s16
 Purpose: The programme helps the user to login fo existing account or register a new user.
 version : 3.0
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <regex>
#include <iomanip>
#include <conio.h>
#include "CS112-2022-2nd-s15s16-20210101-20210107-20210122-A4-FULL.h"

using namespace std;

int main()
{
    int choice;
    cout << "Hello user\nplease enter\n1- To register new user\n2- To login as an existing user\n3- Change pass\n4- Exit\n";
    cin >> choice;
    // registering a new user will require: username / gmail / pass and phone no.
    if (choice == 1) {
        get_user();
        get_mail();
        get_pass();
        get_phone();
    }
    else if (choice == 2) {
        login(); //login to a previously registered user
    }
    else if (choice == 3) {
        change_password(); // change your password
    }
    else if (choice == 4) {
        exit(1);// exit choice
    }
    else {
        cout << "invalid choice\n";
        main();
    }
}