#include <ch554.h>
#include <debug.h>

void main() {
    CfgFsys();

    P1_MOD_OC = 0xff;
    P1_DIR_PU = 0xff;

    while (1) {
    	mDelaymS(100);
        P1 = ~P1;
    }
}