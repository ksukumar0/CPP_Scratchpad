// Local Headers
#include "rspciDrvAccess.h"

// Linux Related Headers
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/mman.h>

// CPP Headers
#include <iomanip>
#include <fstream>
#include <cstring>

// C Headers
#include <unistd.h>

CRsPciDriverAccess::CRsPciDriverAccess(std::string &name): m_text(name)
{
   srand((unsigned)time(0));
   m_random = (rand()%253) + 1;
   printf("In Default Constructor: %s %d\n",m_text.c_str(),m_random);
}

CRsPciDriverAccess::~CRsPciDriverAccess()
{
   printf("In Destructor: %s %d\n",m_text.c_str(), m_random);
}

CRsPciDriverAccess::CRsPciDriverAccess(CRsPciDriverAccess&& other)
{
   printf("In Move Constructor:\n");
   printf("Moving %s %d To %s %d\n",other.m_text.c_str(),other.m_random,this->m_text.c_str(),this->m_random);
   this->m_text = other.m_text + " moved";
   this->m_random = (rand()%253) + 1;
}
