#include "/home/codeleaded/System/Static/Library/ChipBench.h"

void ChipBench_Seg7_Std(ChipBench* cb,Chip_Def* cd,Chip_Signal* input,Chip_Signal* output){
    // Set
}

void ChipBench_Seg7_Render(ChipBench* cb,ChipGUI_Impl* cgi){
    Chip_Signal cs = *(Chip_Signal*)cgi->data;

    const int n0 = (cs / 1)   % 10;
    const int n1 = (cs / 10)  % 10;
    const int n2 = (cs / 100) % 10;
    
    //Sprite_RenderAlpha(cb->w.Buffer,cb->w.Width,cb->w.Height,s7.digits + n2,0.0f,0.0f);
    //Sprite_RenderAlpha(cb->w.Buffer,cb->w.Width,cb->w.Height,s7.digits + n1,s7.digits->w + 20.0f,0.0f);
    //Sprite_RenderAlpha(cb->w.Buffer,cb->w.Width,cb->w.Height,s7.digits + n0,2 * (s7.digits->w + 20.0f),0.0f);

    const float X = 20.0f;
    const float Y = 20.0f;
    const float paddingX = 10.0f;
    const float paddingY = 10.0f;

    Rect_RenderXX(cb->w.Buffer,cb->w.Width,cb->w.Height,X,Y,cb->s7.width + 2 * paddingX,cb->s7.height + 2 * paddingY,BLACK);
    Sprite_RenderAlpha(cb->w.Buffer,cb->w.Width,cb->w.Height,cb->s7.digits + n0,X + paddingX,Y + paddingY);
}
void ChipBench_Seg7_Free(ChipBench* cb,ChipGUI_Impl* cgi){
    
}
void ChipBench_Seg7_Pipe(ChipBench* cb,ChipGUI_Impl* cgi,ChipPipe_Type ct){
    
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
    ChipBench_AddDef(
        cb,
        ChipGUI_Def_New(
            "SEG7",0U,
            sizeof(Chip_Signal),
            (void(*)(void*,ChipGUI_Impl*))ChipBench_Seg7_Render,
            (void(*)(void*,ChipGUI_Impl*))ChipBench_Seg7_Free,
            (void(*)(void*,ChipGUI_Impl*,ChipPipe_Type))ChipBench_Seg7_Pipe
        )
    );
}
