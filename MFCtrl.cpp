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


// Custom Libary
#include "MFCtrl.h"

// Setingup the connection with the RX and TX pins
void MFCtrl::setup(int rx, int tx, int node, long soll) {
    _tx = tx;
    _rx = rx;
    _node = node;
    sollValue = soll;
}


// Debugging
void MFCtrl::getInfo() {

    cout << _tx << " " << _rx << " " << _node << " " << sollValue << endl;
    DecToHex(sollValue);

}

void MFCtrl::setData(int data) {

}

int MFCtrl::DecToHex(int inputValue) {
    char *l_pCharRes = new (char);
    sprintf(l_pCharRes, "%X", inputValue);
    int l_intResult = stoi(l_pCharRes);
    cout << l_intResult<< "\n";
    return l_intResult;
}