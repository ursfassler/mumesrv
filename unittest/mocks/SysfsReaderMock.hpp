#ifndef SYSFSREADERMOCK
#define SYSFSREADERMOCK

#include <ISysfs.hpp>

#include <gmock/gmock.h>

class SysfsReaderMock :
    public ISysfsReader
{
  public:
    MOCK_CONST_METHOD0(read, QString());
};

#endif // SYSFSREADERMOCK

