#include "/home/codeleaded/System/Static/Library/ChipSet.h"
#include "/home/codeleaded/System/Static/Library/DD7Segment.h"
#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"

ChipSet cs;
DD7Segment s7;

void ChipSet_Std_Seg7(Chip_Signal* input,Chip_Signal* output){
    //*output = input[0] ^ input[1];
    Chip_Def* cd = ChipSet_Find(&cs,"SEG7");
    if(cd){
        Clear(LIGHT_BLUE);

        const int n0 = (input[0] / 1)   % 10;
        const int n1 = (input[0] / 10)  % 10;
        const int n2 = (input[0] / 100) % 10;
        Sprite_RenderAlpha(window.Buffer,window.Width,window.Height,s7.digits + n2,0.0f,0.0f);
        Sprite_RenderAlpha(window.Buffer,window.Width,window.Height,s7.digits + n1,s7.digits->w + 20.0f,0.0f);
        Sprite_RenderAlpha(window.Buffer,window.Width,window.Height,s7.digits + n0,2 * (s7.digits->w + 20.0f),0.0f);
    }
}
Chip_Def Chip_New_Custom_MAIN(ChipSet* cs){
    Chip_Def cd = Chip_Def_New(
        "MAIN",
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

void Setup(AlxWindow* w){
    s7 = DD7Segment_New("./assets",200,400);
    cs = ChipSet_New();

    ChipSet_AddDLL(&cs,"./bin/std");
    ChipSet_AddChip(&cs,Chip_Def_New_Fn("SEG7", Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_64,CHIP_SIGNALSIZE_NONE }),Chip_SignalSize_Map_Make((Chip_SignalSize[]){ CHIP_SIGNALSIZE_NONE }),ChipSet_Std_Seg7));
    
    //ChipSet_AddChip(&cs,Chip_New_Custom_MAIN(&cs));
    //ChipSet_Print(&cs);

    Clear(LIGHT_BLUE);
}
void Update(AlxWindow* w){
    if(Stroke(ALX_KEY_W).PRESSED){
        Chip_Signal ins[] = { (int)GetMouse().x };
        Chip_Signal outs[] = { 0x0ULL };
        
        ChipSet_Exe(
            &cs,
            "SEG7",
            ins,
            outs
        );
    }
}
void Delete(AlxWindow* w){
    ChipSet_Free(&cs);
	DD7Segment_Free(&s7);
}

int main(){
    if(Create("ChipSet - 7Seg",1900,1000,1,1,Setup,Update,Delete))
        Start();
    return 0;
}
