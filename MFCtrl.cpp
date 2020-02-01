//
//  MFCtrl.cpp
//  Fraunhofer ICT
//
//  Created by Hamza Huber on 24.01.20.
//  Copyright © 2020 Hamza Huber. All rights reserved.
//
//  Basic Call
//  :06 03 02 01 21 3E 80 \r\n
//


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

