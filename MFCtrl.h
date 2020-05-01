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
 *
 */


#ifndef MFCtrl_h
#define MFCtrl_h

// Needed Libarys
#include <cstdio>
#include <cmath>
#include <cstdint>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class MFCtrl {
private:
    // Variabels
    unsigned int _tx, _rx, _node;
    unsigned int _sollValue;

    string _call;

public:
    // Setting the connection with the RX and TX pins
    void setup(int rx, int tx, int node);

    // Setting Data
    string sendData(long sollValue);

    // Reading the informations from the MAX232
    // TODO: Reading the Data
    string readData(long process);

    // Helper functions
    static string to_hex(long x);

    int to_dec(char *x);

    float to_float(char *x);

    // Error Handling
    bool response(string resp);

    // Debugging
    void getInfo();

};

#endif /* MFCtrl_h */
