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
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lb1;
	Win::Textbox tbxEntrada;
	Win::Label lb2;
	Win::Textbox tbxMinimo;
	Win::Label lb3;
	Win::Textbox tbxMaximo;
	Win::XyChart xy1;
	Win::Button btPlot;
protected:
	Win::Gdi::Font fontArial014A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx = Sys::Convert::PixelToDlgUnitX(465);
		dlgTemplate.cy = Sys::Convert::PixelToDlgUnitY(449);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"Grafica";
		lb1.Create(NULL, L"Ecuación: Escriba los coeficientes separados por coma", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 14, 8, 375, 25, hWnd, 1000);
		tbxEntrada.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 14, 40, 375, 25, hWnd, 1001);
		lb2.Create(NULL, L"Minimo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 21, 88, 70, 25, hWnd, 1002);
		tbxMinimo.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 91, 89, 72, 25, hWnd, 1003);
		lb3.Create(NULL, L"Maximo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 193, 89, 85, 25, hWnd, 1004);
		tbxMaximo.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 278, 90, 89, 25, hWnd, 1005);
		xy1.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_VISIBLE, 25, 143, 396, 299, hWnd, 1006);
		btPlot.Create(NULL, L"Plot", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 379, 91, 79, 28, hWnd, 1007);
		fontArial014A.Create(L"Arial", 14, false, false, false, false);
		lb1.Font = fontArial014A;
		tbxEntrada.Font = fontArial014A;
		lb2.Font = fontArial014A;
		tbxMinimo.Font = fontArial014A;
		lb3.Font = fontArial014A;
		tbxMaximo.Font = fontArial014A;
		xy1.Font = fontArial014A;
		btPlot.Font = fontArial014A;
	}
	//_________________________________________________
	void tbxMaximo_Change(Win::Event& e);
	void btPlot_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (tbxMaximo.IsEvent(e, EN_CHANGE)) {tbxMaximo_Change(e); return true;}
		if (btPlot.IsEvent(e, BN_CLICKED)) {btPlot_Click(e); return true;}
		return false;
	}
};
