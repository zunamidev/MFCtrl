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
 *  2. Reading Measure
 *  3. Arduino Compatibility
 *
 */

// Custom Library
#include "MFCtrl.h"

// Setting up the connection with the RX and TX pins and define the Node
MFCtrl::MFCtrl(int rx, int tx, int node) {
    _tx = tx;
    _rx = rx;
    _node = node;
}

// Setting the data into the call
std::string MFCtrl::sendData(long sollValue) {
    std::string call;
    // Preparing the call
    call = ":060" + std::to_string(_node) + "010121" + toHex(sollValue) + "\r\n";

    // 06803401210120


    if (sollValue >= 32000 || sollValue <= 0) {
        std::cout << "[Error] Soll Wert muss zwischen 0 und 32.000 sein.";
        exit(1);
    }

    if (_node >= 9) {
        std::cout << "[Error] Node Wert darf nicht größer als 9 sein.";
        exit(2);
    }

    if (response(call) == 1) {
        std::cout << "Keine Fehler!" << std::endl;
    } else {
        std::cout << "Error!" << std::endl;
    }

    return call;

}


std::string MFCtrl::readData(long process) {
    return std::string();
}


// Debugging
void MFCtrl::getInfo() {
    std::cout << _tx << " " << _rx << " " << _node << " " << _call << std::endl;
    char test[] = "459CFFAE";
    std::cout << toFloat(test) << std::endl;
    std::string test1 = ":0403000005\r\n";
    std::cout << response(test1);
}

// Helper functions
std::string MFCtrl::toHex(long x) {
    std::stringstream stream;
    stream << std::hex << x;
    return stream.str();
}

int MFCtrl::toDec(char *hexVal) {
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

float MFCtrl::toFloat(char *x) {
    uint32_t num;
    float f;
    sscanf(x, "%x", &num);
    f = *((float *) &num);
    return f;
}

// Error Handling
bool MFCtrl::response(std::string resp) {
    std::string response = resp.substr(5, 2);
    switch (stoi(response)) {
        case 00:
            return true;
        case 01:
            return false;
        case 02:
            return false;
        case 03:
            return false;
        case 04:
            return false;
        default:
            return false;
    }
}

