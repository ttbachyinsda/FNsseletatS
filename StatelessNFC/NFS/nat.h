#ifndef NAT_H
#define NAT_H


class NAT : public NF
{
public:
    NAT();
    void ProcessPacket(char* P);
};

#endif // NAT_H
