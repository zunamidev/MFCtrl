//
//  asd.h
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
#include <iostream>
#include <cmath>
using namespace std;

class MFCtrl {
private:
    // Variabels
    unsigned int _tx, _rx, _node;
    unsigned long int sollValue;

public:
    // Setingup the connection with the RX and TX pins
    void setup(int rx, int tx, int node, long soll);

    // Setting Data
    void setData(int data);

    // Reading the informations from the asd
    // TODO: Reading the MAX232
    void read();

    // Helper functions
    // TODO: Converting the messages
    void convert(string message, bool to);

    // Debugging
    void getInfo();

    int DecToHex(int p_intValue);

};

#endif /* MFCtrl_h */
