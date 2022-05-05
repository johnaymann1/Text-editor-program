// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: Login.cpp // Last Modification Date: 5/3/2022
// Author1 and ID and Group: John Ayman Naim Aziz   |    20210107
// Author2 and ID and Group:
// Author3 and ID and Group:
// Teaching Assistant:
/*  Purpose: 
*Display a message to the user of what letters are allowed/required and conditions that must apply to the password.
*Ask the user to repeat the password and make sure it was entered the same twice
*Verify that the password is a strong one. If not, display to the user a message and ask him for another password. Search for rules of strong password.
Cover the password with ***** while the user is entering it.
*If registration is valid, the user profile, ID and password are added to the list of system users and stored in the user file.
 */


#include <iostream>
#include <string>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

using namespace std;

void display_password_conditions(); //Function that displays a message with the password condition
void repeat_password(string str);//Function that ask the user to repeat the password and make sure it was entered the same twice
void is_strong_password(string str);//Function that make sure that the password is strong
void hide_password(string str);//Function thar hide the pasword while entering it 
int getch();//Got this from stackoverflow because macOs doesnt have "conio.h" Library so i copied the function "getch()" that i will use in the code 
void hide_pass(char password[100]);//This function to hide the password while entering it 
void askforpass();

string pass_str;
string rep_pass_str;
char password[100]={};
char rep_pass[100]={};

int v;//will be used in the "hide_pass" function to get the length of the string

int main()
{
askforpass();
}


//___________________________________________________________________________________

void display_password_conditions()
{
    cout<<"Password conditions: \n";
    cout<<"*At least 8 characters \n";
    cout<<"*Must has a number \n";
    cout<<"*Must contain Uppercase letter, Lowercase letter, number and a Special character (~ ! @ # $ % ^ * - _ = + [ { ] } / ; : , . ? ,...ect)\n";
}

//___________________________________________________________________________________

void repeat_password(string str)
{
    
    cout<<"Enter the password again to make sure that it is correct: ";
    hide_pass(rep_pass);

            for (int i = 0; i < v; i++)
            {//Making the  repeat password as type "string" 
            rep_pass_str.push_back(rep_pass[i]);
            }
            cout<<endl;



    if(rep_pass_str != str)
    {
            cout<<"\n The password does not match , please make sure of the password and try again\n";
            cout<<"\n \n password: "<<str<<endl;
            cout<<"repeated password: "<<rep_pass_str<<endl;
            cout<<endl;
            cout<<endl;
            askforpass();
            exit(0);
    }
}

//___________________________________________________________________________________

void is_strong_password(string str)
{

while(v<8)
    {
        cout<<"The Password is too short please enter a password as required! \n";
        cout<<endl;
        askforpass();
        exit(0);
        
    }
    
bool hasUpper = false;
bool hasLower = false;
bool hasdigit = false;
bool hasSpecialchar = false;
string normalChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";

        for(int i = 0;i<v;i++)
        {
        if(islower(str[i]))
        {
            hasLower = true;
        }
        else if (isupper(str[i]))
        {
            hasUpper = true;
        }
        else if (isdigit(str[i]))
        {
            hasdigit = true;
        }
        size_t special= str.find_first_not_of(normalChars);
        if (special != string::npos)
        {
            hasSpecialchar = true;
        }
        
        }

if (hasLower && hasUpper  && hasdigit && hasSpecialchar)
        {
        //cout << "ACCEPTED PASSWORD" << endl;
        }
else
        {    

    cout<<pass_str<<" <<<< this password is not strong enough \n \n";
    askforpass();
    exit(0);
        }

}

//___________________________________________________________________________________

int getch () //Copied this function from stackoverflow because its not avalibale in macos so i can use it 
{
    int ch;
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag = newt.c_lflag & ~(ICANON|ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

void hide_pass(char password[100])
{
    
    char c;
    v=0;
    char ch = '*';
    c = getch();
    while (c != '\n' ){
    
        if (c ==127 || c==8)
        {
           
      //WE WANT TO REMOVE THE LAST ENTERED CHARACTER IN THE ARRAY "password[v]"
        
        }
        
        password[v] = c;
        v++;
        putchar(ch);
        c=getch();
    }
    
}

//___________________________________________________________________________________

void askforpass()
{
pass_str="";
rep_pass_str="";


display_password_conditions();

cout<<endl<<"Enter a password: ";       hide_pass(password);
cout<<endl;

for (int i = 0; i < v; i++)//Making the password as type "string" to use it in the functions
{  
   pass_str.push_back(password[i]);
}

is_strong_password(pass_str);

repeat_password(pass_str);

}

