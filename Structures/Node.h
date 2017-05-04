#pragma once

template<class T>
struct Node
{
	T data;
	Node<T>* link;
};