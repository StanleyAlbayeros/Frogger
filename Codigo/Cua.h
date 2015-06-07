#pragma once
#include "Iterador.h"

class Cua
{
private:
	Node* m_primer;
	Node* m_ultim;
public:
	Cua();
	~Cua();
	bool afegeix(Cotxe valor);
	Cotxe treu();
	Cotxe& getPrimer() const;
	Cotxe& getUltim() const;
	bool esBuida() const;
	Iterador getInici() const;
};

