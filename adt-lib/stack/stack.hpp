
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

	/* ************************************************************************** */

	template <typename Data>
	class Stack : virtual public Container {

		private:

		protected:

		public:

			// Destructor
			virtual ~Stack() = default;

	/* ************************************************************************ */

			// Copy assignment
			// type operator=(argument); // Copy assignment of abstract types should not be possible.
			Stack& operator=(const Stack&) = delete;
	

			// Move assignment
			// type operator=(argument); // Move assignment of abstract types should not be possible.
			Stack& operator=(Stack&&) noexcept = delete;

			/* ************************************************************************ */

			// Comparison operators
			// type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
			bool operator==(const Stack&) const noexcept = delete;
			// type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
			bool operator!=(const Stack&) const noexcept = delete;

			/* ************************************************************************ */

			// Specific member functions

			// type Push(argument) specifiers; // Copy of the value
			virtual void Push(const Data&) = 0;
			// type Push(argument) specifiers; // Move of the value
			virtual void Push(Data&&) noexcept = 0;
			// type Top() specifiers; // (concrete function must throw std::length_error when empty)
			virtual Data& Top() const = 0;
			// type Pop() specifiers; // (concrete function must throw std::length_error when empty)
			virtual void Pop() = 0;
			// type TopNPop() specifiers; // (concrete function must throw std::length_error when empty)
			virtual Data TopNPop() = 0;

	};

/* ************************************************************************** */

}

#endif
