#include "../include/VM_Instance.hpp"



int VM::rangeFromVector(std::vector<byte> args, int begin, int end)
{
  int retval = 0;
  int magnitude = 0x1;
  for (int i = end; i >= begin; i--)
  {
    retval += args[i] * magnitude;
    magnitude *= 0x100;
  }
  return retval;
}

int VM::mmov(Instance & vm, std::vector<byte> args)
{
  vm.reg(args[0]).v = vm.reg(args[1]).v;
  return 0;
}

int VM::mset(Instance & vm, std::vector<byte> args)
{
  vm.reg(args[0]).v = Bytepack::unpack_int32(rangeFromVector(args, 1, 4));
  return 0;
}

int VM::mld(Instance & vm, std::vector<byte> args)
{
  int dd;
  try
  {
    dd = vm.memory.fetch_dword(vm.reg(args[1]).v);
  }
  catch (const char * s)
  {
    
  }
}

int VM::mst(Instance & vm, std::vector<byte> args);

int VM::mldb(Instance & vm, std::vector<byte> args);

int VM::mstb(Instance & vm, std::vector<byte> args);

int VM::madd(Instance & vm, std::vector<byte> args);

int VM::msub(Instance & vm, std::vector<byte> args);
  
int VM::mmul(Instance & vm, std::vector<byte> args);
  
int VM::mdiv(Instance & vm, std::vector<byte> args);
  
int VM::mmod(Instance & vm, std::vector<byte> args);
  
int VM::mor(Instance & vm, std::vector<byte> args);
  
int VM::mand(Instance & vm, std::vector<byte> args);
  
int VM::mxor(Instance & vm, std::vector<byte> args);
  
int VM::mnot(Instance & vm, std::vector<byte> args);
  
int VM::mshl(Instance & vm, std::vector<byte> args);
  
int VM::mshr(Instance & vm, std::vector<byte> args);
  
int VM::mcmp(Instance & vm, std::vector<byte> args);
  
int VM::mjz(Instance & vm, std::vector<byte> args);
  
int VM::mjnz(Instance & vm, std::vector<byte> args);
  
int VM::mjc(Instance & vm, std::vector<byte> args);
  
int VM::mjnc(Instance & vm, std::vector<byte> args);
  
int VM::mjbe(Instance & vm, std::vector<byte> args);
  
int VM::msrb(Instance & vm, std::vector<byte> args);
  
int VM::mja(Instance & vm, std::vector<byte> args);
  
int VM::mpush(Instance & vm, std::vector<byte> args);
  
int VM::mpop(Instance & vm, std::vector<byte> args);
  
int VM::mjmp(Instance & vm, std::vector<byte> args);
  
int VM::mjmpr(Instance & vm, std::vector<byte> args);
  
int VM::mcall(Instance & vm, std::vector<byte> args);
  
int VM::mcallr(Instance & vm, std::vector<byte> args);
  
int VM::mret(Instance & vm, std::vector<byte> args);
  
int VM::mcrl(Instance & vm, std::vector<byte> args);
  
int VM::mcrs(Instance & vm, std::vector<byte> args);
  
int VM::moutb(Instance & vm, std::vector<byte> args);
  
int VM::minb(Instance & vm, std::vector<byte> args);

int VM::miret(Instance & vm, std::vector<byte> args);
 
int VM::mcrsh(Instance & vm, std::vector<byte> args);
  
int VM::moff(Instance & vm, std::vector<byte> args);