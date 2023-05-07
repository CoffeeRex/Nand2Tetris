#ifndef INSTRUCTION_TYPES_H
#define INSTRUCTION_TYPES_H

enum InstructionType {
        A_INSTRUCTION,
        C_INSTRUCTION,
        L_INSTRUCTION,
        NULL_INSTRUCTION
    };

    enum InstructionDest {
        A,
        D,
        M,
        AM,
        AD,
        MD,
        AMD,
        NULL_DEST
    };

    enum InstructionJump {
        JLT,
        JGT,
        JEQ,
        JLE,
        JGE,
        JNE,
        JMP,
        NULL_JUMP
    };

    enum InstructionComp {
        CONST_0,
        CONST_1,
        CONST_NEG_1,
        VAL_A,
        VAL_M,
        VAL_D,
        NOT_A,
        NOT_M,
        NOT_D,
        NEG_A,
        NEG_M,
        NEG_D,
        A_ADD_1,
        M_ADD_1,
        D_ADD_1,
        A_SUB_1,
        M_SUB_1,
        D_SUB_1,
        D_ADD_A,
        D_ADD_M,
        D_SUB_A,
        D_SUB_M,
        A_SUB_D,
        M_SUB_D,
        D_AND_A,
        D_AND_M,
        D_OR_A,
        D_OR_M,
        NULL_COMP
    };


#endif