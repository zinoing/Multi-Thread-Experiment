#pragma once

#include <functional>
#include <string>
#include <vector>

struct LabCase {
    std::string name;
    std::function<void()> run;
};

std::vector<LabCase>& labRegistry();
void registerLab(const LabCase& c);

#define REGISTER_LAB(name, fn) \
    namespace { struct _Reg_##fn{ _Reg_##fn(){ registerLab({name, fn}); }} _reg_##fn; }
