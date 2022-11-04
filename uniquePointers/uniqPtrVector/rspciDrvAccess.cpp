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
   printf("In Default Constructor: %s\n",m_text.c_str());
}

CRsPciDriverAccess::~CRsPciDriverAccess()
{
   printf("In Destructor: %s\n",m_text.c_str());
}

CRsPciDriverAccess::CRsPciDriverAccess(CRsPciDriverAccess&& other)
{
   printf("In Move Constructor:\n");
   printf("Moving %s To %s\n",other.m_text.c_str(),this->m_text.c_str());
   
   this->m_text = other.m_text + " moved";
}
