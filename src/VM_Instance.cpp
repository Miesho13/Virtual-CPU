#include "../include/VM_Instance.hpp"


VM::Instance::Instance()
{
  this->r.resize(16);

  this->fr = 0;

  this->sp = std::make_unique<Register>(r.at(14));
  this->sp->v = 0x10000;

  this->pc = std::make_unique<Register>(r.at(15));

  this->terminated = false;

  for (int i = (int)CONTROL_REGISTER::INT_FIRST; i < (int)CONTROL_REGISTER::INT_LAST; i++)
  {
    this->cr[i] = 0xffffffff;
  }
  this->cr[(int)CONTROL_REGISTER::INT_CONTROL] = 0;
  
  this->opcode =
  {
    {0x00, {mmov, 1+1}},  {0x01, {mset, 1+4}},
    {0x02, {mld, 1+1}},   {0x03, {mst, 1+1}},
    {0x04, {mldb, 1+1}},  {0x05, {mstb, 1+1}},

    {0x10, {madd, 1+1}},  {0x11, {msub, 1 + 1}},
    {0x12, {mmul, 1+1}},  {0x13, {mdiv, 1 + 1}},
    {0x14, {mmod, 1+1}},  {0x15, {mor, 1 + 1}},
    {0x16, {mand, 1+1}},  {0x17, {mxor, 1 + 1}},
    {0x18, {mnot, 1}},    {0x19, {mshl, 1 + 1}},
    {0x1A, {mshr, 1+1}},
    
    {0x20, {mcmp, 1+1}},  {0x21, {mjz, 2}},
    {0x22, {mjnz, 2}},    {0x23, {mjc, 2}},
    {0x24, {mjnc, 2}},    {0x25, {mjbe, 2}},
    {0x26, {mja, 2}},

    {0x30, {mpush, 1}},   {0x31, {mpop, 1}},

    {0x40, {mjmp, 2}},    {0x41, {mjmpr, 1}},
    {0x42, {mcall, 2}},   {0x43, {mcallr, 1}},
    {0x44, {mret, 0}}, 

    {0xF0, {mcrl, 1+1}},  {0xF1, {mcrs, 1 + 1}},
    {0xF2, {moutb, 1+1}},  {0xF3, {minb, 1 + 1}},
    {0xF4, {miret, 1+1}},  {0xFE, {mcrsh, 1 + 1}},
    {0xFF, {moff, 1+1}},  
  };
  
}

VM::Register & VM::Instance::reg(size_t r)
{
  return this->r.at(r & 0xf);
} 

void VM::Instance::interupt(int interupt)
{
  interrupt_queue.push_back(interupt);
}


