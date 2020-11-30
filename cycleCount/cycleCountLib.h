#include <stdint.h>

//  Windows
#ifdef _WIN32

#include <intrin.h>
uint64_t rdtsc(void);

//  Linux/GCC
#else

uint64_t rdtsc(void);
#endif
