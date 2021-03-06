# Virtual CPU
[![Compilator version](https://img.shields.io/badge/C%2B%2B-(GCC)%209.2.0-blue)](https://gcc.gnu.org/gcc-9/)
[![NASM version](https://img.shields.io/badge/NASM-%092.15.05-blue)](https://www.nasm.us/)

## About project

It is a 32-bit virtual processor. Carries out commands given by the programmer. All instances are defined in the `opcode file`. The processor communicates with the two preferential devices.

## CPU Specification

**Processor:**
  - 32 bit
  - 32 bit address bus
  - 16 registers
  - a simple set of instructions for operating on natural numbers

**64 kB RAM:**
  - A cell of RAM is one byte

**Input / output device:**
  - Simple text console

**Other devices:** 
  - Programmable timer

**Disclamer: _Not all feature are implementing yet_**

## Project Specification

This project uses pure c ++ and Netwide Assembler (NASM) for opcode generation.