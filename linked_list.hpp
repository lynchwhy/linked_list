/*
* LinkedList.hpp
* Written by : Jo Lynch (c3200655)
* Modified   : 27/08/23 
*
* This class represents the template implementation for a LinkedList class.
* This file should be used in conjunction with Assignment 1 for SENG1120.
*/ 

template <typename T>
LinkedList<T>::LinkedList() 
{
	head = new Node<T>();
	tail = new Node<T>();
	
	head->set_next(tail);
    head->set_prev(tail);
	
	tail->set_next(head);
	tail->set_prev(head);
    
	current = head;
    count = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	clear();
	delete head;
	delete tail;
}

template <typename T>
void LinkedList<T>::push_front(const T& data) 
{
	current = head->get_next();
	insert(data);
}

template <typename T>
void LinkedList<T>::push_back(const T& data) 
{
	current = tail;
	insert(data);
}

template <typename T>
void LinkedList<T>::insert(const T& data) 
{
	// The supplied data is inserted just before the node pointed to by the current.
	// create new node
	// new node points to the next node
	// new node points to the previous node
	// next node points to the new node
	// previous node points to the new node
	Node<T>* newNode = new Node<T>(data);
	newNode->set_next(current);
    newNode->set_prev(current->get_prev());
    current->set_prev(newNode);
    newNode->get_prev()->set_next(newNode);
    current = newNode;
    count++;
}

template <typename T>
T LinkedList<T>::pop_front()
{
	current = head->get_next();
	return remove();
}

template <typename T>
T LinkedList<T>::pop_back()
{
	current = tail->get_prev();
	return remove();
}

template <typename T>
T LinkedList<T>::remove()
{
	if (empty() || current == head || current == tail) {
        throw std::runtime_error("Cannot remove from an empty list or from a sentinel node.");
    }

	Node<T>* nodeToRemove = current; // Store the node to remove in a temporary variable
    
    current->get_prev()->set_next(current->get_next());
    current->get_next()->set_prev(current->get_prev());

    current = head; // Reset current to head
    T data = nodeToRemove->get_data();
    delete nodeToRemove; // Delete the removed node
    count--;

    return data;
}

template <typename T>
void LinkedList<T>::clear()
{
	while (head->get_next() != tail) 
	{
		pop_front();
	}
	current = head;
	count = 0;
	
}

template <typename T>
T& LinkedList<T>::front() const
{
	if (empty()) 
	{
		throw std::runtime_error("List is empty.");
	}
	return head->get_next()->get_data();
}

template <typename T>
T& LinkedList<T>::back() const
{
	if (empty()) 
	{
		throw std::runtime_error("List is empty.");
	}
	return tail->get_prev()->get_data();
}

template <typename T>
T& LinkedList<T>::get_current() const
{
	if(empty() || current == head || current == tail) 
	{
		throw std::runtime_error("List is empty or current is pointing to a sentinel node.");
	}
	return current->get_data();
}

template <typename T>
void LinkedList<T>::begin() 
{
    current = head->get_next();
}

template <typename T>
void LinkedList<T>::end() 
{
    current = tail->get_prev();
}

template <typename T>
void LinkedList<T>::forward() 
{
	if(current->get_next() != tail)
	{
		current = current->get_next();
	}
}

template <typename T>
void LinkedList<T>::backward() 
{
	if(current->get_prev() != head)
	{
		current = current->get_prev();
	}
}

template <typename T>
int LinkedList<T>::size() const
{
	return count;
}

template <typename T>
bool LinkedList<T>::empty() const
{
	return count == 0;
}

template <typename T>
bool LinkedList<T>::search(const T& target)
{
	begin(); // Set current to the first node
	for (int i = 0; i < size(); i++) // Loop through the list
	{
		if (get_current() == target) // If the current node is the target
		{
			return true;
		}
		forward(); // Move to the next node
	}
	return false;
}


