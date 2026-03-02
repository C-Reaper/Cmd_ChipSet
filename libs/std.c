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

void ChipSet_Std_Lib_OR(ChipSet* cs,Chip_Def* cd,Chip_Signal* ins,Chip_Signal* outs){
    *outs = ins[0] | ins[1];
}

void Ex_Packer(void* Extern_Functions,Vector* funcs,ChipSet* cs){ // Vector<CStr>
    ChipSet_AddChip(cs,Chip_Def_New_Fn("NOT", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),                   Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_NOT    ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("AND", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_AND    ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("NAND",Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_NAND   ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("OR",  Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_OR     ));
    ChipSet_AddChip(cs,Chip_Def_New_Fn("XOR", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),ChipSet_Std_XOR    ));
    
    //ChipSet_AddChip(
    //    &cs,Chip_Def_New_Fn(
    //        "OR",
    //        Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),
    //        Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),
    //        ChipSet_Std_OR
    //));
}
