#pragma once
#include "Jugador.h"
#include "Obstaculo.h"

//Mi Nuevo comentario

ref class Juego //ref para permitir usar el Bitmap
{
private:
	Jugador* player;
	Obstaculos* obj_obstaculos;
	Bitmap^ imgTroll;
	Bitmap^ imgPlayer;
public:
	Juego()
	{
		imgTroll = gcnew Bitmap("imagenes/troll.png");
		imgPlayer = gcnew Bitmap("imagenes/player.png");
		player = new Jugador(imgPlayer);
		obj_obstaculos = new Obstaculos(5, player->Area(), imgTroll);
	}
	~Juego()
	{
		delete player;
		delete obj_obstaculos;
		delete imgTroll;
	}

	void MovimientoJugador(bool accion, Keys tecla)
	{
		int velocidad = 4;
		if (accion == true)
		{
			if (tecla == Keys::Up)
				player->SetDY(-velocidad);
			else if (tecla == Keys::Down)
				player->SetDY(velocidad);
			else if (tecla == Keys::Left)
				player->SetDX(-velocidad);
			else if (tecla == Keys::Right)
				player->SetDX(velocidad);
		}
		else
		{
			if (tecla == Keys::Up)
				player->SetDY(0);
			else if (tecla == Keys::Down)
				player->SetDY(0);
			else if (tecla == Keys::Left)
				player->SetDX(0);
			else if (tecla == Keys::Right)
				player->SetDX(0);
		}
	}
	void Mover(Graphics^ g)
	{
		if(obj_obstaculos->Colision(player->NextArea()) == false)
			player->Mover(g);
		obj_obstaculos->Mover(g);
	}
	void Mostrar(Graphics^ g)
	{
		player->Mostrar(g, imgPlayer);
		obj_obstaculos->Mostrar(g, imgTroll);
	}
};