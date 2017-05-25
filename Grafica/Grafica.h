#pragma once  //______________________________________ Grafica.h  
#include "Resource.h"
class Grafica : public Win::Dialog
{
public:
	Grafica()
	{
	}
	~Grafica()
	{
	}
	void RefreshGraph();
	double EvaluateFunction(const valarray<double>& coeficientes, double x);
	double ComputeY(double x);
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::XyChart xy1;
protected:
	Win::Gdi::Font fontArial014A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx = Sys::Convert::PixelToDlgUnitX(423);
		dlgTemplate.cy = Sys::Convert::PixelToDlgUnitY(313);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"Grafica";
		xy1.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_VISIBLE, 20, 7, 396, 299, hWnd, 1000);
		fontArial014A.Create(L"Arial", 14, false, false, false, false);
		xy1.Font = fontArial014A;
	}
	//_________________________________________________
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		return false;
	}
};
