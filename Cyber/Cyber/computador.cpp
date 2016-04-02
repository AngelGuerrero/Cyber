#include "computador.h"



computador::computador()
{
	this->id = 0;
	this->nombreUsuario = "";
	this->horaInicio = "";
	this->horaFinal = "";
	
}
// Crear objeto pasando los parámetros
computador::computador(int id, std::string nombreUsuario, std::string horaInicio, std::string horaFinal)
{
	this->id = id;
	this->nombreUsuario = nombreUsuario;
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

std::string computador::getnombreUsuario()
{
	return this->nombreUsuario;
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

void computador::setnombreUsuario(std::string nombreUsuario)
{
	this->nombreUsuario = nombreUsuario;
}

void computador::setHoraInicio(std::string horaInicio)
{
	this->horaInicio = horaInicio;
}

void computador::setHoraFinal(std::string horaFinal)
{
	this->horaFinal = horaFinal;
}
