#ifndef _BYTEPACK_H_
#define _BYTEPACK_H_

#include <string>
#include <vector>
#include <windows.h> // for htonl function

class Bytepack
{
  public:
    static int unpack_int32(int myValueToPack);

    static unsigned short unpack_short(short myValueToPack);

};

#endif