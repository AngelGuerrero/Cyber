#pragma once
#include <string>

class computador
{
public:
	computador();
	// Pasando par�metros
	computador(int id, std::string nombreUsuario, std::string horaInicio, std::string horaFinal);
	~computador();

// Atributos
private:
	static int secuenciaId;	// Variable que enumera el n�mero de secuencia en que se ha estado creando los objetos
	int id;
	std::string nombreUsuario;
	std::string horaInicio;
	std::string horaFinal;

// M�todos de acceso
public:
	int getId();
	std::string getnombreUsuario();
	std::string getHoraInicio();
	std::string getHoraFinal();

// M�todos de modificaci�n
	void setId(int id);
	void setnombreUsuario(std::string nombreUsuario);
	void setHoraInicio(std::string horaInicio);
	void setHoraFinal(std::string horaFinal);
};

