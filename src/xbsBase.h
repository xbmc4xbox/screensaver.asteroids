#ifndef _XBS_BASE_H_
#define _XBS_BASE_H_

//Include correct headers/includes for XBOX or PC test mode
#ifdef _TEST //PC TEST MODE
	// DX8 PC libraries
	#pragma comment(lib, "D3d8.lib")
	#pragma comment(lib, "D3dx8.lib")
	// DX8 PC Include
	#include <d3dx8.h>

	#define d3dSetRenderState			d3dDevice->SetRenderState
	#define d3dGetRenderState			d3dDevice->GetRenderState
	#define d3dSetTextureStageState		d3dDevice->SetTextureStageState
#else // XBOX mode
	// use the 'dummy' dx8 lib - this allow you to make
	// DX8 calls which XBMC will emulate for you.
	#pragma comment (lib, "lib/xbox_dx8.lib" )
	#include <xtl.h>

	extern "C" void d3dGetRenderState(DWORD dwY, DWORD* dwZ);
	extern "C" void d3dSetRenderState(DWORD dwY, DWORD dwZ);
	extern "C" void d3dSetTextureStageState( int x, DWORD dwY, DWORD dwZ);
#endif

#endif
