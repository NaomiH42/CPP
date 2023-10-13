#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){};
		~MutantStack(){};
		MutantStack(const MutantStack& o) : std::stack<T>(o)
		{
			*this = o;
		};

		MutantStack &operator=(const MutantStack& o)
		{
			(void)o;
			return *this;
		};

		void	push(T val){this->std::stack<T>::push(val);};
		T&		top(){return(this->std::stack<T>::top());};
		void	pop(){this->std::stack<T>::pop();};
		int 	size()
		{
			MutantStack<T> cpy(*this);
			int i = 0;
			while (cpy.std::stack<T>::empty() == false)
			{
				cpy.pop();
				i++;
			}
			return (i);
		};

		class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
		{
			public:
				iterator() : _ptr(NULL){};
				~iterator(){};
				iterator(T* ptr): _ptr(ptr){};
				iterator(const iterator& o) : _ptr(o._ptr){};
				iterator& operator=(const iterator& o)
				{
					if (this != &o)
						_ptr = o._ptr;
					return (*this);
				}
				iterator operator++(){_ptr++; return *this;};
				iterator operator--(){_ptr--; return *this;};
				bool operator!=(iterator &rhs){return (_ptr != rhs._ptr);};
				T& operator*(){return *_ptr;};

			private:
				T* _ptr;
		};

		iterator begin()
		{
			iterator it(&this->top() - this->size() + 1);
			return (it);
		};
		iterator end()
		{
			iterator it(&this->top() + 1);
			return (it);
		};



};

#endif
