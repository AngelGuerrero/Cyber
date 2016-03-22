#pragma once
#include <string>

class computador
{
public:
	computador();
	// Pasando parámetros
	computador(int id, std::string curp, std::string horaInicio, std::string horaFinal);
	~computador();

// Atributos
private:
	static int secuenciaId;	// Variable que enumera el número de secuencia en que se ha estado creando los objetos
	int id;
	std::string curp;
	std::string horaInicio;
	std::string horaFinal;

public:
// Métodos de acceso
	int getId();
	std::string getCurp();
	std::string getHoraInicio();
	std::string getHoraFinal();

// Métodos de modificación
	void setId(int id);
	void setCurp(std::string curp);
	void setHoraInicio(std::string horaInicio);
	void setHoraFinal(std::string horaFinal);
};

