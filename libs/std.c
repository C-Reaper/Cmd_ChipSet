#include "/home/codeleaded/System/Static/Library/ChipSet.h"

void ChipSet_Std_NOT(Chip_Signal* input,Chip_Signal* output){
    *output = ~(*input);
}
void ChipSet_Std_AND(Chip_Signal* input,Chip_Signal* output){
    *output = input[0] & input[1];
}
void ChipSet_Std_NAND(Chip_Signal* input,Chip_Signal* output){
    *output = ~(input[0] & input[1]);
}
void ChipSet_Std_OR(Chip_Signal* input,Chip_Signal* output){
    *output = input[0] | input[1];
}
void ChipSet_Std_XOR(Chip_Signal* input,Chip_Signal* output){
    *output = input[0] ^ input[1];
}
void ChipSet_Std_MUX(Chip_Signal* input,Chip_Signal* output){
    output[0] = input[2] ? input[0] : input[1];
}

void ChipSet_Std_ZERO(Chip_Signal* input,Chip_Signal* output){
    output[0] = 0U;
}
void ChipSet_Std_ONE(Chip_Signal* input,Chip_Signal* output){
    output[0] = 1U;
}

void ChipSet_Std_SHL(Chip_Signal* input,Chip_Signal* output){
    output[0] = input[0] << input[1];
}
void ChipSet_Std_SHR(Chip_Signal* input,Chip_Signal* output){
    output[0] = input[0] >> input[1];
}

void ChipSet_Std_ADD(Chip_Signal* input,Chip_Signal* output){
    output[0] = input[0] + input[1];
}
void ChipSet_Std_SUB(Chip_Signal* input,Chip_Signal* output){
    output[0] = input[0] - input[1];
}
void ChipSet_Std_MUL(Chip_Signal* input,Chip_Signal* output){
    output[0] = input[0] * input[1];
}
void ChipSet_Std_DIV(Chip_Signal* input,Chip_Signal* output){
    output[0] = input[0] / input[1];
}
void ChipSet_Std_NEG(Chip_Signal* input,Chip_Signal* output){
    output[0] = -input[0];
}

void ChipSet_Std_EQU(Chip_Signal* input,Chip_Signal* output){
    output[0] = input[0] == input[1];
}
void ChipSet_Std_NEQ(Chip_Signal* input,Chip_Signal* output){
    output[0] = input[0] != input[1];
}
void ChipSet_Std_GRT(Chip_Signal* input,Chip_Signal* output){
    output[0] = input[0] > input[1];
}
void ChipSet_Std_LES(Chip_Signal* input,Chip_Signal* output){
    output[0] = input[0] < input[1];
}
void ChipSet_Std_GRQ(Chip_Signal* input,Chip_Signal* output){
    output[0] = input[0] >= input[1];
}
void ChipSet_Std_LEQ(Chip_Signal* input,Chip_Signal* output){
    output[0] = input[0] <= input[1];
}

void ChipSet_Std_Lib_OR(ChipSet* cs,Chip_Def* cd,Chip_Signal* ins,Chip_Signal* outs){
    *outs = ins[0] | ins[1];
}

void Ex_Packer(void* Extern_Functions,Vector* funcs,ChipSet* cs){ // Vector<CStr>
    ChipSet_AddChip(cs,Chip_Def_New_Fn("NOT", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),                   Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_NOT    ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("AND", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_AND    ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("NAND",Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_NAND   ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("OR",  Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_OR     ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("XOR", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_XOR    ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("MUX", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_MUX    ));
    
    ChipSet_AddChip(cs,Chip_Def_New_Fn("ONE", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_ONE    ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("ZERO",Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_ZERO   ));
    
    ChipSet_AddChip(cs,Chip_Def_New_Fn("SHL", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_SHL    ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("SHR", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_SHR    ));
    
    ChipSet_AddChip(cs,Chip_Def_New_Fn("ADD", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_ADD    ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("SUB", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_SUB    ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("MUL", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_MUL    ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("DIV", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_DIV    ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("NEG", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),                   Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_NEG    ));
    
    ChipSet_AddChip(cs,Chip_Def_New_Fn("EQU", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_EQU    ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("NEQ", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_NEQ    ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("GRT", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_GRT    ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("LES", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_LES    ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("GRQ", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_GRQ    ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("LEQ", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_LEQ    ));
}
