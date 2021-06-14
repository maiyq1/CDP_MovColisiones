#pragma once
#include "Dependencias.h"

class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
public:
	Entidad()
	{
		x = y = 0;
		dx = dy = 0;
		ancho = alto = 0;
	}
	
	void SetDX(int value)
	{
		dx = value;
	}
	void SetDY(int value)
	{
		dy = value;
	}

	Rectangle Area() //posicion actual del rectangulo
	{
		return Rectangle(x, y, ancho, alto);
	}
	Rectangle NextArea() //siguiente posicion
	{
		return Rectangle(x + dx, y + dy, ancho, alto);
	}

	virtual void Mover(Graphics^ g)
	{
		x += dx;
		y += dy;
	}
	virtual void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->FillRectangle(Brushes::White, Area());
	}
};