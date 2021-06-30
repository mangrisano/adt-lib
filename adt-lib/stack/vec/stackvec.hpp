
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : virtual public Stack<Data>,
                 protected Vector<Data> {

    private:

      	unsigned long top = 0;

    protected:

      	using Vector<Data>::size;
	  	using Vector<Data>::Elements;

    public:

		// Default constructor
		StackVec();

		/* ************************************************************************ */

		// Specific constructor
		StackVec(const LinearContainer<Data>&);

		/* ************************************************************************ */

		// Copy constructor
		StackVec(const StackVec&);

		// Move constructor
		StackVec(StackVec&&) noexcept;

		/* ************************************************************************ */

		// Destructor
		virtual ~StackVec();

		/* ************************************************************************ */

		// Copy assignment
		StackVec& operator=(const StackVec&);

		// Move assignment
		StackVec& operator=(StackVec&&) noexcept;

		/* ************************************************************************ */

		// Comparison operators
		bool operator==(const StackVec&) const noexcept;
		bool operator!=(const StackVec&) const noexcept;

      	/* ************************************************************************ */

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

	  	inline bool Empty() const noexcept override;

		inline unsigned long Size() const noexcept override;

		void Clear() override;

    protected:

		void Expand();
		void Reduce();

    };

    /* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
