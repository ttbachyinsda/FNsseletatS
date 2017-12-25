#ifndef RC_H
#define RC_H

#include <ClientException.h>
#include <ramcloud/RamCloud.h>
using namespace RAMCloud;

class RC
{
public:
    RC();
    void readRC(char* key, uint16_t lkey, char* dest, uint16_t& ldest);
    void writeRC(char* key, uint16_t lkey, char* value, uint16_t lvalue);
    void deleteRC(char* key, uint16_t lkey);
    ~RC();
private:
    RamCloud *cluster;
    uint64_t table;
    Buffer buffer;
};

#endif // RC_H
