#include "/home/codeleaded/System/Static/Library/ChipSet.h"

Chip_Def Chip_New_Custom_OR(ChipSet* cs){
    Chip_Def cd = Chip_Def_New(
        "COR",
        Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),
        Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE })
    );
    Vector_Push(&cd.chips,(Chip_Impl[]){ ChipSet_New_Impl(cs,"NOT") });
    Vector_Push(&cd.chips,(Chip_Impl[]){ ChipSet_New_Impl(cs,"NOT") });
    Vector_Push(&cd.chips,(Chip_Impl[]){ ChipSet_New_Impl(cs,"AND") });
    Vector_Push(&cd.chips,(Chip_Impl[]){ ChipSet_New_Impl(cs,"NOT") });

    Vector_Push(&cd.wires,(Chip_Wire[]){{ .src = 0U, .dst = 3U  }});
    Vector_Push(&cd.wires,(Chip_Wire[]){{ .src = 4U, .dst = 7U  }});
    Vector_Push(&cd.wires,(Chip_Wire[]){{ .src = 1U, .dst = 5U  }});
    Vector_Push(&cd.wires,(Chip_Wire[]){{ .src = 6U, .dst = 8U  }});
    Vector_Push(&cd.wires,(Chip_Wire[]){{ .src = 9U, .dst = 10U }});
    Vector_Push(&cd.wires,(Chip_Wire[]){{ .src = 11U,.dst = 2U  }});
    return cd;
}
Chip_Def Chip_New_Custom_HADD(ChipSet* cs){
    Chip_Def cd = Chip_Def_New(
        "CHADD",
        Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),
        Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE })
    );
    Vector_Push(&cd.chips,(Chip_Impl[]){ ChipSet_New_Impl(cs,"XOR") });
    Vector_Push(&cd.chips,(Chip_Impl[]){ ChipSet_New_Impl(cs,"AND") });

    Vector_Push(&cd.wires,(Chip_Wire[]){{ .src = 0U, .dst = 4U  }});
    Vector_Push(&cd.wires,(Chip_Wire[]){{ .src = 1U, .dst = 5U  }});
    Vector_Push(&cd.wires,(Chip_Wire[]){{ .src = 0U, .dst = 7U  }});
    Vector_Push(&cd.wires,(Chip_Wire[]){{ .src = 1U, .dst = 8U  }});
    Vector_Push(&cd.wires,(Chip_Wire[]){{ .src = 6U, .dst = 2U  }});
    Vector_Push(&cd.wires,(Chip_Wire[]){{ .src = 9U, .dst = 3U  }});
    return cd;
}

void ChipSet_Test(ChipSet* cs,CStr name){
    printf("------ %s ------\n",name);
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2;j++){
            Chip_Signal ins[] = { j,i };
            Chip_Signal outs[] = { 0x0ULL,0x0ULL };

            ChipSet_Exe(
                cs,
                name,
                ins,
                outs
            );

            printf("    CS: ");

            Chip_Def* cd = ChipSet_Find(cs,name);
            for(int k = 0;k<cd->inputs.size;k++){
                printf("%llx",ins[k]);
                if(k<cd->inputs.size - 1)
                    printf(",");
            }
            
            printf(" = ");

            for(int k = 0;k<cd->outputs.size;k++){
                printf("%llx",outs[k]);
                if(k<cd->outputs.size - 1)
                    printf(",");
            }

            printf("\n");
        }
    }
}

int main(){
    ChipSet cs = ChipSet_New();
    ChipSet_AddDLL(&cs,"./bin/std");
    
    ChipSet_AddChip(&cs,Chip_New_Custom_OR(&cs));
    ChipSet_AddChip(&cs,Chip_New_Custom_HADD(&cs));

    ChipSet_Test(&cs,"AND");
    ChipSet_Test(&cs,"NAND");
    ChipSet_Test(&cs,"OR");
    ChipSet_Test(&cs,"XOR");

    ChipSet_Test(&cs,"COR");
    ChipSet_Test(&cs,"CHADD");

    ChipSet_Print(&cs);
    ChipSet_Free(&cs);
    return 0;
}