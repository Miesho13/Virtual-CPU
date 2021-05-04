
#include "Bytepack.hpp"


int Bytepack::unpack_int32(int bigEndianValue)
{
  int32_t unpack_value = htonl(bigEndianValue);
  return unpack_value;
}

unsigned short Bytepack::unpack_short(short myValueToPack)
{
  // to define
  return 0;
}
