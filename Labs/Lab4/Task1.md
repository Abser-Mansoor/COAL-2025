MOV AX 3d -> no comma (syntax error)\
MOV 23, AX -> asignment to immediate number (logical error)\
MOV CX, CH -> assignment of separate sized registers (logical error)\
MOVE AX, 1h -> MOVE is not a valid command (syntax error)\
ADD 2, CX -> assignment to immediate number (logical error)\
ADD 3, 6 -> assignment to immediate number (logical error)\
INC AX, 2 -> inc does not take any source operand (syntax error)\
