#include "DataRace.h"
#include "Lab.h"

void DataRace_Run() { DataRace_Bug(); DataRace_Fix_Atomic(); DataRace_Fix_Mutex(); }
REGISTER_LAB("DataRace:RunAll", DataRace_Run);
