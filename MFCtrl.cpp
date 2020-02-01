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
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */


// Custom Library
#include "MFCtrl.h"

// Setting up the connection with the RX and TX pins
void MFCtrl::setup(int rx, int tx, int node) {
    _tx = tx;
    _rx = rx;
    _node = node;
}


void MFCtrl::setData(long sollValue) {
    string call;
    // Preparing the call
    call = ":060" + to_string(_node) + "010121" + to_hex(sollValue) + "\r\n";


    if (sollValue >= 32000 || sollValue <= 0) {
        cout << "[Error] Soll Wert muss zwischen 0 und 32.000 sein.";
        exit(1);
    }

    if (_node >= 9) {
        cout << "[Error] Node Wert darf nicht größer als 9 sein.";
        exit(2);
    }

    _call = call;


}


// Debugging
void MFCtrl::getInfo() {
    cout << _tx << " " << _rx << " " << _node << " " << _call << endl;
}

// Helper functions
string MFCtrl::to_hex(long x) {
    stringstream stream;
    stringstream stream1;
    stream << hex << x;
    return stream.str();

}

