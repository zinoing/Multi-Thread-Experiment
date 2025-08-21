#include "Lab.h"

std::vector<LabCase>& labRegistry() { static std::vector<LabCase> v; return v; }
void registerLab(const LabCase& c) { labRegistry().push_back(c); }