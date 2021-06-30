
#ifndef MATRIX_HPP
#define MATRIX_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

	template <typename Data>
	class Matrix : virtual public MappableContainer<Data>,
				   virtual public FoldableContainer<Data> {

		private:

		protected:

			unsigned long row = 0;
			unsigned long col = 0;

		public:

		// Destructor
		virtual ~Matrix() = default;

		/* ************************************************************************ */

		// Copy assignment
		// type operator=(argument); // Copy assignment of abstract types should not be possible.
		Matrix& operator=(const Matrix&) = delete;

		// Move assignment
		// type operator=(argument); // Move assignment of abstract types should not be possible.
		Matrix& operator=(Matrix&&) noexcept = delete;

		/* ************************************************************************ */

		// Comparison operators
		// type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
		// type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

		bool operator==(const Matrix&) const noexcept = delete;
		bool operator!=(const Matrix&) const noexcept = delete;


		/* ************************************************************************ */

		// Specific member functions

		// type RowNumber() specifiers; // (concrete function should not throw exceptions)
		// type ColumnNumber() specifiers; // (concrete function should not throw exceptions)

		inline unsigned long RowNumber() const noexcept 
		{ 
			return row; 
		}

		inline unsigned long ColumnNumber() const noexcept
		{
			return col;
		}

		// type RowResize() specifiers;
		virtual void RowResize(const unsigned long) noexcept = 0;
		// type ColumnResize() specifiers;
		virtual void ColumnResize(const unsigned long) noexcept = 0;

		// type ExistsCell() specifiers; // (concrete function should not throw exceptions)
		virtual bool ExistsCell(const unsigned long, const unsigned long) const noexcept = 0;

		// type operator()() specifiers; // Mutable access to the element (concrete function should throw exceptions only when out of range)
		virtual Data& operator()(const unsigned long, const unsigned long) = 0;

		// type operator()() specifiers; // Immutable access to the element (concrete function should throw exceptions when not present)
		virtual const Data& operator()(const unsigned long, const unsigned long) const = 0;


	};

/* ************************************************************************** */

}

#include "matrix.cpp"

#endif
