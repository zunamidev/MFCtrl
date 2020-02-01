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


void MFCtrl::setData(int data, long sollValue) {
    _sollValue = sollValue;

    if (sollValue >= 32000 || sollValue <= 0) {
        cout << "[Error] Soll Wert muss zwischen 0 und 32.000 sein.";
        exit(1);
    }

    to_hex(_sollValue);

}


// Debugging
void MFCtrl::getInfo() {
    cout << _tx << " " << _rx << " " << _node << " " << _sollValue << endl;
    cout << hex << _sollValue << endl;
}

// Helper functions
string MFCtrl::to_hex(long x) {
    std::stringstream s;
    s << std::hex << x;
    return s.str();

}

