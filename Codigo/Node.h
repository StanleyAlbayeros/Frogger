#include "Codigo\Cotxe.h"


class Node
{
public:
	Cotxe& getValor();
	Node(void);
	Node* getNext();
	void setValor (<tipus_cua> valor);
	void setNext (Node* next);
	~Node(void);
private:
	<tipus_cua> m_valor;
	Node* m_next;
};

