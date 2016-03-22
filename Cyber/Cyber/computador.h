#pragma once
#include <string>

class computador
{
public:
	computador();
	// Pasando par�metros
	computador(int id, std::string curp, std::string horaInicio, std::string horaFinal);
	~computador();

// Atributos
private:
	static int secuenciaId;	// Variable que enumera el n�mero de secuencia en que se ha estado creando los objetos
	int id;
	std::string curp;
	std::string horaInicio;
	std::string horaFinal;

public:
// M�todos de acceso
	int getId();
	std::string getCurp();
	std::string getHoraInicio();
	std::string getHoraFinal();

// M�todos de modificaci�n
	void setId(int id);
	void setCurp(std::string curp);
	void setHoraInicio(std::string horaInicio);
	void setHoraFinal(std::string horaFinal);
};

