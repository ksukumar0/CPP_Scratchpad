#include "MdBgaIoIsr.h"
#include <iostream>
using namespace std;

static MdBgaIoIsr* myStaticthis = nullptr;

MdBgaIoIsr::MdBgaIoIsr()
{
    myStaticthis = this;
}

MdBgaIoIsr::~MdBgaIoIsr(){

}

void MdBgaIoIsr::IsrThread(void)
{
    cout<<"In MdBgaIoIsr"<<endl;
}
