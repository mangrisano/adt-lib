
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

	template <typename Data>
	class BinaryTreeVec : virtual public BinaryTree<Data> { // Must extend BinaryTree<Data>

		private:

		protected:

			using BinaryTree<Data>::size;

			struct NodeVec : public BinaryTree<Data>::Node { // Must extend Node

				private:

				protected:

					Data value;
					Vector<NodeVec*> *nodeVec;
					unsigned long index;

				public:

					NodeVec();
					NodeVec(const Data&, unsigned long, Vector<NodeVec*>*);

					Data& Element() noexcept override;
					const Data& Element() const noexcept override;
					bool IsLeaf() const noexcept override;
					bool HasLeftChild() const noexcept override;
					bool HasRightChild() const noexcept override;
					NodeVec& LeftChild() const override;
					NodeVec& RightChild() const override;

					friend class BinaryTreeVec<Data>;

			};

		Vector<NodeVec*> treevec;

		public:

			// Default constructor
			// BinaryTreeVec() specifiers;
			BinaryTreeVec() = default;

			/* ************************************************************************ */

			// Specific constructors
			// BinaryTreeVec(argument) specifiers; // A binary tree obtained from a LinearContainer
			BinaryTreeVec(const LinearContainer<Data>&);

			/* ************************************************************************ */

			// Copy constructor
			// BinaryTreeVec(argument) specifiers;
			BinaryTreeVec(const BinaryTreeVec&);

			// Move constructor
			// BinaryTreeVec(argument) specifiers;
			BinaryTreeVec(BinaryTreeVec&&) noexcept;

			/* ************************************************************************ */

			// Destructor
			virtual ~BinaryTreeVec();

			/* ************************************************************************ */

			// Copy assignment
			// type operator=(argument) specifiers;
			BinaryTreeVec& operator=(const BinaryTreeVec&);

			// Move assignment
			// type operator=(argument) specifiers;
			BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept;

			/* ************************************************************************ */

			// Comparison operators
			// type operator==(argument) specifiers;
			/*bool operator==(const BinaryTreeVec&) const noexcept;
			// type operator!=(argument) specifiers;
			bool operator!=(const BinaryTreeVec&) const noexcept;*/

			/* ************************************************************************ */

			// Specific member functions (inherited from BinaryTree)

			// type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
			NodeVec& Root() const override;

			/* ************************************************************************ */

			// Specific member functions (inherited from Container)

			// type Clear() specifiers; // Override Container member
			void Clear() override;

			using typename MappableContainer<Data>::MapFunctor; 
			void MapBreadth(const MapFunctor, void*) override;

			using typename FoldableContainer<Data>::FoldFunctor;
			void FoldBreadth(const FoldFunctor, const void*, void*) const override;

	};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
