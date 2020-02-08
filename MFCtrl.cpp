/*
 *   Copyright 2020 Hamza Huber
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

/*
 * TODO:
 *  1. Error Handling
 *  2. Reading Measure
 *  3. Arduino Compatibility
 *
 */

/* *
    00 kein Fehler
    01 Prozess angefordert
    02 Befehlsfehler
    03 Prozessfehler
    04 Parameterfehler
 * */

// Custom Library
#include <cmath>
#include "MFCtrl.h"

// Setting up the connection with the RX and TX pins and define the Node
void MFCtrl::setup(int rx, int tx, int node) {
    _tx = tx;
    _rx = rx;
    _node = node;
}

// Setting the data into the call
string MFCtrl::sendData(long sollValue) {
    string call;
    // Preparing the call
    call = ":060" + to_string(_node) + "010121" + to_hex(sollValue) + "\r\n";

    // 06803401210120


    if (sollValue >= 32000 || sollValue <= 0) {
        cout << "[Error] Soll Wert muss zwischen 0 und 32.000 sein.";
        exit(1);
    }

    if (_node >= 9) {
        cout << "[Error] Node Wert darf nicht größer als 9 sein.";
        exit(2);
    }

    if (response(call) == 0) {
        cout << "Keine Fehler!" << endl;
    } else {
        cout << "Error!" << endl;
    }

    return call;

}


string MFCtrl::readData(long process) {
    return std::string();
}


// Debugging
void MFCtrl::getInfo() {
    cout << _tx << " " << _rx << " " << _node << " " << _call << endl;
    cout << response("123") << endl;
    char test[] = "459CFFAE";
    cout << to_dec(test) << endl;

    cout << HexStringToFloat(test) << endl;
}

// Helper functions
string MFCtrl::to_hex(long x) {
    stringstream stream;
    stream << hex << x;
    return stream.str();
}

float MFCtrl::to_dec(char *hexVal) {
    int len = strlen(hexVal);

    int base = 1;

    int dec_val = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            dec_val += (hexVal[i] - 48) * base;

            base = base * 16;
        } else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            dec_val += (hexVal[i] - 55) * base;

            base = base * 16;
        }
    }

    return dec_val;
}

float MFCtrl::HexStringToFloat(char *s) {
    if ((*s != '0') || ((*s != 'X') && (*s != 'x'))) {
        return NAN;  // Not-a-number macro from math.h
    }
    float x = 0;
    int ch;
    while ((ch = *s++) != '\0') {
        static const char HexDigit[] = "0123456789ABCDEFabcdef";
        int i = 0;
        while (1) {
            if (HexDigit[i] == '\0') return NAN;
            if (HexDigit[i] == ch) break;
            i++;
        }
        if (i >= 16) i -= 6;
        x *= 16;
        x += i;
    }
    return x;
}

// TODO:
bool MFCtrl::response(string resp) {
    return false;
}



