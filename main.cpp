/**
 * Description: A convertor between decimal <-> binary, and decimal <-> hexadecimal.
 * Author names: Koichi Nakata
 * Author emails: knakata595@insite.4cd.edu
 * Last modified date: Feb 2, 2024
 * Creation date: Feb 1, 2024
 **/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const vector<int> BIN_VAL{1, 2, 4, 8, 16, 32, 64, 128};
const vector<int> HEX_VAL{1, 16, 256, (int)pow(16, 3), (int)pow(16, 4),
                          (int)pow(16, 5), (int)pow(16, 6), (int)pow(16, 7)};

const unordered_map<char, int> HEX_DEC_VAL{{'0', 0}, {'1', 1}, {'2', 2},
                                           {'3', 3}, {'4', 4}, {'5', 5},
                                           {'6', 6}, {'7', 7}, {'8', 8},
                                           {'9', 9}, {'A', 10}, {'B', 11},
                                           {'C', 12}, {'D', 13}, {'E', 14},
                                           {'F', 15}};
const vector<char> DEC_HEX_VAL{'0', '1', '2', '3', '4', '5', '6', '7', '8',
                               '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int convertBinToDec(const string&);
long convertHexToDec(const string&);
string convertDecToBin(unsigned int);
string convertDecToHex(unsigned int);

int main() {
    string binStr = "1010";
    string hexStr = "1E";
    int dec = 100;

    cout << setw(8) << binStr << " (bin) -> " << setw(8) << convertBinToDec(binStr) << " (dec)" << endl;
    cout << setw(8) << hexStr << " (hex) -> " << setw(8) << convertHexToDec(hexStr) << " (dec)" << endl;
    cout << setw(8) << dec << " (dec) -> " << setw(8) << convertDecToBin(dec) << " (bin)" << endl;
    cout << setw(8) << dec << " (dec) -> "<< setw(8) << convertDecToHex(dec) << " (hex)" << endl;
}

/**
 * convertBinToDec performs a conversion from binary to decimal value
 * Assumption: parameter string binStr has a valid binary expression with max length of 8
 * Input parameters: binStr: binary value as a const string reference
 * Returns: dec: decimal value as as an int
**/
int convertBinToDec(const string& binStr) {
    int dec = 0;
    for (int i = 0; i < binStr.length(); i++) {
        // Note that the indices are opposite for binStr and BIN_VAL
        int index = binStr.length() - 1 - i;
        if (binStr[index] == '1') dec += BIN_VAL[i];
    }
    return dec;
}

/**
 * convertHexToDec performs a conversion from hexadecimal to decimal value
 * Assumption: parameter string hexStr has a valid format of hexadecimal with max length of 8
 * Input parameters: hexStr: hexadecimal value as a const string reference
 * Returns: dec: decimal value as a long int
**/
long convertHexToDec(const string& hexStr) {
    long dec = 0;
    for (int i = 0; i < hexStr.length(); i++) {
        // Node that indices are opposite for hexStr and HEX_DEC_VAL
        int index = hexStr.length() - 1 - i;
        int mult = HEX_DEC_VAL.at(hexStr[index]);
        // Instead, this code is also acceptable, without using the global hash table variable
//        int mult = hexStr[i] < 'A' ? hexStr[i] - '0' : (hexStr[i] - 'A') + 10;
        dec += mult * HEX_VAL[i];
    }
    return dec;
}

/**
 * convertDecToBin performs a conversion from decimal to binary value
 * Assumption: parameter dec < UINT_MAX (unsigned int max)
 * Input parameters: dec: decimal value as an unsigned int
 * Returns: binStr: binary value as a string
**/
string convertDecToBin(unsigned int dec) {
    string binStr = "";

    while (dec) {
        if (dec % 2 == 1) binStr = '1' + binStr; // The value is added to the front of the string
        else binStr = '0' + binStr;
        dec /= 2;
    }
    return binStr;
}

/**
 * convertDecToHex performs a conversion from decimal to hexadecimal value
 * Assumption: parameter dec < UINT_MAX (unsigned int max)
 * Input parameters: dec: decimal value as an unsigned int
 * Returns: hexStr: hexadecimal value as a string
**/
string convertDecToHex(unsigned int dec) {
    string hexStr = "";

    while (dec) {
        int rem = dec % 16;
        hexStr = DEC_HEX_VAL[rem] + hexStr; // The value is added to the front of the string
        // Instead, this code is also acceptable, without declaring the global vector
//        char ch = rem < 10 ? '0' + rem : 'A' + (rem - 10);
//        hexStr = ch + hexStr;
        dec /= 16;
    }
    return hexStr;
}

