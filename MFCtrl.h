//
//  MFCtrl.h
//  Fraunhofer ICT
//
//  Created by Hamza Huber on 24.01.20.
//  Copyright © 2020 Hamza Huber. All rights reserved.
//
//  Basic Call
//  :06030201213E80\r\n
//


#ifndef MFCtrl_h
#define MFCtrl_h

// Needed Libarys
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class MFCtrl {
private:
    // Variabels
    unsigned int _tx, _rx, _node;
    unsigned int _sollValue;

public:
    // Setingup the connection with the RX and TX pins
    void setup(int rx, int tx, int node);

    // Setting Data
    void setData(int data, long sollValue);

    // Reading the informations from the asd
    // TODO: Reading the MAX232
    void read();

    // Helper functions
    static string to_hex(long x);

    // Debugging
    void getInfo();

};

#endif /* MFCtrl_h */
