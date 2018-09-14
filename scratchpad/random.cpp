#include "random.h"
namespace randar1
{
    unsigned short hash(void *p)
    {
        unsigned long val = reinterpret_cast<unsigned long>(p);
        val = val + 1;
        return ( unsigned short )(val^(val >> 16));
    }
}
