#include <iostream>
#include <string>

//class Node {
//private:
//	Node *vanem, *vasak, *parem;
//	int vaartus;
//public:
//	// Konstruktorid
//	Node (const Node&);
//	Node (const int&, Node* = nullptr, Node* = nullptr, Node* = nullptr);
//	Node (const int&, Node*, Node*, const int&);
//	Node (const int&, Node*, const int&, Node*);
//	Node (const int&, Node*, const int&, const int&);
//	Node (const int&, Node*, const int&);
//	Node (const int&, const int&, Node*);
//	Node (const int&, const int&, const int&);
//	Node (const int&, Node*);
//	Node (const int&, const int&);
//	Node (const int&);
//	// Set-meetodid
//	void setVanem (Node*);
//	void setVaartus (const int&);
//	// Get-meetodid
//	Node& leiaVanem () const;
//	Node& leiaVasak () const;
//	Node& leiaParem () const;
//	const int& leiaVaartus () const;
//};
//
//
//Node::Node (const Node& node) {
//	this->vaartus = node.leiaVaartus ();
//	this->vanem = &node.leiaVanem ();
//	this->vasak = &node.leiaVasak ();
//	this->parem = &node.leiaParem ();
//}
//
//Node::Node (const int& vaartus, Node* vanem, Node* vasak, Node* parem) {
//	this->vaartus = vaartus;
//	if (vanem != nullptr) {
//		this->vanem = vanem;
//	}
//	if (vasak != nullptr) {
//		this->vasak = vasak;
//		this->vasak->setVanem (this);
//	}
//	if (parem != nullptr) {
//		this->parem = parem;
//		this->parem->setVanem (this);
//	}
//}
//
//Node::Node (const int& vaartus, Node* vanem, Node* vasak, const int& parem) {
//	this->vaartus = vaartus;
//	this->vanem = vanem;
//	this->vasak = vasak;
//	this->parem = new Node (parem&, const_cast<Node*>(this));
//}
//
//Node::Node (const int& vaartus, Node* vanem, const int& vasak, Node* parem) {
//	this->vaartus = vaartus;
//	this->vanem = vanem;
//	this->vasak = new Node (vasak, const_cast<Node*>(this));
//	this->parem = parem;
//}
//
//Node::Node (const int& vaartus, Node* vanem, const int& vasak, const int& parem) {
//	this->vaartus = vaartus;
//	this->vanem = vanem;
//	this->vasak = new Node (vasak, const_cast<Node*>(this));
//	this->parem = new Node (parem, const_cast<Node*>(this));
//}
//
//Node::Node (const int& vaartus, Node* vasak, const int& parem) {
//	this->vaartus = vaartus;
//	this->vasak = vasak;
//	this->parem = new Node (parem, const_cast<Node*>(this));
//}
//
//Node::Node (const int& vaartus, const int& vasak, Node* parem) {
//	this->vaartus = vaartus;
//	this->vasak = new Node (vasak, const_cast<Node*>(this));
//	this->parem = parem;
//}
//
//Node::Node (const int& vaartus, const int& vasak, const int& parem) {
//	this->vaartus = vaartus;
//	this->vasak = new Node (vasak, const_cast<Node*>(this));
//	this->parem = new Node (parem, const_cast<Node*>(this));
//}
//
//Node::Node (const int& vaartus, Node* vanem) {
//	this->vaartus = vaartus;
//	this->vanem = vanem;
//}
//
//Node::Node (const int& vaartus, const int& vasak) {
//	this->vaartus = vaartus;
//	this->vasak = new Node (vasak, const_cast<Node*>(this));
//}
//
//Node::Node (const int& vaartus) {
//	this->vaartus = vaartus;
//}
//
//void Node::setVanem (Node* vanem) {
//	this->vanem = vanem;
//}
//
//void Node::setVaartus (const int& vaartus) {
//	this->vaartus = vaartus;
//}
//
//Node& Node::leiaVanem () const {
//	return *vanem;
//}
//
//Node& Node::leiaVasak () const {
//	return *vasak;
//}
//
//Node& Node::leiaParem () const {
//	return *parem;
//}
//
//const int& Node::leiaVaartus () const {
//	return vaartus;
//}
//
//void valjasta (const Node& kahendpuu) {
//	std::cout << kahendpuu.leiaVaartus () << std::endl;
//	if (&kahendpuu.leiaVasak () != nullptr) {
//		valjasta (kahendpuu.leiaVasak ());
//	}
//	if (&kahendpuu.leiaParem () != nullptr) {
//		valjasta (kahendpuu.leiaParem ());
//	}
//}



int main () {
	//Node kahendpuu (1, new Node (10, 2, 11), new Node (8, new Node (3), 5));
	//valjasta (kahendpuu);
	bla a;
	a.ostr();
	
	bla b("jeeee");
	b.ostr ();

	b.setStr ("jee2");
	b.ostr ();

	std::cin.ignore ();

	return 0;
}