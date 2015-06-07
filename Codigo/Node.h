#pragma once
#include "Cotxe.h"


class Node
{
public:
	Node ();
	Node(Cotxe cotxe);
	Cotxe& getValor() const;
	Node* getNext();
	void setValor (Cotxe valor);
	void setNext (Node* next);
	~Node ();
private:
	Cotxe m_valor;
	Node* m_next;
};

