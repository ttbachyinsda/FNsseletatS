#include "nat.h"

NAT::NAT(RC* rc, char* ClusterID, uint16_t lClusterID)
{
    this->rc = rc;
    this->ClusterID = (char*)malloc(lClusterID);
    memcpy(this->ClusterID, ClusterID, lClusterID);
    this->lClusterID = lClusterID;
}
void NAT::ProcessPacket(char *P, uint16_t Packetlen)
{
    char tupleof5[20]; uint16_t ltupleof5;
    char pipport[8]; uint16_t lpipport;
    char ipport[8]; uint16_t lipport;
    rc->readRC(tupleof5,ltupleof5,ipport,lipport);
    if (lipport == 0)
    {
        char ipportlist[100]; uint16_t lipportlist;
        char newipportlist[100]; uint16_t lnewipportlist;
        rc->readRC(tupleof5,ltupleof5,ipportlist,lipportlist);
        select_IP_Port(ipportlist,lipportlist,tupleof5,ltupleof5,ipport,lipport);
        update(ipportlist,lipportlist,ipport,lipport,newipportlist,lnewipportlist);
        rc->writeRC(ClusterID,lClusterID,ipportlist,lipportlist);
        rc->writeRC(tupleof5,ltupleof5,ipport,lipport);
        char* reversetupleof5 = tupleof5; int lreversetupleof5 = ltupleof5;
        rc->writeRC(reversetupleof5,lreversetupleof5,pipport,lpipport);
    }
    char* p1 = (char*)malloc(MAX_PACKET_LEN); uint16_t lp1;
    updatePacketHeader(P,Packetlen,ipport,lipport,p1,lp1);
    //sendPacket(p1,lp1);
}
void NAT::select_IP_Port(char *ipportlist, uint16_t l1, char *tupleof5, uint16_t l2, char *dest, uint16_t &ldest)
{
    ldest=8;
}
void NAT::update(char *ipportlist, uint16_t l1, char *ipport, uint16_t l2, char *dest, uint16_t &ldest)
{
    ldest=l1;
}
void NAT::updatePacketHeader(char *P, uint16_t lP, char *ipport, uint16_t l1, char *dest, uint16_t &ldest)
{
    ldest=lP;
}
