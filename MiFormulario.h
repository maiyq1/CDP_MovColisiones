#pragma once
#include "Juego.h"

namespace MovColis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MiFormulario : public System::Windows::Forms::Form
	{
		Juego^ partida; //en vez de puntero(*) se usa circunflejo(^)
						//porque es una clase referenciada
	public:
		MiFormulario(void)
		{
			InitializeComponent();
			partida = gcnew Juego(); //se añade el gc a una clase referenciada
		}

	protected:
		~MiFormulario()
		{
			if (components)
			{
				delete components;
			}
			delete partida;
		}
	private: System::Windows::Forms::Timer^ clock;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// clock
			// 
			this->clock->Enabled = true;
			this->clock->Interval = 33;
			this->clock->Tick += gcnew System::EventHandler(this, &MiFormulario::clock_Tick);
			// 
			// MiFormulario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(337, 303);
			this->Name = L"MiFormulario";
			this->Text = L"MiFormulario";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MiFormulario::MiFormulario_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MiFormulario::MiFormulario_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	Void clock_Tick(Object^ sender, EventArgs^ e)
	{
		Graphics^ g = this->CreateGraphics();
		g->Clear(Color::White);
		partida->Mover(g);
		partida->Mostrar(g);
	}
	Void MiFormulario_KeyDown(Object^ sender, Windows::Forms::KeyEventArgs^ e)
	{
		partida->MovimientoJugador(true, e->KeyCode);
	}
	Void MiFormulario_KeyUp(Object^ sender, Windows::Forms::KeyEventArgs^ e)
	{
		partida->MovimientoJugador(false, e->KeyCode);
	}
	};
}
