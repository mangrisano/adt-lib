
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/binarytree.hpp"
#include <cmath>

/* ************************************************************************** */

namespace lasd {

	/* ************************************************************************** */

	template <typename Data>
	class BST : virtual public BinaryTreeLnk<Data> { // Must extend BinaryTreeLnk<Data>

		private:

		// ...

		protected:

		using BinaryTreeLnk<Data>::size;
		using BinaryTreeLnk<Data>::root;
		using typename BinaryTreeLnk<Data>::NodeLnk;
		

		// ...

		public:

			// Default constructor
			BST() = default;

			/* ************************************************************************ */

			// Specific constructors
			BST(const LinearContainer<Data>&);

			/* ************************************************************************ */

			// Copy constructor
			BST(const BST&);

			// Move constructor
			BST(BST&&) noexcept;

			/* ************************************************************************ */

			// Destructor
			virtual ~BST() = default;

			/* ************************************************************************ */

			// Copy assignment
			// type operator=(argument) specifiers;
			BST& operator=(const BST&);

			// Move assignment
			// type operator=(argument) specifiers;
			BST& operator=(BST&&) noexcept;

			/* ************************************************************************ */

			// Comparison operators

			bool operator==(const BST&) const noexcept;
			bool operator!=(const BST&) const noexcept;

			/* ************************************************************************ */

			// Specific member functions

			void Insert(const Data&) noexcept; 				// Copy of the value
			void Insert(Data&&) noexcept;	   				// Move of the value
			void Remove(const Data&) noexcept;

			const Data& Min() const;  						// (concrete function must throw std::length_error when not found)
			Data MinNRemove();		  						// (concrete function must throw std::length_error when not found)
			void RemoveMin();		  						// (concrete function must throw std::length_error when not found)

			const Data& Max() const; 						// (concrete function must throw std::length_error when not found)
			Data MaxNRemove();		 						// (concrete function must throw std::length_error when not found)
			void RemoveMax();		 						// (concrete function must throw std::length_error when not found)

			const Data& Predecessor(const Data&) const; 	// (concrete function must throw std::length_error when not found)
			Data PredecessorNRemove(const Data&); 			// (concrete function must throw std::length_error when not found)
			void RemovePredecessor(const Data&); 			// (concrete function must throw std::length_error when not found)

			const Data& Successor(const Data&) const; 		// (concrete function must throw std::length_error when not found)
			Data SuccessorNRemove(const Data&); 			// (concrete function must throw std::length_error when not found)
			void RemoveSuccessor(const Data&); 				// (concrete function must throw std::length_error when not found)

			/* ************************************************************************ */

			// Specific member functions (inherited from TestableContainer)

			bool Exists(const Data&) const noexcept override; // Override TestableContainer member

		protected:

			// Auxiliary member functions


			Data DataNDelete(NodeLnk*) noexcept;
			typename BST<Data>::NodeLnk* Detach(NodeLnk*&) noexcept;

			typename BST<Data>::NodeLnk* DetachMin(NodeLnk*&) noexcept;
			typename BST<Data>::NodeLnk* DetachMax(NodeLnk*&) noexcept;

			typename BST<Data>::NodeLnk* SkipOnLeft(NodeLnk*&) noexcept;
			typename BST<Data>::NodeLnk* SkipOnRight(NodeLnk*&) noexcept;

			typename BST<Data>::NodeLnk*& FindPointerToMin(NodeLnk*&) noexcept;
			typename BST<Data>::NodeLnk* const& FindPointerToMin(NodeLnk* const&) const noexcept;
	
			typename BST<Data>::NodeLnk*& FindPointerToMax(NodeLnk*&) noexcept;
			typename BST<Data>::NodeLnk* const& FindPointerToMax(NodeLnk* const&) const noexcept;

			typename BST<Data>::NodeLnk*& FindPointerTo(NodeLnk*&, const Data&) noexcept;
			typename BST<Data>::NodeLnk* const& FindPointerTo(NodeLnk* const&, const Data&) const noexcept;
			typename BST<Data>::NodeLnk*& FindPointerToPredecessor(NodeLnk*&, const Data&) noexcept;
			typename BST<Data>::NodeLnk* const& FindPointerToPredecessor(NodeLnk* const&, const Data&) const noexcept;
			typename BST<Data>::NodeLnk*& FindPointerToSuccessor(NodeLnk*&, const Data&) noexcept;
			typename BST<Data>::NodeLnk* const& FindPointerToSuccessor(NodeLnk* const&, const Data&) const noexcept;


	};

	/* ************************************************************************** */

}

#include "bst.cpp"

#endif
