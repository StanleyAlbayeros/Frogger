#include "Node.h"

Node::Node()
{
	m_next = NULL;
}

Node::~Node()
{
	m_next = NULL;
}

Node::Node(Cotxe cotxe)
{
	m_valor = cotxe;
	m_next = NULL;
}

Cotxe& Node::getValor() const
{
	Cotxe temp;
	temp = m_valor;

	return temp;
}

Node* Node::getNext()
{
	return m_next;
}

void Node::setValor(Cotxe valor)
{
	m_valor=valor;
}

void Node::setNext(Node* next)
{
	m_next = next;
}
