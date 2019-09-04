// Cnitgen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NBioAPI.h"




int _tmain(int argc, _TCHAR* argv[])
{

		NBioAPI_HANDLE g_hBSP; // NBioBSP module Handle.
		NBioAPI_UINT8 nIndex = 2;
		NBioAPI_UINT8 nData = 2;

		// 2 e 2 LFD Ativo e no maior nível.

	//	nIndex 0, nData 0 : Latent Off & LFD Off
	//	nIndex 0, nData 1 : Latent On & LFD On
	//	nIndex 0, nData 4 : Latent On & LFD Off(when it is 11, it works as Latent Off & LFD Off)
	//	nIndex 2, nData 0 : LFD Level Low
	//	nIndex 2, nData 1 : LFD Level Middle
	//	nIndex 2, nData 2 : LFD Level High


	// Inicializar moduloBSP 
	if ( NBioAPI_Init(&g_hBSP) != NBioAPIERROR_NONE )
	{

	}
	  	//abrir dispositivo com auto detecção do mesmo
	 NBioAPI_RETURN nRet = NBioAPI_OpenDevice(g_hBSP, NBioAPI_DEVICE_ID_AUTO);

	NBioAPI_WriteDataToDevice(g_hBSP, nIndex, nData);
	NBioAPI_FIR_HANDLE hFIR;	

	nRet = NBioAPI_Capture(g_hBSP, NBioAPI_FIR_PURPOSE_IDENTIFY, &hFIR, NBioAPI_USE_DEFAULT_TIMEOUT, NULL, NULL);

	printf("codigo de retorno %d", nRet);
	
	return 0;
}

