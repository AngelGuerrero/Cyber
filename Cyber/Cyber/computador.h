#pragma once
#include <string>

class computador
{
public:
	computador();
	// Pasando parámetros
	computador(int id, std::string nombreUsuario, std::string horaInicio, std::string horaFinal);
	~computador();

// Atributos
private:
	static int secuenciaId;	// Variable que enumera el número de secuencia en que se ha estado creando los objetos
	int id;
	std::string nombreUsuario;
	std::string horaInicio;
	std::string horaFinal;

// Métodos de acceso
public:
	int getId();
	std::string getnombreUsuario();
	std::string getHoraInicio();
	std::string getHoraFinal();

// Métodos de modificación
	void setId(int id);
	void setnombreUsuario(std::string nombreUsuario);
	void setHoraInicio(std::string horaInicio);
	void setHoraFinal(std::string horaFinal);
};

