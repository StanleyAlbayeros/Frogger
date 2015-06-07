#pragma once
#include "Iterador.h"

class Cua
{
private:
	Node* m_primer;
	Node* m_ultim;
	int m_elements;

public:
	Cua();
	~Cua();
	bool afegeix(Cotxe valor);
	Cotxe treu();
	Cotxe& getPrimer() const;
	Cotxe& getUltim() const;
	int numElements();
	bool esBuida() const;
	Iterador getInici() const;
};

