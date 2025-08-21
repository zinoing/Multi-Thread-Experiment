#include "LiveLock.h"
#include "Lab.h"

void Livelock_Run() { /*Livelock_Bug();*/ Livelock_Fix_Backoff(); Livelock_Fix_ScopedLock(); }
REGISTER_LAB("Livelock:RunAll", Livelock_Run);
