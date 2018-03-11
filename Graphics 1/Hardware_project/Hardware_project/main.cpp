// CGS HW Project A "Line Land".
// Author: L.Norri CD CGS, FullSail University

// Introduction:
// Welcome to the hardware project of the Computer Graphics Systems class.
// This assignment is fully guided but still requires significant effort on your part. 
// Future classes will demand the habits & foundation you develop right now!  
// It is CRITICAL that you follow each and every step. ESPECIALLY THE READING!!!

// TO BEGIN: Open the word document that acompanies this project and start from the top.

//************************************************************
//************ INCLUDES & DEFINES ****************************
//************************************************************

#include <iostream>
#include <ctime>
#include "XTime.h"
#include <DirectXMath.h>


using namespace std;



// BEGIN PART 1
// TODO: PART 1 STEP 1a

#include <d3d11.h>
#pragma comment (lib, "d3d11.lib")

// TODO: PART 1 STEP 1b
using namespace DirectX;
// TODO: PART 2 STEP 6

IDXGISwapChain* swapChain;
ID3D11Device* device;
D3D_FEATURE_LEVEL selectedLevel;
ID3D11DeviceContext* context;

ID3D11Resource* backBuffer;
ID3D11RenderTargetView* view;

D3D11_VIEWPORT viewport;

#define BACKBUFFER_WIDTH	500
#define BACKBUFFER_HEIGHT	500

void InitializeD3D(HWND inHwnd);

//************************************************************
//************ SIMPLE WINDOWS APP CLASS **********************
//************************************************************

class DEMO_APP
{
	HINSTANCE						application;
	WNDPROC							appWndProc;
	HWND							window;
	// TODO: PART 1 STEP 2

	// TODO: PART 2 STEP 2

	// BEGIN PART 5
	// TODO: PART 5 STEP 1

	// TODO: PART 2 STEP 4

	// BEGIN PART 3
	// TODO: PART 3 STEP 1

	// TODO: PART 3 STEP 2b

	// TODO: PART 3 STEP 4a

public:
	// BEGIN PART 2
	// TODO: PART 2 STEP 1

	DEMO_APP(HINSTANCE hinst, WNDPROC proc);
	bool Run();
	bool ShutDown();
};

//************************************************************
//************ CREATION OF OBJECTS & RESOURCES ***************
//************************************************************

DEMO_APP::DEMO_APP(HINSTANCE hinst, WNDPROC proc)
{
	// ****************** BEGIN WARNING ***********************// 
	// WINDOWS CODE, I DON'T TEACH THIS YOU MUST KNOW IT ALREADY! 
	application = hinst;
	appWndProc = proc;

	WNDCLASSEX  wndClass;
	ZeroMemory(&wndClass, sizeof(wndClass));
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.lpfnWndProc = appWndProc;
	wndClass.lpszClassName = L"DirectXApplication";
	wndClass.hInstance = application;
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
	//wndClass.hIcon			= LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_FSICON));
	RegisterClassEx(&wndClass);

	RECT window_size = { 0, 0, BACKBUFFER_WIDTH, BACKBUFFER_HEIGHT };
	AdjustWindowRect(&window_size, WS_OVERLAPPEDWINDOW, false);

	window = CreateWindow(L"DirectXApplication", L"CGS Hardware Project", WS_OVERLAPPEDWINDOW & ~(WS_THICKFRAME | WS_MAXIMIZEBOX),
		CW_USEDEFAULT, CW_USEDEFAULT, window_size.right - window_size.left, window_size.bottom - window_size.top,
		NULL, NULL, application, this);

	ShowWindow(window, SW_SHOW);
	//********************* END WARNING ************************//

	// TODO: PART 1 STEP 3a

	// TODO: PART 1 STEP 3b
	InitializeD3D(window);
	// TODO: PART 1 STEP 4

	// TODO: PART 1 STEP 5

	// TODO: PART 2 STEP 3a

	// BEGIN PART 4
	// TODO: PART 4 STEP 1

	// TODO: PART 2 STEP 3b

	// TODO: PART 2 STEP 3c

	// TODO: PART 2 STEP 3d

	// TODO: PART 5 STEP 2a

	// TODO: PART 5 STEP 2b

	// TODO: PART 5 STEP 3

	// TODO: PART 2 STEP 5
	// ADD SHADERS TO PROJECT, SET BUILD OPTIONS & COMPILE

	// TODO: PART 2 STEP 7

	// TODO: PART 2 STEP 8a

	// TODO: PART 2 STEP 8b

	// TODO: PART 3 STEP 3

	// TODO: PART 3 STEP 4b

}

//************************************************************
//************ EXECUTION *************************************
//************************************************************

bool DEMO_APP::Run()
{
	// TODO: PART 4 STEP 2	

	// TODO: PART 4 STEP 3

	// TODO: PART 4 STEP 5

	// END PART 4

	// TODO: PART 1 STEP 7a

	// TODO: PART 1 STEP 7b

	// TODO: PART 1 STEP 7c

	// TODO: PART 5 STEP 4

	// TODO: PART 5 STEP 5

	// TODO: PART 5 STEP 6

	// TODO: PART 5 STEP 7

	// END PART 5

	// TODO: PART 3 STEP 5

	// TODO: PART 3 STEP 6

	// TODO: PART 2 STEP 9a

	// TODO: PART 2 STEP 9b

	// TODO: PART 2 STEP 9c

	// TODO: PART 2 STEP 9d

	// TODO: PART 2 STEP 10

	// END PART 2

	// TODO: PART 1 STEP 8

	// END OF PART 1
	return true;
}

//************************************************************
//************ DESTRUCTION ***********************************
//************************************************************

bool DEMO_APP::ShutDown()
{
	// TODO: PART 1 STEP 6

	UnregisterClass(L"DirectXApplication", application);
	return true;
}

void InitializeD3D(HWND inHwnd) {
	DXGI_SWAP_CHAIN_DESC swapChainDiscription;
	ZeroMemory(&swapChainDiscription, sizeof(DXGI_SWAP_CHAIN_DESC));

	swapChainDiscription.BufferDesc.Width = BACKBUFFER_WIDTH;
	swapChainDiscription.BufferDesc.Height = BACKBUFFER_HEIGHT;

	swapChainDiscription.BufferDesc.RefreshRate.Numerator = 1;
	swapChainDiscription.BufferDesc.RefreshRate.Denominator = 60;// 1/60 is 60 frames a second

	swapChainDiscription.BufferDesc.Format = DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_UNORM;//The same hex format we used for our labs

	swapChainDiscription.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER::DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;//Who knows? Not this guy.

	swapChainDiscription.BufferDesc.Scaling = DXGI_MODE_SCALING::DXGI_MODE_SCALING_UNSPECIFIED;

	swapChainDiscription.SampleDesc.Count = 4;
	swapChainDiscription.SampleDesc.Quality = 0;

	swapChainDiscription.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDiscription.BufferCount = 1;//How many back buffers. we have 1

	swapChainDiscription.OutputWindow = inHwnd;
	swapChainDiscription.Windowed = true;

	swapChainDiscription.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;//What we do after we swap front and back buffers

	swapChainDiscription.Flags = 0;


	D3D_FEATURE_LEVEL featureLevelArray[] = {
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,


	};
#ifdef _DEBUG
	HRESULT result = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, D3D10_CREATE_DEVICE_SINGLETHREADED | D3D10_CREATE_DEVICE_BGRA_SUPPORT | D3D11_CREATE_DEVICE_DEBUG,
		featureLevelArray, ARRAYSIZE(featureLevelArray), D3D11_SDK_VERSION,
		&swapChainDiscription, &swapChain, &device, &selectedLevel,
		&context);

	#else
	HRESULT result = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, D3D10_CREATE_DEVICE_SINGLETHREADED | D3D10_CREATE_DEVICE_BGRA_SUPPORT,
		featureLevelArray, ARRAYSIZE(featureLevelArray), D3D11_SDK_VERSION,
		&swapChainDiscription, &swapChain, &device, &selectedLevel,
		&context);

#endif


	swapChain->GetBuffer(0, __uuidof(backBuffer), reinterpret_cast<void**>(&backBuffer));

	device->CreateRenderTargetView(backBuffer, NULL, &view);

	
	viewport.Height = BACKBUFFER_HEIGHT;
	viewport.Width = BACKBUFFER_WIDTH;
	viewport.MaxDepth = 1;
	viewport.MinDepth = 0;
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;


}

void cleanUp() {

	if (swapChain)	swapChain->Release();
	if (device) 	device->Release();
	if (context)	context->Release();
}

//************************************************************
//************ WINDOWS RELATED *******************************
//************************************************************

// ****************** BEGIN WARNING ***********************// 
// WINDOWS CODE, I DON'T TEACH THIS YOU MUST KNOW IT ALREADY!

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR, int)
{
	srand(unsigned int(time(0)));
	DEMO_APP myApp(hInstance, (WNDPROC)WndProc);
	MSG msg; ZeroMemory(&msg, sizeof(msg));

	//Setting the globals to 0 to ensure they are initialized

	

	
	context->OMSetRenderTargets(1, &view, 0);
	context->RSSetViewports(1, &viewport);

	float darkBlue[4] = { 0.1f, 0.0f, 1.0f, 1.0f };
	
	while (msg.message != WM_QUIT && myApp.Run())
	{
		context->ClearRenderTargetView(view, darkBlue);
		swapChain->Present(0, 0);
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	cleanUp();//Releases pointers
	myApp.ShutDown();
	return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (GetAsyncKeyState(VK_ESCAPE))
		message = WM_DESTROY;
	switch (message)
	{
	case (WM_DESTROY): { PostQuitMessage(0); }
					   break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
//********************* END WARNING ************************//



