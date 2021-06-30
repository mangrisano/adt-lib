
#ifndef MATRIXVEC_HPP
#define MATRIXVEC_HPP

/* ************************************************************************** */

#include "../matrix.hpp"

#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

	template <typename Data>
	class MatrixVec : virtual public Matrix<Data>,
					  virtual protected Vector<Data> { // Must extend Matrix<Data>

		private:

			// ...

		protected:

			using Matrix<Data>::row;
			using Matrix<Data>::col;
			using Vector<Data>::size;
			using Vector<Data>::Elements;

		public:

			using Vector<Data>::MapPreOrder;
			using Vector<Data>::MapPostOrder;
			using Vector<Data>::FoldPreOrder;
			using Vector<Data>::FoldPostOrder;

			// Default constructor
			MatrixVec() = default;;

			/* ************************************************************************ */

			// Specific constructors
			MatrixVec(unsigned long, unsigned long); // A matrix of some specified dimension

			/* ************************************************************************ */

			// Copy constructor
			MatrixVec(const MatrixVec&);

			// Move constructor
			MatrixVec(MatrixVec&&) noexcept;

			/* ************************************************************************ */

			// Destructor
			virtual ~MatrixVec();

			/* ************************************************************************ */

			// Copy assignment
			MatrixVec& operator=(const MatrixVec&);

			// Move assignment
			MatrixVec& operator=(MatrixVec&&) noexcept;

			/* ************************************************************************ */

			// Comparison operators
			bool operator==(const MatrixVec&) const noexcept;
			bool operator!=(const MatrixVec&) const noexcept;

			/* ************************************************************************ */

			// Specific member functions (inherited from Matrix)

			void RowResize(const unsigned long) noexcept override; 	 // Override Matrix member
			void ColumnResize(const unsigned long) noexcept override; // Override Matrix member

			bool ExistsCell(const unsigned long, const unsigned long) const noexcept override; // Override Matrix member (should not throw exceptions)

			Data& operator()(const unsigned long, const unsigned long) override; // Override Matrix member (mutable access to the element; throw out_of_range when out of range)

			const Data& operator()(const unsigned long, const unsigned long) const override; // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)

			/* ************************************************************************ */

			// Specific member functions (inherited from Container)

			void Clear() override; // Override Container member

			/* ************************************************************************ */

			// Specific member functions (inherited from MappableContainer)

			// type MapPreOrder(arguments) specifiers; // Override MappableContainer member
			// type MapPostOrder(arguments) specifiers; // Override MappableContainer member

			/* ************************************************************************ */

			// Specific member functions (inherited from FoldableContainer)

			// type FoldPreOrder(arguments) specifiers; // Override FoldableContainer member
			// type FoldPostOrder(arguments) specifiers; // Override FoldableContainer member

	};

/* ************************************************************************** */

}

#include "matrixvec.cpp"

#endif
