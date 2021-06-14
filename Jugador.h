#pragma once
#include "Entidad.h"

class Jugador : public Entidad
{
public:
	Jugador(Bitmap^ img)
	{
		x = y = 70;
		dx = dy = 0;
		ancho = img->Width / 13;
		alto = img->Height / 13;
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
		Rectangle corte = Rectangle(0, 0, 64, 64);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
	}
};