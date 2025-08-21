#pragma once

static constexpr int T = 8, N = 1'000'000;

void DataRace_Bug();
void DataRace_Fix_Mutex();
void DataRace_Fix_Atomic();
void DataRace_Run();