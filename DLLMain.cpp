#include <kiero.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <iostream>
#include <assert.h>

typedef HRESULT(__thiscall* present_o)(IDXGISwapChain3*, UINT, UINT);
present_o presentO;

HRESULT presentH(IDXGISwapChain3* swapchain, UINT syncinterval, UINT flags) {
	printf("Present");
	return presentO(swapchain, syncinterval, flags);
}

void init() {
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout); // will only work if u have sum developer flags or smth
	if (kiero::init(kiero::RenderType::D3D12) == kiero::Status::Success) {
		kiero::bind(140, (void**)&presentO, presentH);
	}
}

bool WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpRes) {

	switch (fdwReason) {

	case DLL_PROCESS_ATTACH:

		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)init, hInstance, 0, 0);
		break;

	};

	return TRUE;

};
