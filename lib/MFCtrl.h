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

class MFCtrl {
private:
    // Variabels
    unsigned int _tx, _rx, _node;
    unsigned int _sollValue{};

    std::string_view _call;

public:
    // Setting the connection with the RX and TX pins
    MFCtrl(int rx, int tx, int node);

    // Setting Data
    std::string sendData(long sollValue);

    // Reading the informations from the MAX232
    // TODO: Reading the Data
    std::string readData(long process);

    // Helper functions
    static std::string toHex(long x);

    int toDec(char *x);

    float toFloat(char *x);

    // Error Handling
    bool response(std::string resp);

    // Debugging
    void getInfo();

};

#endif /* MFCtrl_h */
