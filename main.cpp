//
//  main.cpp
//  Ces_Vij_Vdovina
//  Copyright (c) 2015 Lyuba_Vdovina. All rights reserved.
//

// Ces_Vij_Vdovina.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 6)
    {
        cout << "Incorrect string! Enter arguments as: 1/2 - type of cipher 1/2 - crypt/encrypt input.txt output.txt shift value/key string. \n";
        return 0;
    }
    ifstream infile;
    infile.open(argv[3], ios::in);
    ofstream outfile;
    outfile.open(argv[4], ios::trunc);
    if ((infile.fail()) || (outfile.fail()))
    {
        cout << "Error: openning file.\n";
        return 0;
    }
    switch (*argv[1])
    {
        case '1': //Шифр Цезаря
        {
            int index = atoi(argv[2]);
            if (index == 1)
            {
                cout << "Cesar cipher. Encryption.\n";
            }
            if (index == 2)
            {
                cout << "Cesar cipher. Decryption.\n";
            }
            char ch;
            int shift = atoi(argv[5]) % 256;
            string result = "";
            while (!infile.eof())
            {
                ch = infile.get();
                if (ch != EOF)
                {
                    if (index == 1)
                        ch = (ch + shift) % 256;
                    if (index == 2)
                        ch = (ch - shift) % 256;
                    result = result + ch;
                }
            }
            cout << "Result: " << result << "\n";
            outfile << result;
            break;
            
            
        }
        case '2': //Шифр Виженера
        {
            int index = atoi(argv[2]);
            if (index == 1)
                cout << "Vigenere cipher. Encryption.\n";
            if (index == 2)
                cout << "Vigenere cipher. Decryption.\n";
            char ch;
            string s = argv[5];
            string result = "";
            string::iterator i = s.begin();
            while (!infile.eof())
            {
                ch = infile.get();
                if (ch != EOF)
                {
                    if (index == 1)
                        ch = (ch + *i) % 256;
                    if (index == 2)
                        ch = (ch - *i) % 256;
                    result = result + ch;
                    if (i + 1 == s.end())
                        i = s.begin();
                    else
                        i++;
                }
            }
            cout << "Result: " << result <<"\n";
            outfile << result;
            break;
        }
        default:
        {
            cout << "Incorrect cipher number. Try again.\n";
            break;
        }
    }
    infile.close();
    outfile.close();
    return 0;
}

