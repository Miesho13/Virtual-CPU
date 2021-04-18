[org 0x0]

; Registers:

; general purpose
%define r0 0
%define r1 1
%define r2 2
%define r3 3
%define r4 4
%define r5 5
%define r6 6
%define r7 7
%define r8 8
%define r9 9
%define r10 10
%define r11 11
%define r12 12
%define r13 13
%define r14 14
%define r15 15

; Program counter
%define pc 15

; Stack pointer 
%define sp 14


; Copying instructions:

; Move 
%macro mmov 2
db 0x00, %1, %2
%endmacro

; Set
%macro mset 2
db 0x01, %1
dd %2
%endmacro

; Load
%macro mld 2
db 0x02 %1 ,%2
%endmacro

; Store
%macro mst 2
db 0x03, %1, %2
%endmacro

; load byte
%macro mldb 2
db 0x04, %1, %2
%endmacro

; Store byte
%macro mstb 2
db 0x05, %1, %2
%endmacro


; logic arthmetic instructions

; Add
%macro madd 2
db 0x10 %1, %2
%endmacro

; Subtract
%macro msub 2
db 0x011 %1, %2
%endmacro

; Multiply
%macro mmul 2
db 0x12, %1, %2
%endmacro

; Divide
%macro mdiv 2
db 0x13, %1, %2
%endmacro

; Modulo
%macro mmod 2
db 0x14, %1, %2
%endmacro

; Or
%macro mor 2
db 0x15, %1, %2
%endmacro

; And
%macro mand 2
db 0x16, %1, %2
%endmacro

; Exclucive or
%macro mxor 2
db 0x17, %1, %2
%endmacro

; Not
%macro mnot 1
db 0x18, %1
%endmacro

; shift left
%macro mshl 2
db 0x19, %1, %2
%endmacro

; shift right
%macro mshr 2
db 0x1a, %1, %2
%endmacro

; Compare
%macro mcmp 2
db 0x20
%endmacro

; Conditional jumps

; Jump if zero / jump if equal
%macro mjz 1
db 0x21
dw (%1 - ($ + 2))
%endmacro
%define mje mjz

; Jump if not zero / jump if not equal
%macro mjnz 1
db 0x22
dw (1% - ($ + 2))
%endmacro
%define mjne mjnz

; jump if carry/  jump if below
%macro mjc 1
db 0x23
dw (%1 - ($ + 2))
%endmacro
%define mjl mjc
%define mjb mjc

; Jump if not carry / jump if aboce or equal
%macro mjnc 1
db 0x24
dw (%1 - ($ + 2))
%endmacro
%define mjge mjnc
%define mjae mjnc

; Jump if below or equal
%macro mjbe 1
db 0x25
dw (%1 - ($ + 2))
%endmacro
%define mjle mjbe

; Jump if above
%macro mja 1
db 0x26
dw (%1 - ($ + 2))
%endmacro
%define mjg mja

; Stack's operators

; Push
%macro mpush 1
db 0x30, %1
%endmacro

; Pop
%macro mpop 1
db 0x31, %1
%endmacro

; Unconditional jumps

; Jump
%macro mjmp 1
db 0x40
dw (%1 - ($ + 2))
%endmacro

; Jump to address from register
%macro mjmpr 1
db 0x41, %1
%endmacro

; Call
%macro mcall 1
db 0x42
dw (%1 - ($ + 2))
%endmacro

; Call an address from register
%macro mcallr 1
db 0x43, %1
%endmacro

; Return
%macro mret 0
db 0x44
%endmacro

; Additional control instructions

; Control register load 
%macro mcrl 2
db 0xf0, %2
dw %1
%endmacro

; Control register strore
%macro mcrs 2
db 0xf1, %2
dw %1
%endmacro

; Output byte
%macro moutb 2
db 0xf2, %2, %1
%endmacro

; Input byte 
%macro minb 2
db 0xf3, %2, %1
%endmacro

; Interrupt return
%macro miret 0
db 0xf4
%endmacro

; 
%macro mcrsh 0
db 0xfe
%endmacro

; Power off
%macro moff 0
db 0xff
%endmacro





