#pragma once
#include "Node.h"
#include "Cotxe.h"

class Iterador
{
private:
	Node* m_posicio;

public:
	Iterador();
	Iterador (Node* posicio);
	void seguent();
	Cotxe& getElement() const;
	void setElement(Cotxe cotxe);
	bool esNul() const;
	~Iterador();



};

