#include "computador.h"



computador::computador()
{
	this->id = 0;
	this->curp = "";
	this->horaInicio = "";
	this->horaFinal = "";
}
// Crear objeto pasando los parámetros
computador::computador(int id, std::string curp, std::string horaInicio, std::string horaFinal)
{
	this->id = id;
	this->curp = curp;
	this->horaInicio = horaInicio;
	this->horaFinal = horaFinal;
}
computador::~computador()
{
}

// Métodos de acceso
int computador::getId()
{
	return this->id;
}

std::string computador::getCurp()
{
	return this->curp;
}

std::string computador::getHoraInicio()
{
	return this->horaInicio;
}

std::string computador::getHoraFinal()
{
	return this->horaFinal;
}

// Métodos de modificación
void computador::setId(int id)
{
	this->id = id;
}

void computador::setCurp(std::string curp)
{
	this->curp = curp;
}

void computador::setHoraInicio(std::string horaInicio)
{
	this->horaInicio = horaInicio;
}

void computador::setHoraFinal(std::string horaFinal)
{
	this->horaFinal = horaFinal;
}
