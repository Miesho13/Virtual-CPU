#ifndef _VM_MEMORY_HPP_
#define _VM_MEMORY_HPP_

#include <array>
#include <vector>

namespace VM
{
  using byte = unsigned char;

  using dword = unsigned int;

  using index = unsigned int;

  using memory_array = std::vector<unsigned char>;

  class Memory
  {
    private:
      std::vector<byte> memory;
    
    public:
      Memory();

      ~Memory();

      byte fetch_byte(index addr) const;

      bool store_byte(index addr, byte value);

      dword fetch_dword(index addr) const;

      bool store_dword(index addr, dword value);

      memory_array fetch_many(index addr, size_t size) const; 

      bool store_many(index addr, std::vector<unsigned char> & array);
  };
}

#endif