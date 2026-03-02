#include "/home/codeleaded/System/Static/Library/ChipSet.h"

int main(){
    ChipSet cs = ChipSet_Make_Std();
    Chip_Signal outs[] = { 0x0ULL };

    ChipSet_Exe(
        &cs,
        "AND",
        (Chip_Signal[]){ 0x1ULL,0x1ULL },
        outs
    );
    printf("Out: %llu\n",outs[0]);

    ChipSet_Free(&cs);
    return 0;
}