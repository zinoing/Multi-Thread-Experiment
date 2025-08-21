// Multi-Thread-Experiment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Common/Lab.h"

int main(int argc, char** argv) {
    auto& labs = labRegistry();

    std::cout << "== Multi-Thread Labs ==\n";
    for (size_t i = 0; i < labs.size(); ++i) std::cout << i << ") " << labs[i].name << "\n";

    std::cout << "Select index: ";
    size_t k{}; std::cin >> k;
    if (k >= labs.size()) { std::cout << "invalid\n"; return 0; }

    std::cout << "\n[RUN] " << labs[k].name << "\n";
    labs[k].run();
    std::cout << "\nDone.\n";
}
