#ifndef _VM_INSTANCE_HPP_
#define _VM_INSTANCE_HPP_

#include "VM_Memory.hpp"
#include "VM_Register.hpp"

#include <memory>
#include <array>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include "VM_Instruction.hpp"
#include "Bytepack/Bytepack.hpp"

namespace VM
{
  class Instance;

  using Flag_register = int;

  using Is_terminated = bool;

  using byte = unsigned char;

  class op
  {
    public:
      int (*call)(Instance &, std::vector<byte>);
      int number_of_byte;
      op(int (*a)(Instance &, std::vector<byte>), int b) : call(a), number_of_byte(b) { }
  };

  class Instance
  {
    public: 
      static const size_t MEMORY_SIZIE = 64 * 1024;

    public: 
      enum class INSERT
    {
      INSTR_HANDLER = 0,
      INSTR_LENGTH = 1
    };

    public: 
      enum class INTERPUR
    {
      MEMORY_ERROR = 0,
      DIVISION_ERROR = 1,
      GENERAL_ERROR = 2,
      PIT = 8,
      CONSOLE = 9
    };

    public: 
      enum class FLAG
    {
      ZERO_FLAG = (1 << 0),
      CARRY_FLAG = (1 << 1)
    };

    public: 
      enum class CONTROL_REGISTER
    {
      INT_FIRST = 0x100,
      INT_LAST = 0x10f, 
      INT_CONTROL = 0x110
    };

    public: 
      std::array<int, 2> maskable_ints = {8, 9};

    public: 
      std::vector<Register> r;

    public: 
      Flag_register fr;

    public: 
      std::unique_ptr<Register> sp;

    public: 
      std::unique_ptr<Register> pc;

    public: 
      Is_terminated terminated;
    
    public:
      std::map<int, int> cr;

    public:
      std::list<int> interrupt_queue;
    
    public:
      std::deque<int> deferend_queue;

    public:
      std::map<int, op> opcode;

    public: 
      Memory memory;    

    // Constructor
    public: 
      Instance();
    
    // Method
    
    public: 
      Register & reg(size_t r);
    
    public:
      void interupt(int interupt);

    public: 
      void load_to_memory(); 

    public: 
      void single_step();
    
  };
  
  // Declaration CPU instruction
  int rangeFromVector(std::vector<byte> args, int begin, int end);

  int mmov(Instance & vm, std::vector<byte> args);

  int mset(Instance & vm, std::vector<byte> args);

  int mld(Instance & vm, std::vector<byte> args);

  int mst(Instance & vm, std::vector<byte> args);

  int mldb(Instance & vm, std::vector<byte> args);

  int mstb(Instance & vm, std::vector<byte> args);

  int madd(Instance & vm, std::vector<byte> args);

  int msub(Instance & vm, std::vector<byte> args);
  
  int mmul(Instance & vm, std::vector<byte> args);
  
  int mdiv(Instance & vm, std::vector<byte> args);
  
  int mmod(Instance & vm, std::vector<byte> args);
  
  int mor(Instance & vm, std::vector<byte> args);
  
  int mand(Instance & vm, std::vector<byte> args);
  
  int mxor(Instance & vm, std::vector<byte> args);
  
  int mnot(Instance & vm, std::vector<byte> args);
  
  int mshl(Instance & vm, std::vector<byte> args);
  
  int mshr(Instance & vm, std::vector<byte> args);
  
  int mcmp(Instance & vm, std::vector<byte> args);
  
  int mjz(Instance & vm, std::vector<byte> args);
  
  int mjnz(Instance & vm, std::vector<byte> args);
  
  int mjc(Instance & vm, std::vector<byte> args);
  
  int mjnc(Instance & vm, std::vector<byte> args);
  
  int mjbe(Instance & vm, std::vector<byte> args);
  
  int msrb(Instance & vm, std::vector<byte> args);
  
  int mja(Instance & vm, std::vector<byte> args);
  
  int mpush(Instance & vm, std::vector<byte> args);
  
  int mpop(Instance & vm, std::vector<byte> args);
  
  int mjmp(Instance & vm, std::vector<byte> args);
  
  int mjmpr(Instance & vm, std::vector<byte> args);
  
  int mcall(Instance & vm, std::vector<byte> args);
  
  int mcallr(Instance & vm, std::vector<byte> args);
  
  int mret(Instance & vm, std::vector<byte> args);
  
  int mcrl(Instance & vm, std::vector<byte> args);
  
  int mcrs(Instance & vm, std::vector<byte> args);
  
  int moutb(Instance & vm, std::vector<byte> args);
  
  int minb(Instance & vm, std::vector<byte> args);

  int miret(Instance & vm, std::vector<byte> args);
  
  int mcrsh(Instance & vm, std::vector<byte> args);
  
  int moff(Instance & vm, std::vector<byte> args);
  
}

#endif