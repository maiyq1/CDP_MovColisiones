#pragma once
#include "Entidad.h"

class Jugador : public Entidad
{
public:
	Jugador()
	{
		x = y = 70;
		dx = dy = 0;
		ancho = alto = 40;
	}
	void Mover(Graphics^ g)
	{
		if (x + dx >= 0 && x + dx + ancho < g->VisibleClipBounds.Width)
			x += dx;
		if (y + dy >= 0 && y + dy + alto < g->VisibleClipBounds.Height)
			y += dy;

	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->FillRectangle(Brushes::Green, Area());
	}
};