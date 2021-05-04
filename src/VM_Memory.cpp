#include "../include/VM_Memory.hpp"

VM::Memory::Memory()
{
  this->memory.resize(64 * 1024);
}

VM::Memory::~Memory()
{
  memory.clear();
}

VM::byte VM::Memory::fetch_byte(index addr) const
{
  if (addr < 0 || addr >= this->memory.size())
  {
    throw "Memory Error";
    return 0;
  }
  else
  {
    return memory.at(addr);
  }
}

bool VM::Memory::store_byte(index addr, byte value)
{
  if (addr < 0 || addr >= this->memory.size())
  {
    return false;
  }
  else
  {
    memory.at(addr) = value;
    return true;
  }
}

VM::dword VM::Memory::fetch_dword(index addr) const
{
  if (addr < 0 || addr + 3 >= this->memory.size())
  {
    throw "Memory Error";
    return 0;
  }
  else 
  {
    return (
      memory.at(addr) |
      (memory.at(addr + 1) << 8) |
      (memory.at(addr + 2) << 16) |
      (memory.at(addr + 3) << 24) 
    ); 
  }
}

bool VM::Memory::store_dword(index addr, dword value)
{
  if (addr < 0 || addr + 3 >= this->memory.size())
  {
    return false;
  }
  else
  {
    memory.at(addr) = value & 0xff;
    memory.at(addr + 1) = (value >> 8) & 0xff;
    memory.at(addr + 2) = (value >> 16) & 0xff;
    memory.at(addr + 3) = (value >> 24) & 0xff;
    return true;
  }
}

VM::memory_array VM::Memory::fetch_many(index addr, size_t size) const
{

  if ((addr + size - 1) >= this->memory.size())
  {
    throw "Memory Error";
    return memory_array {};
  }
  else
  {
    memory_array ret_vec;
    std::copy
    (
      memory.begin() + addr, 
      memory.begin() + addr + size,
      std::back_inserter(ret_vec)
    );
    return ret_vec;
  }
}

bool VM::Memory::store_many(index addr, std::vector<unsigned char> & array)
{
  if ((addr + array.size() - 1) >= this->memory.size())
  {
    return false;
  }
  else
  {
    std::copy
    (
      array.begin(), 
      array.end(), 
      std::inserter(this->memory, this->memory.begin() + addr)
    );
    return true;
  }
}




