#ifndef NAT_H
#define NAT_H

#include <./RC/rc.h>
#include <./NFS/nf.h>
#include <./NFS/define.h>

class NAT : public NF
{
public:
    NAT(RC* rc, char* ClusterID, uint16_t lClusterID);
    void ProcessPacket(char* P, uint16_t Packetlen);
private:
    RC* rc;
    char* ClusterID;
    uint16_t lClusterID;
    void select_IP_Port(char* ipportlist, uint16_t l1, char* tupleof5, uint16_t l2, char* dest, uint16_t& ldest);
    void update(char* ipportlist, uint16_t l1, char* ipport, uint16_t l2, char* dest, uint16_t& ldest);
    void updatePacketHeader(char* P, uint16_t lP, char* ipport, uint16_t l1, char* dest, uint16_t &ldest);

};

#endif // NAT_H
