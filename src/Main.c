#include "/home/codeleaded/System/Static/Library/ChipBench.h"

int main(){
    ChipBench cb = ChipBench_New("./assets/digits");

    ChipBench_Load(&cb,"./bin/std");
    ChipBench_Load(&cb,"./bin/seg7");


    Chip_Def cd = Chip_Def_New(
        "MAIN",
        Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),
        Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_NONE })
    );
    Vector_Push(&cd.chips,(Chip_Impl[]){ ChipSet_New_Impl(&cb.cs,"SEG7") });
    Vector_Push(&cd.chips,(Chip_Impl[]){ ChipSet_New_Impl(&cb.cs,"SEG7") });
    Vector_Push(&cd.wires,(Chip_Wire[]){{ .src = 0U, .dst = 2U  }});
    Vector_Push(&cd.wires,(Chip_Wire[]){{ .src = 1U, .dst = 3U  }});
    ChipSet_AddChip(&cb.cs,cd);
    ChipBench_AddGUI(&cb,"SEG7",10U,0U,  (Chip_Impl*[]){ (Chip_Impl*)Vector_Get(&cd.chips,0) });
    ChipBench_AddGUI(&cb,"SEG7",10U,250U,(Chip_Impl*[]){ (Chip_Impl*)Vector_Get(&cd.chips,1) });


    ChipBench_Print(&cb);
    ChipBench_Start(&cb);
    
    while(cb.w.Running){
        if(cb.w.Strokes[ALX_MOUSE_L].PRESSED){
            Chip_Signal ins[] = { cb.w.MouseX,cb.w.MouseY };
            Chip_Signal outs[] = { 0x0ULL };
            
            ChipSet_Exe(
                &cb.cs,
                "MAIN",
                ins,
                outs
            );
        }

        if(!cb.w.Focus) Thread_Sleep_M(40);
        else            Thread_Sleep_M(2);
    }

    ChipBench_Free(&cb);
    return 0;
}