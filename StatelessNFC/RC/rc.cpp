#include "rc.h"

RC::RC()
{
    this->cluster = new RamCloud("tcp:host=127.0.0.1,port=12245");
    table = cluster.createTable("test");
}

void RC::readRC(char *key, int lkey, char *dest, int &ldest)
{
    cluster->read(table,key,lkey,buffer);
    ldest = buffer.size();
    buffer.copy(0,ldest,dest);
}

void RC::writeRC(char *key, int lkey, char *value, int lvalue)
{
    cluster->write(table,key,lkey,value,lvalue);
}

void RC::deleteRC(char *key, int lkey)
{
    cluster->remove(table,key,lkey);
}

RC::~RC()
{
    cluster->dropTable("test");
}
