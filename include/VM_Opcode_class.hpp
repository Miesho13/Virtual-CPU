#ifndef __OPCODE_H_
#define __OPCODE_H_

namespace VM
{
  class opcode
  {
    public:
      int (*call)(int, int);
      int number_of_byte;
      opcode(int (*a)(int, int), int b) : call(a), number_of_byte(b) { }
  };
}

#endif