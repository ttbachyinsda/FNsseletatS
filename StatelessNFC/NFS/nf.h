#ifndef NF_H
#define NF_H

#include <RamCloud.h>
class NF
{
public:
    virtual void ProcessPacket(char* P, uint16_t Packetlen)=0;
};

#endif // NF_H
