#include "node.hpp"

Node::Node(int val, Node* next) {
	m_val = val;
	m_next = next;
}

int Node::getVal() {
	return m_val;
}

Node* Node::getNext() {
  return m_next;
}

void Node::setNext(Node* next) {
  m_next = next;
}
