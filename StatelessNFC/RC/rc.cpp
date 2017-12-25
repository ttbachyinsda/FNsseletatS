#include "rc.h"

RC::RC()
{
    this->cluster = new RamCloud("tcp:host=127.0.0.1,port=12245");
    table = cluster->createTable("test");
}

void RC::readRC(char *key, uint16_t lkey, char *dest, uint16_t &ldest)
{
    cluster->read(table,key,lkey,&buffer);
    ldest = buffer.size();
    buffer.copy(0,ldest,dest);
    //Is buffer thread-safe?
}

void RC::writeRC(char *key, uint16_t lkey, char *value, uint16_t lvalue)
{
    cluster->write(table,key,lkey,value,lvalue);
}

void RC::deleteRC(char *key, uint16_t lkey)
{
    cluster->remove(table,key,lkey);
}

RC::~RC()
{
    cluster->dropTable("test");
}
