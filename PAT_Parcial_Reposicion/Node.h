#pragma once
template<typename T>
struct Node
{
	T value;
	Node* next;

	Node() : value(T()), next(nullptr) {}
	Node(T val) : value(val), next(nullptr) {}
};

