#include "DeadLock.h"
#include "Lab.h"

void Deadlock_Run() { /*Deadlock_Bug();*/ Deadlock_Fix_ScopedLock(); Deadlock_Fix_Order(); }
REGISTER_LAB("Deadlock:RunAll", Deadlock_Run);
