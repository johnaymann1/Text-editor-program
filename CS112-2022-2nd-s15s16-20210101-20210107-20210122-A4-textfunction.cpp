#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
#include<string>
#include "CS112-2022-2nd-s15s16-20210101-20210107-20210122-A4-textfunction.h";
using namespace std;

char name[50];
string words;

void view_menu() {
    cout << "Hello user\nPlease enter the name of the file you want to process:\n";
    cin >> name;
    strcat_s(name, ".txt");
    cout << "please enter the option you want\n1-Add content to text file\n2-view the content\n3- clear file content\n4-Encrypt the file content\n5-Decrypt the file content\n";
    cout << "6-merge another file\n7-count the number of words\n8-count the number of characters\n9-count the number of lines\n10-search for a word in file\n";
    cout << "11-count the number of times a word exists in the file\n12-turn the content to upper case\n13-turn the content to lower case\n14-turn file content to first caps\n15-save\n16-Exit\n";
}
void add_txt() { // adding text to the file
    string added_txt;
    cout << "please enter the text you want to add and (CTRL + Z) to stop :)\n";// ctrl + z represent the eof
    ofstream fout(name, ios::app); //open append mode
    std::cin >> std::ws; // to avoid errors due to using getline with cin
    while (getline(cin, added_txt)) {
        fout << endl << added_txt;
    }
    fout.close();
}
//_______________________________________________________________________________________
void view_txt() { // cout the CONTENT ON THE SCREEN
    ifstream fin(name); //open import mode
    while (getline(fin, words))
        cout << words << endl;
    fin.close();
}
//_______________________________________________________________________________________
void clear() { // clear the content
    ofstream clear(name);
    clear << ""; // replace teh content with an empty string
    clear.close();
}
//_______________________________________________________________________________________
void view_encryption() {
    fstream myfile;
    myfile.open(name, ios::in); // store data from the file in a vector of type string
    vector<char> sentence;
    while (getline(myfile, words)) {
        for (int i = 0; i < words.length(); i++) {
            words[i] = (char)(words[i] + 1);
            sentence.push_back(words[i]); // add content to the vector
        }
        sentence.push_back('\n'); //add a new line
    }
    myfile.close();
    myfile.open(name, ios::out);
    for (int i = 0; i < sentence.size(); i++)
        myfile.put(sentence[i]); // store the new encrypted data
    myfile.close();
}
//____________________________________________________________________________
void Decrypt() { // inverse of the encryption and work with the same mechanism
    fstream myfile;
    myfile.open(name, ios::in);
    vector<char> sentence;
    while (getline(myfile, words)) {
        for (int i = 0; i < words.length(); i++) {
            words[i] = (char)(words[i] - 1);
            sentence.push_back(words[i]);
        }
        sentence.push_back('\n');
    }
    myfile.close();
    myfile.open(name, ios::out);
    for (int i = 0; i < sentence.size(); i++)
        myfile.put(sentence[i]);
    myfile.close();
}
//_______________________________________________________________________________
void merge() {
    fstream myfile;
    vector<char> sentence;
    string merged_file;
    cout << "please enter the name of the file you want to merge\n";
    cin >> merged_file;
    myfile.open(merged_file, ios::in);
    while (getline(myfile, words)) {
        for (int i = 0; i < words.length(); i++) {
            sentence.push_back(words[i]); // add content to the vector
        }
        sentence.push_back('\n'); //add a new line
    }
    myfile.close();
    myfile.open(name, ios::app);
    myfile.put('\n');
    for (int i = 0; i < sentence.size(); i++)
        myfile.put(sentence[i]);
    myfile.close();
}
//_______________________________________________________________________________
void countwords() {
    ifstream fin(name); //opening text file
    int count = 0; //will not count first word so initial value is 1
    while (fin >> words)
        count++;
    cout << "Number of words are " << count << endl;
    fin.close();
}
//___________________________________________________________________________________
void countletters() {
    ifstream fin(name); //opening text file
    char ch;
    int count = 0;
    while (fin >> ch) {
        if (ch != 13) {
            count++;
        }
    }fin.close();
    cout << "Number of letters are " << count << endl;
}
//___________________________________________________________________________________

void countlines() {
    int count = 0;
    ifstream fin(name); //open import mode
    while (getline(fin, words))
        count++;
    fin.close();
    cout << "Number of lines is " << count << endl;
}
//___________________________________________________________________________________

void findword()
{
    string str, word;
    cout << "enter the word you search for";
    cin >> word;
    ifstream fileinput(name); //opening text file

    if (!fileinput.is_open())
    {

        cout << "file not found";
    }
    else
    {
        while (fileinput >> str)//taking every word and comparing with replaceStr
        {
            if (str.find(word) != std::string::npos)
            {
                cout << "found!" << '\n';
                break;
            }
            else
            {
                cout << "not found" << '\n';
                break;
            }
        }
    }

    fileinput.close(); //closing file

}
//______________________________________________________________________________________
void counting_repeated_word() {
    fstream myfile;
    string line, word;
    int count = 0;
    cout << "enter the word you search for:";
    cin >> word;
    myfile.open(name, ios::in);//open the file in the reading mode
    while (getline(myfile, line)) //store from the file and put in te line
    {
        if (line.find(word) != string::npos)//build in function to check the word in the file or not
            count++; //increasing the counter


    }
    myfile.close();
    cout << "the word " << word << " reapeted  " << count << " times ";
}
void upper_case() {
    fstream myfile;
    char ch;
    vector<char>container;// vector of type char
    myfile.open(name, ios::in);//open the file in the read mode
    while (!myfile.eof())//looping until the end of the file
    {
        myfile.get(ch);//taking every character in the file and store it
        container.push_back(toupper(ch));//converting the charactars to upper case and pushback to the vector
    }
    myfile.close();
    myfile.open(name, ios::out);//open the file in the write mode
    for (int i = 0; i < container.size(); i++)//looping on the vector
        myfile.put(container[i]);//store in the file
    myfile.close();
}
void lower_case() {
    fstream myfile;
    char ch;
    vector<char>container;// vector of type char
    myfile.open(name, ios::in);//open the file in the read mode
    while (!myfile.eof())//looping until the end of the file
    {
        myfile.get(ch);//taking every character in the file and store it
        container.push_back(tolower(ch));//converting the charactars to lower case and pushback to the vector
    }
    myfile.close();
    myfile.open(name, ios::out);//open the file in the write mode
    for (int i = 0; i < container.size(); i++)//looping on the vector
        myfile.put(container[i]);//store in the file
    myfile.close();
}
void captilize_first_letter() {
    fstream myfile;
    char ch;
    bool line = false;//bool variable
    int i = 0;
    string data;//variable to save data
    myfile.open(name, ios::in);//open in the read mode
    while (!myfile.eof()) //looping to the end of the file
    {
        myfile.get(ch);//taking every character in the file
        ch = tolower(ch);//converting all the char to lower case
        if (line == true) //checking the case lower the code
        {
            ch = toupper(ch); //converting to upper
            line = false;//returning line to false
        }
        if (i == 0)// this function to convert the first letter in the file to upper case
        {
            i = 1;
            ch = toupper(ch);
        }

        if (ch == ' ' || ch == '\n')  //checking if new line or space and start word
        {
            line = true;//return line to true and convert to upper
        }
        data += ch;//store the data in variable
    }

    myfile.close();
    myfile.open(name, ios::out);
    myfile << data;
    myfile.close();
}

void  save_file() {
    int choice1;
    cout << "1/save the edits in the same file" << endl << "2/save the edits in new file";
    cin >> choice1;
    if (choice1 == 1)//the user chose if he want to save in the same file
        cout << "the edits saved sucessfully";
    else if (choice1 == 2)  //the user wants to save the edits in new file
    {
        char name2[90], c;
        cout << "enter the new file";
        cin >> name2;
        ifstream old_file;//open the old file to read
        ofstream new_file;// open the new file to write
        old_file.open(name, ios::in);
        new_file.open(name2, ios::out);
        while (old_file.get(c)) //taking every character from the old file
        {
            new_file.put(c);//put it in the new file

        }
        old_file.close();//closing the files
        new_file.close();
        cout << "data saved";
    }
}