#include "/home/codeleaded/System/Static/Library/ChipBench.h"

void ChipBench_Seg7_Std(ChipBench* cb,Chip_Def* cd,Chip_Signal* input,Chip_Signal* output){
    const int n0 = (input[0] / 1)   % 10;
    const int n1 = (input[0] / 10)  % 10;
    const int n2 = (input[0] / 100) % 10;
    //Sprite_RenderAlpha(window.Buffer,window.Width,window.Height,s7.digits + n2,0.0f,0.0f);
    //Sprite_RenderAlpha(window.Buffer,window.Width,window.Height,s7.digits + n1,s7.digits->w + 20.0f,0.0f);
    //Sprite_RenderAlpha(window.Buffer,window.Width,window.Height,s7.digits + n0,2 * (s7.digits->w + 20.0f),0.0f);
}

void Ex_Packer(void* Extern_Functions,Vector* funcs,ChipBench* cb){ // Vector<CStr>
    ChipSet_AddChip(
        &cb->cs,
        Chip_Def_New_DLL(
            "SEG7",
            Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),
            Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_NONE }),
            (void(*)(void*,struct Chip_Def*,Chip_Signal*,Chip_Signal*))ChipBench_Seg7_Std
        )
    );
}
