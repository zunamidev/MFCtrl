//
//  main.cpp
//  Fraun
//
//  Created by Hamza Huber on 24.01.20.
//  Copyright © 2020 Hamza Huber. All rights

#include <iostream>
#include "MFCtrl.h"

int main(int argc, const char * argv[]) {
    MFCtrl MF;
    MF.setup(12, 23, 15, 16000);
    MF.getInfo();
    std::cout << "Hello, World!\n";
    return 0;
}
