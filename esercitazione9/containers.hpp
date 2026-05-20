#pragma once
#include <queue>
#include <stack>

// cont FIFO 
template <typename T>
class fifo {
private:
	std::queue<T> m_queue; // cont STL

public:
	fifo() = default;

	void put(const T& element) {
		m_queue.push(element);
	}

	T get() {
		T element = m_queue.front(); // primo elt
		m_queue.pop();               // remove
		return element;
	}

	bool empty() const {
		return m_queue.empty();
	}
};

// contenitore LIFO 
template <typename T>
class lifo {
private:
	std::stack<T> m_stack; //cont STL

public:
	lifo() = default;

	void put(const T& element) {
		m_stack.push(element);
	}

	T get() {
		T element = m_stack.top(); // ultimo elt inserito
		m_stack.pop();             // remove
		return element;
	}

	bool empty() const {
		return m_stack.empty();
	}
};