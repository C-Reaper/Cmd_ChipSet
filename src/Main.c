#include "/home/codeleaded/System/Static/Library/ChipBench.h"

int main(){
    ChipBench cb = ChipBench_New("./assets/digits");
    ChipBench_Load(&cb,"./bin/std");
    ChipBench_Load(&cb,"./bin/seg7");
    ChipBench_AddGUI(&cb,"SEG7",0U,0U,(Chip_Signal[]){ 0U });

    ChipBench_Print(&cb);
    ChipBench_Start(&cb);
    
    while(cb.w.Running){
        if(cb.w.Strokes[ALX_KEY_W].PRESSED){
            Chip_Signal ins[] = { cb.w.MouseX };
            Chip_Signal outs[] = { 0x0ULL };
            
            ChipSet_Exe(
                &cb.cs,
                "SEG7",
                ins,
                outs
            );
        }

        Thread_Sleep_M(1000);
    }

    ChipBench_Free(&cb);
    return 0;
}