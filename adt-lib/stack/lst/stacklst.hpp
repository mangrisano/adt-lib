
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

	template <typename Data>
	class StackLst : virtual public Stack<Data>, 
					 protected List<Data> {
		private:

		protected:
			
		public:

			// Default constructor
			StackLst() = default;

			/* ************************************************************************ */

			// Specific constructor
			StackLst(const LinearContainer<Data>&); // A stack obtained from a LinearContainer

			/* ************************************************************************ */

			// Copy constructor
			StackLst(const StackLst&);

			// Move constructor
			StackLst(StackLst&&) noexcept;

			/* ************************************************************************ */

			// Destructor
			virtual ~StackLst();

			/* ************************************************************************ */

			// Copy assignment
			StackLst& operator=(const StackLst&);

			// Move assignment
			StackLst& operator=(StackLst&&) noexcept;

			/* ************************************************************************ */

			// Comparison operators
			// type operator==(argument) specifiers;
			bool operator==(const StackLst&) const noexcept;
			bool operator!=(const StackLst&) const noexcept;

			/* ************************************************************************ */

			// Specific member functions (inherited from Stack)

			// type Push(argument) specifiers; // Override Stack member (copy of the value)
			void Push(const Data&) override;
			// type Push(argument) specifiers; // Override Stack member (move of the value)
			void Push(Data&&) noexcept override;
			// type Top() specifiers; // Override Stack member (must throw std::length_error when empty)
			Data& Top() const override;
			// type Pop() specifiers; // Override Stack member (must throw std::length_error when empty)
			void Pop() override;
			// type TopNPop() specifiers; // Override Stack member (must throw std::length_error when empty)
			Data TopNPop() override;

			/* ************************************************************************ */

			// Specific member functions (inherited from Container)

			// type Clear() specifiers; // Override Container member
			void Clear() override;

	};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
