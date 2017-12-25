#ifndef RC_H
#define RC_H

#include <ClientException.h>
#include <ramcloud/RamCloud.h>
using namespace RAMCloud;

class RC
{
public:
    RC();
    void readRC(char* key, int lkey, char* dest, int& ldest);
    void writeRC(char* key, int lkey, char* value, int lvalue);
    void deleteRC(char* key, int lkey);
    ~RC();
private:
    RamCloud *cluster;
    uint64_t table;
    Buffer buffer;
};

#endif // RC_H
