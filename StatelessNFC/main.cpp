#include <iostream>
#include <ClientException.h>
#include <ramcloud/RamCloud.h>
using namespace RAMCloud;
using namespace std;

int main()
{
    RamCloud cluster("tcp:host=127.0.0.1,port=12245");
    uint64_t table = cluster.createTable("test");
    cluster.write(table, "42", 2, "Hello, World!", 14);
    const char *value = "0123456789012345678901234567890"
            "123456789012345678901234567890123456789";
    cluster.write(table, "43", 2, value, downCast<uint32_t>(strlen(value) + 1));
    Buffer buffer;
    cluster.read(table, "43", 2, &buffer);
    cout<< buffer.size() <<endl;
    cluster.read(table, "42", 2, &buffer);
    cluster.dropTable("test");
    return 0;
}
