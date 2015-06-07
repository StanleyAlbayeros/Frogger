#include "Cua.h"

Cua::Cua()
{
	m_primer = NULL;
	m_ultim = NULL;
	m_elements = 0;
}

bool Cua::esBuida() const
{
	bool esBuida = false;
	if (m_primer == NULL)
	{
		esBuida = true;
	}
	return esBuida;
}

Cotxe& Cua::getPrimer() const
{
	Cotxe tmp;
	tmp = m_primer->getValor();
	return tmp;
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
	m_elements = m_elements+1;
	return correcte;
}

int Cua::numElements()
{
	return m_elements;
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
	m_elements = m_elements -1;

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