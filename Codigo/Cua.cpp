#include "Cua.h"

Cua::Cua()
{
	m_primer = NULL;
	m_ultim = NULL;
}

bool Cua::esBuida() const
{
	return m_primer == NULL;
}

Cotxe& Cua::getPrimer() const
{
	return m_primer->getValor();
}

Cotxe& Cua::getUltim() const
{
	return m_ultim->getValor();
}

bool Cua::afegeix(Cotxe valor)
{
	Node* aux;
	aux = new Node;
	bool correcte = false;
	if (aux != NULL)
		{
			correcte = true;
			aux->setValor(valor);
			aux->setNext(NULL);
			
			if (esBuida())
				{
					m_primer = aux;
				}
			
			else
				{
					m_ultim->setNext(aux);
				}
			m_ultim = aux;
		}
	return correcte;
}

Cotxe Cua::treu()
{
	Node* aux;
	Cotxe valor;

	aux = m_primer;

	if (m_primer == m_ultim)
		{
			m_ultim = NULL;
		}
	valor = aux->getValor();

	m_primer = aux->getNext();

	delete aux;

	return valor;
}

Iterador Cua::getInici() const
{
	return Iterador(m_primer);
}


Cua::~Cua()
{
	while (!esBuida())
		{
			treu();
		}
}