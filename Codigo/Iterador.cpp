#include "Iterador.h"


Iterador::Iterador()
{
	m_posicio = NULL;
}

Iterador::Iterador(Node* posicio)
{
	m_posicio = posicio;
}

void Iterador::seguent()
{
	m_posicio = m_posicio->getNext();
}

Cotxe& Iterador::getElement() const
{
	return m_posicio->getValor();
}


void Iterador::setElement(Cotxe cotxe)
{
	m_posicio->setValor(cotxe);
}

bool Iterador::esNul() const
{
	return m_posicio == NULL;
}


Iterador::~Iterador()
{
}
