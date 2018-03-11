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
#include <Windows.h>
#include "XTime.h"
#include <DirectXMath.h>
#include "Trivial_PS.csh"
#include "Trivial_VS.csh"


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

ID3D11VertexShader *VS;
ID3D11PixelShader *PS;
ID3D11Buffer *VertexBuffer;
ID3D11Buffer *ConstantBuffer;
ID3D11InputLayout *inputLayout;

ID3D11Buffer *CubeVertexBuffer;
ID3D11Buffer *CubeConstantBuffer;
ID3D11InputLayout *CubeinputLayout;

XTime timer;

float verticalOffset = 0;
float horizontalOffset = 0;


int horizontalDirection = 1;

int verticalDirection = 1;

struct SIMPLE_VERTEX {
	XMFLOAT2 location1;


	XMFLOAT4 rgba;

	SIMPLE_VERTEX() {
		location1 = XMFLOAT2(0, 0);


		rgba = XMFLOAT4(0, 0, 0, 0);
	}

	SIMPLE_VERTEX(XMFLOAT2 inlocation1) {
		location1 = inlocation1;

		rgba = XMFLOAT4(0, 0, 0, 0);
	}

	SIMPLE_VERTEX(XMFLOAT2 inlocation1, XMFLOAT4 inColors) {
		location1 = inlocation1;

		rgba = inColors;
	}
};

struct SEND_TO_VRAM
{
	XMFLOAT4 constantColor;
	XMFLOAT2 constantOffset;
	XMFLOAT2 padding;

	SEND_TO_VRAM() {
		constantOffset = XMFLOAT2(0, 0);


		constantColor = XMFLOAT4(0, 0, 0, 0);
	}

	SEND_TO_VRAM(XMFLOAT2 inlocation1) {
		constantOffset = inlocation1;

		constantColor = XMFLOAT4(0, 0, 0, 0);
	}

	SEND_TO_VRAM(XMFLOAT2 inlocation1, XMFLOAT4 inColors) {
		constantOffset = inlocation1;

		constantColor = inColors;
	}

};

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
	if (backBuffer) backBuffer->Release();
	if (VS)			VS->Release();
	if (PS)			PS->Release();
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
		timer.Signal();


#pragma region Bounce the circle
		horizontalOffset += timer.Delta() * (float)horizontalDirection;
		verticalOffset += timer.Delta() / 2 * (float)verticalDirection;
		if (abs(horizontalOffset) > 1)
			horizontalDirection *= -1;
		if (abs(verticalOffset) > 1)
			verticalDirection *= -1;
#pragma endregion


#pragma region Circle creation
		const unsigned int pointCount = 361;
		SIMPLE_VERTEX vertCircle[pointCount];
		for (int i = 0; i < 360; i++)
		{
			vertCircle[i] = SIMPLE_VERTEX(
				XMFLOAT2(
					cos(XMConvertToRadians((float)i)) * 0.2,
					sin(XMConvertToRadians((float)i)) * 0.2),

				XMFLOAT4(1, 1, 1, 1));
		}
		vertCircle[360] = vertCircle[0];

		D3D11_INPUT_ELEMENT_DESC vertexLayout[] = {
			{ "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};

#pragma endregion
#pragma region Create shaders and buffers for them
		device->CreateVertexShader(Trivial_VS, sizeof(Trivial_VS), NULL, &VS);
		device->CreatePixelShader(Trivial_PS, sizeof(Trivial_PS), NULL, &PS);
#pragma region Buffer 1



		D3D11_BUFFER_DESC bufferDiscription;
		ZeroMemory(&bufferDiscription, sizeof(bufferDiscription));
		bufferDiscription.Usage = D3D11_USAGE_DYNAMIC;
		bufferDiscription.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bufferDiscription.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		bufferDiscription.ByteWidth = sizeof(SIMPLE_VERTEX) * pointCount;
		device->CreateBuffer(&bufferDiscription, NULL, &VertexBuffer);

		D3D11_MAPPED_SUBRESOURCE mappedSubresource;
		context->Map(VertexBuffer, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &mappedSubresource);
		memcpy(mappedSubresource.pData, vertCircle, sizeof(vertCircle));
		context->Unmap(VertexBuffer, NULL);

#pragma endregion
#pragma region Buffer 2


		D3D11_BUFFER_DESC bufferDiscription2;
		ZeroMemory(&bufferDiscription2, sizeof(bufferDiscription2));
		bufferDiscription2.Usage = D3D11_USAGE_DYNAMIC;
		bufferDiscription2.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		bufferDiscription2.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		bufferDiscription2.ByteWidth = sizeof(SEND_TO_VRAM);
		device->CreateBuffer(&bufferDiscription2, NULL, &ConstantBuffer);


		SEND_TO_VRAM toShader(XMFLOAT2(horizontalOffset, verticalOffset), XMFLOAT4(1, 1, 0, 1));



		D3D11_MAPPED_SUBRESOURCE mappedSubresource2;
		context->Map(ConstantBuffer, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &mappedSubresource2);
		memcpy(mappedSubresource2.pData, &toShader, sizeof(toShader));
		context->Unmap(ConstantBuffer, NULL);
#pragma endregion

		device->CreateInputLayout(vertexLayout, 2, Trivial_VS, sizeof(Trivial_VS), &inputLayout);
		context->IASetInputLayout(inputLayout);

		context->VSSetShader(VS, 0, 0);
		context->PSSetShader(PS, 0, 0);
#pragma endregion
#pragma region Grid Creation
		const unsigned int squareRows = 20;
		const unsigned int squareCol = 10;
		const unsigned int squareCount = squareRows * squareCol;
		const unsigned int gridPointCount = 4;
		SIMPLE_VERTEX gridArray[squareRows][squareCol][gridPointCount];
		for (int i = 0; i < squareRows; i++)
		{
			for (int j = 0; j < squareCol; j++)
			{
				float offsetX;
				float offsetY;
				if (i % 2 == 0)	//Evens
					offsetX = 0.1 * j * 2;
				else			//Odds
					offsetX = 0.1 * j * 2 - 0.1;

				gridArray[i][j][0] = XMFLOAT2(-0.9f + offsetX, 0.9f - 0.1 *i);
				gridArray[i][j][1] = XMFLOAT2(-0.9f + offsetX, 1.0f - 0.1 *i);
				gridArray[i][j][2] = XMFLOAT2(-0.8f + offsetX, 0.9f - 0.1 *i);
				gridArray[i][j][3] = XMFLOAT2(-0.8f + offsetX, 1.0f - 0.1 *i);


			}
		}
#pragma endregion
#pragma region Cube Buffer 1



		D3D11_BUFFER_DESC CubebufferDiscription;
		ZeroMemory(&CubebufferDiscription, sizeof(CubebufferDiscription));
		CubebufferDiscription.Usage = D3D11_USAGE_DYNAMIC;
		CubebufferDiscription.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		CubebufferDiscription.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		CubebufferDiscription.ByteWidth = sizeof(SIMPLE_VERTEX) * squareCount * 4;
		device->CreateBuffer(&CubebufferDiscription, NULL, &CubeVertexBuffer);

		D3D11_MAPPED_SUBRESOURCE CubemappedSubresource;
		context->Map(CubeVertexBuffer, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &CubemappedSubresource);
		memcpy(CubemappedSubresource.pData, gridArray, sizeof(gridArray));
		context->Unmap(CubeVertexBuffer, NULL);

#pragma endregion
#pragma region Cube Buffer 2


		D3D11_BUFFER_DESC CubebufferDiscription2;
		ZeroMemory(&CubebufferDiscription2, sizeof(CubebufferDiscription2));
		CubebufferDiscription2.Usage = D3D11_USAGE_DYNAMIC;
		CubebufferDiscription2.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		CubebufferDiscription2.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		CubebufferDiscription2.ByteWidth = sizeof(SEND_TO_VRAM);
		device->CreateBuffer(&CubebufferDiscription2, NULL, &CubeConstantBuffer);


		SEND_TO_VRAM CubetoShader(XMFLOAT2(0, 0), XMFLOAT4(0, 0, 0, 1));



		D3D11_MAPPED_SUBRESOURCE CubemappedSubresource2;
		context->Map(CubeConstantBuffer, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &CubemappedSubresource2);
		memcpy(CubemappedSubresource2.pData, &CubetoShader, sizeof(CubetoShader));
		context->Unmap(CubeConstantBuffer, NULL);
#pragma endregion


#pragma region Draw Grid
		UINT gridStride = sizeof(SIMPLE_VERTEX);
		UINT offset = 0;

		context->IASetVertexBuffers(0, 1, &CubeVertexBuffer, &gridStride, &offset);
		context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
		context->VSSetConstantBuffers(0, 1, &CubeConstantBuffer);
		for (int i = 0; i < squareCount; i++)
		{
			context->Draw(4, i * 4);
		}

#pragma endregion
#pragma region Draw Circle
		UINT stride = sizeof(SIMPLE_VERTEX);

		context->IASetVertexBuffers(0, 1, &VertexBuffer, &stride, &offset);
		context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
		context->VSSetConstantBuffers(0, 1, &ConstantBuffer);
		context->Draw(pointCount, 0);
#pragma endregion



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



