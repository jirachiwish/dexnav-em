#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

#include "global.h"

#include "global.h"

typedef void (*MainCallback)(void);
typedef void (*IntrCallback)(void);
typedef void (*IntrFunc)(void);
typedef void (*EraseFlash)(u16);

struct Main
{
    /*0x000*/ MainCallback callback1;
    /*0x004*/ MainCallback callback2;

    /*0x008*/ MainCallback savedCallback;

    /*0x00C*/ IntrCallback vblankCallback;
    /*0x010*/ IntrCallback hblankCallback;
    /*0x014*/ IntrCallback vcountCallback;
    /*0x018*/ IntrCallback serialCallback;

    /*0x01C*/ vu16 intrCheck;

    /*0x020*/ u32 *vblankCounter1;
    /*0x024*/ u32 vblankCounter2;

    /*0x028*/ u16 heldKeysRaw;           // held keys without L=A remapping
    /*0x02A*/ u16 newKeysRaw;            // newly pressed keys without L=A remapping
    /*0x02C*/ u16 heldKeys;              // held keys with L=A remapping
    /*0x02E*/ u16 newKeys;               // newly pressed keys with L=A remapping
    /*0x030*/ u16 newAndRepeatedKeys;    // newly pressed keys plus key repeat
    /*0x032*/ u16 keyRepeatCounter;      // counts down to 0, triggering key repeat
    /*0x034*/ bool16 watchedKeysPressed; // whether one of the watched keys was pressed
    /*0x036*/ u16 watchedKeysMask;       // bit mask for watched keys

    /*0x038*/ struct OamData oamBuffer[128];

    /*0x438*/ u8 state;

    /*0x439*/ u8 oamLoadDisabled:1;
    /*0x439*/ u8 inBattle:1;
    /*0x439*/ u8 field_439_x4:1;
};

extern u8 gUnknown_3001764;
extern struct Main gMain;
extern bool8 gSoftResetDisabled;
extern bool8 gLinkVSyncDisabled;

extern const u8 gGameVersion;
extern const u8 gGameLanguage;

void __attribute__((long_call)) SetMainCallback1(MainCallback callback);
void __attribute__((long_call)) SetMainCallback2(MainCallback callback);

void __attribute__((long_call)) SetVBlankCallback(IntrCallback callback);
void __attribute__((long_call)) SetHBlankCallback(IntrCallback callback);


/*
void AgbMain(void);
void InitKeys(void);
void SetVCountCallback(IntrCallback callback);
void SetSerialCallback(IntrCallback callback);
void InitFlashTimer(void);
void DoSoftReset(void);
void ClearPokemonCrySongs(void);
*/
#endif // GUARD_MAIN_H
