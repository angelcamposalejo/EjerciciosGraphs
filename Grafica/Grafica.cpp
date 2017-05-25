#include "stdafx.h"  //________________________________________ Grafica.cpp
#include "Grafica.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR cmdLine, int cmdShow) {
	Grafica app;
	return app.BeginDialog(IDI_Grafica, hInstance);
}

void Grafica::Window_Open(Win::Event& e)
{
	//________________________________________________________ xy1
	xy1.CaptionX = L"Axis X";
	xy1.CaptionY = L"Axis Y";
	xy1.MinX = 0.0;
	xy1.MaxX = 10.0;
	xy1.MinY = -1.0;
	xy1.MaxY = 1.0;
	xy1.Graphs.Add(100);
	for (int i = 0; i<100; i++)
	{
		xy1.Graphs[0][i].x = 0.0;
		xy1.Graphs[0][i].y = 0.0;
	}
	//xy1.Graphs[0].Color = RGB(0, 0, 255);
	//xy1.Graphs[0].Type = Win::Graph::circle;
	//xy1.Graphs[0].Caption = L"My Function";
	xy1.RefreshAll();
}

void Grafica::tbxEntrada_Change(Win::Event& e)
{
	RefreshGraph();
}

void Grafica::RefreshGraph()
{
	if (tbxEntrada.Text.length() == 0)return;
	const double minX = this->tbxMinimo.DoubleValue;
	const double maxX = this->tbxMaximo.DoubleValue;
	if (minX >= maxX)return;
	valarray<double>coeficientes;
	Sys::Convert::ToVector(tbxEntrada.Text, coeficientes);
	const int orden = coeficientes.size() - 1;
	if (orden <= 0)return;
	xy1.MinX = minX;
	xy1.MaxX = maxX;
	const double deltaX = (maxX - minX) / 100;
	double x = 0.0;
	for (int i = 0; i < 100; i++)
	{
		x = minX + i*deltaX;
		xy1.Graphs[0][i].x = x;
		xy1.Graphs[0][i].y = EvaluateFunction(coeficientes, x);
	}
	xy1.AutoScaleY();
	xy1.RefreshAll();
}
double Grafica::EvaluateFunction(const valarray<double>& coeficientes, double x)
{
	double evaluacion = 0.0;
	const int orden = coeficientes.size() - 1;
	for (int i = 0, j = orden; i < orden; i++, j--)
	{
		evaluacion = (1 * coeficientes[i] * pow(x, j)) + evaluacion;
	}
	return evaluacion;
}
void Grafica::tbxMinimo_Change(Win::Event& e)
{
	RefreshGraph();
}

void Grafica::tbxMaximo_Change(Win::Event& e)
{
	RefreshGraph();
}

