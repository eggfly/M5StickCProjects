#include "Delay.H"
#include "ch554_platform.h"

void mDelayuS(uint16_t n ) {
#ifdef	CLOCK_CFG
#if		CLOCK_CFG <= 6000000
		n >>= 2;
#endif
#if		CLOCK_CFG <= 3000000
		n >>= 2;
#endif
#if		CLOCK_CFG <= 750000
		n >>= 4;
#endif
#endif
	while ( n ) {
		++ SAFE_MOD;
#ifdef	CLOCK_CFG
#if		CLOCK_CFG >= 14000000
		++ SAFE_MOD;
#endif
#if		CLOCK_CFG >= 16000000
		++ SAFE_MOD;
#endif
#if		CLOCK_CFG >= 18000000
		++ SAFE_MOD;
#endif
#if		CLOCK_CFG >= 20000000
		++ SAFE_MOD;
#endif
#if		CLOCK_CFG >= 22000000
		++ SAFE_MOD;
#endif
#if		CLOCK_CFG >= 24000000
		++ SAFE_MOD;
#endif
#if		CLOCK_CFG >= 26000000
		++ SAFE_MOD;
#endif
#if		CLOCK_CFG >= 28000000
		++ SAFE_MOD;
#endif
#if		CLOCK_CFG >= 30000000
		++ SAFE_MOD;
#endif
#if		CLOCK_CFG >= 32000000
		++ SAFE_MOD;
#endif
#endif
		-- n;
	}
}

void mDelaymS(uint16_t n ) {
	while ( n ) {
#ifdef	DELAY_MS_HW
		while ( ( TKEY_CTRL & bTKC_IF ) == 0 );
		while ( TKEY_CTRL & bTKC_IF );
#else
		mDelayuS(1000);
#endif
		-- n;
	}
}                                         
