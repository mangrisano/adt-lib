
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/lst/stacklst.hpp"
#include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

	template <typename Data>
	class BinaryTree : virtual public InOrderMappableContainer<Data>,
					   virtual public BreadthMappableContainer<Data>,
					   virtual public InOrderFoldableContainer<Data>,
					   virtual public BreadthFoldableContainer<Data> {

		private:

		protected:

			using BreadthMappableContainer<Data>::size;

		public:

			struct Node {

				private:

				protected:

					// type operator==(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.
					// type operator!=(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.
					virtual bool operator==(const Node&) const noexcept;
					virtual bool operator!=(const Node&) const noexcept;

				public:

					friend class BinaryTree<Data>;

					/* ********************************************************************** */

					// Destructor
					virtual ~Node() = default;

					/* ********************************************************************** */

					// Copy assignment
					// type operator=(argument); // Copy assignment of abstract types should not be possible.
					Node& operator=(const Node&) = delete;
					

					// Move assignment
					// type operator=(argument); // Move assignment of abstract types should not be possible.
					Node& operator=(Node&&) = delete;

					/* ********************************************************************** */

					// Specific member functions

					// type Element() specifiers; // Mutable access to the element (concrete function should not throw exceptions)
					// type Element() specifiers; // Immutable access to the element (concrete function should not throw exceptions)
					virtual Data& Element() noexcept = 0;
					virtual const Data& Element() const noexcept = 0;

					// type IsLeaf() specifiers; // (concrete function should not throw exceptions)
					virtual bool IsLeaf() const noexcept = 0;
					// type HasLeftChild() specifiers; // (concrete function should not throw exceptions)
					virtual bool HasLeftChild() const noexcept = 0;
					// type HasRightChild() specifiers; // (concrete function should not throw exceptions)
					virtual bool HasRightChild() const noexcept = 0;

					// type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
					virtual Node& LeftChild() const = 0;
					// type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
					virtual Node& RightChild() const = 0;

			};

			/* ************************************************************************ */

			// Destructor
			virtual ~BinaryTree() = default;

			/* ************************************************************************ */

			// Copy assignment
			// type operator=(argument); // Copy assignment of abstract types should not be possible.
			BinaryTree& operator=(const BinaryTree&) = delete;

			// Move assignment
			// type operator=(argument); // Move assignment of abstract types should not be possible.
			BinaryTree& operator=(BinaryTree&&) noexcept = delete;

			/* ************************************************************************ */

			// Comparison operators
			// type operator==(argument) specifiers; // Comparison of abstract binary tree is possible.
			virtual bool operator==(const BinaryTree&) const noexcept;
			// type operator!=(argument) specifiers; // Comparison of abstract binary tree is possible.
			virtual bool operator!=(const BinaryTree&) const noexcept;

			/* ************************************************************************ */

			// Specific member functions

			// type Root() specifiers; // (concrete function must throw std::length_error when empty)
			virtual Node& Root() const = 0;

			/* ************************************************************************ */

			// Specific member functions (inherited from MappableContainer)

			using typename MappableContainer<Data>::MapFunctor;
			void MapPreOrder(const MapFunctor, void*) override;
			void MapPostOrder(const MapFunctor, void*) override;

			/* ************************************************************************ */

			// Specific member functions (inherited from FoldableContainer)

			using typename FoldableContainer<Data>::FoldFunctor;
			void FoldPreOrder(const FoldFunctor, const void*, void*) const override;
			void FoldPostOrder(const FoldFunctor, const void*, void*) const override;

			/* ************************************************************************ */

			// Specific member functions (inherited from InOrderMappableContainer)
			void MapInOrder(const MapFunctor, void*) override;

			/* ************************************************************************ */

			// Specific member functions (inherited from InOrderFoldableContainer)
			void FoldInOrder(const FoldFunctor, const void*, void*) const override;

			/* ************************************************************************ */

			// Specific member functions (inherited from BreadthMappableContainer)
			void MapBreadth(const MapFunctor, void*) override;

			/* ************************************************************************ */

			// Specific member functions (inherited from BreadthFoldableContainer)
			void FoldBreadth(const FoldFunctor, const void*, void*) const override;

		protected:

			// Auxiliary member functions (for MappableContainer)

			// type MapPreOrder(arguments) specifiers; // Accessory function executing from one node of the tree
			// type MapPostOrder(arguments) specifiers; // Accessory function executing from one node of the tree
			void MapPreOrder(const MapFunctor, void*, Node&);
			void MapPostOrder(const MapFunctor, void*, Node&);

			/* ************************************************************************ */

			// Auxiliary member functions (for FoldableContainer)

			// type FoldPreOrder(arguments) specifiers; // Accessory function executing from one node of the tree
			// type FoldPostOrder(arguments) specifiers; // Accessory function executing from one node of the tree
			void FoldPreOrder(const FoldFunctor, const void*, void*, Node&) const;
			void FoldPostOrder(const FoldFunctor, const void*, void*, Node&) const;

			/* ************************************************************************ */

			// Auxiliary member functions (for InOrderMappableContainer)

			// type MapInOrder(arguments) specifiers; // Accessory function executing from one node of the tree
			void MapInOrder(const MapFunctor, void*, Node&);

			/* ************************************************************************ */

			// Auxiliary member functions (for InOrderFoldableContainer)

			// type FoldInOrder(arguments) specifiers; // Accessory function executing from one node of the tree
			void FoldInOrder(const FoldFunctor, const void*, void*, Node&) const;
			/* ************************************************************************ */

			// Auxiliary member functions (for BreadthMappableContainer)

			// type MapBreadth(arguments) specifiers; // Accessory function executing from one node of the tree
			void MapBreadth(const MapFunctor, void*, Node&);

			/* ************************************************************************ */

			// Auxiliary member functions (for BreadthFoldableContainer)

			// type FoldBreadth(arguments) specifiers; // Accessory function executing from one node of the tree
			void FoldBreadth(const FoldFunctor, const void*, void*, Node&) const;

	};

	/* ************************************************************************** */

	template <typename Data>
	class BTPreOrderIterator : virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

		private:

		protected:

			typename BinaryTree<Data>::Node* curr = nullptr;
			StackLst<struct BinaryTree<Data>::Node*> stacklst;

		public:

			// Specific constructors
			// BTPreOrderIterator(argument) specifiers; // An iterator over a given binary tree
			BTPreOrderIterator(const BinaryTree<Data>&);

			/* ************************************************************************ */

			// Copy constructor
			BTPreOrderIterator(const BTPreOrderIterator&);
			// Move constructor
			BTPreOrderIterator(BTPreOrderIterator&&) noexcept;

			/* ************************************************************************ */

			// Destructor
			virtual ~BTPreOrderIterator() = default;

			/* ************************************************************************ */

			// Copy assignment
			BTPreOrderIterator& operator=(const BTPreOrderIterator&);

			// Move assignment
			BTPreOrderIterator& operator=(BTPreOrderIterator&&) noexcept;


			/* ************************************************************************ */

			// Comparison operators
			bool operator==(const BTPreOrderIterator&) const noexcept;
			bool operator!=(const BTPreOrderIterator&) const noexcept;



		/* ************************************************************************ */

			// Specific member functions (inherited from Iterator)

			// type operator*() specifiers; // (throw std::out_of_range when terminated)
			Data& operator*() const override;

			bool Terminated() const noexcept override;
			/* ************************************************************************ */

			// Specific member functions (inherited from ForwardIterator)

			// type operator++() specifiers; // (throw std::out_of_range when terminated)
			BTPreOrderIterator& operator++() override;

	};

	/* ************************************************************************** */

	template <typename Data>
	class BTPostOrderIterator : virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

		private:

			// ...

		protected:

			typename BinaryTree<Data>::Node* curr = nullptr;
			typename BinaryTree<Data>::Node* last = nullptr;
			StackLst<struct BinaryTree<Data>::Node*> stacklst;
			void findLeftMostLeaf();


		public:

			// Specific constructors
			// BTPreOrderIterator(argument) specifiers; // An iterator over a given binary tree
			BTPostOrderIterator(const BinaryTree<Data>&);

			/* ************************************************************************ */

			// Copy constructor
			BTPostOrderIterator(const BTPostOrderIterator&);
			// Move constructor
			BTPostOrderIterator(BTPostOrderIterator&&) noexcept;

			/* ************************************************************************ */

			// Destructor
			virtual ~BTPostOrderIterator() = default;

			/* ************************************************************************ */

			// Copy assignment
			BTPostOrderIterator& operator=(const BTPostOrderIterator&);

			// Move assignment
			BTPostOrderIterator& operator=(BTPostOrderIterator&&) noexcept;


			/* ************************************************************************ */

			// Comparison operators
			bool operator==(const BTPostOrderIterator&) const noexcept;
			bool operator!=(const BTPostOrderIterator&) const noexcept;



		/* ************************************************************************ */

			// Specific member functions (inherited from Iterator)

			// type operator*() specifiers; // (throw std::out_of_range when terminated)
			Data& operator*() const override;

			bool Terminated() const noexcept override;
			/* ************************************************************************ */

			// Specific member functions (inherited from ForwardIterator)

			// type operator++() specifiers; // (throw std::out_of_range when terminated)
			BTPostOrderIterator& operator++() override;

		};

	/* ************************************************************************** */

	template <typename Data>
	class BTInOrderIterator : virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

		private:

			// ...

		protected:

			typename BinaryTree<Data>::Node* curr = nullptr;
			StackLst<struct BinaryTree<Data>::Node*> stacklst;
			typename BinaryTree<Data>::Node& findMostLeftChild(typename BinaryTree<Data>::Node&);

		public:

			// Specific constructors
			// BTPreOrderIterator(argument) specifiers; // An iterator over a given binary tree
			BTInOrderIterator(const BinaryTree<Data>&);

			/* ************************************************************************ */

			// Copy constructor
			BTInOrderIterator(const BTInOrderIterator&);
			// Move constructor
			BTInOrderIterator(BTInOrderIterator&&) noexcept;

			/* ************************************************************************ */

			// Destructor
			virtual ~BTInOrderIterator() = default;

			/* ************************************************************************ */

			// Copy assignment
			BTInOrderIterator& operator=(const BTInOrderIterator&);

			// Move assignment
			BTInOrderIterator& operator=(BTInOrderIterator&&) noexcept;


			/* ************************************************************************ */

			// Comparison operators
			bool operator==(const BTInOrderIterator&) const noexcept;
			bool operator!=(const BTInOrderIterator&) const noexcept;



		/* ************************************************************************ */

			// Specific member functions (inherited from Iterator)

			// type operator*() specifiers; // (throw std::out_of_range when terminated)
			Data& operator*() const override;

			bool Terminated() const noexcept override;
			/* ************************************************************************ */

			// Specific member functions (inherited from ForwardIterator)

			// type operator++() specifiers; // (throw std::out_of_range when terminated)
			BTInOrderIterator& operator++() override;

	};

	/* ************************************************************************** */

	template <typename Data>
	class BTBreadthIterator : virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

		private:

			// ...

		protected:

			typename BinaryTree<Data>::Node* curr;
			QueueLst<struct BinaryTree<Data>::Node*> queuelst;

		public:

			// Specific constructors
			// BTPreOrderIterator(argument) specifiers; // An iterator over a given binary tree
			BTBreadthIterator(const BinaryTree<Data>&);

			/* ************************************************************************ */

			// Copy constructor
			BTBreadthIterator(const BTBreadthIterator&);
			// Move constructor
			BTBreadthIterator(BTBreadthIterator&&) noexcept;

			/* ************************************************************************ */

			// Destructor
			virtual ~BTBreadthIterator() = default;

			/* ************************************************************************ */

			// Copy assignment
			BTBreadthIterator& operator=(const BTBreadthIterator&);

			// Move assignment
			BTBreadthIterator& operator=(BTBreadthIterator&&) noexcept;


			/* ************************************************************************ */

			// Comparison operators
			bool operator==(const BTBreadthIterator&) const noexcept;
			bool operator!=(const BTBreadthIterator&) const noexcept;



		/* ************************************************************************ */

			// Specific member functions (inherited from Iterator)

			// type operator*() specifiers; // (throw std::out_of_range when terminated)
			Data& operator*() const override;

			bool Terminated() const noexcept override;
			/* ************************************************************************ */

			// Specific member functions (inherited from ForwardIterator)

			// type operator++() specifiers; // (throw std::out_of_range when terminated)
			BTBreadthIterator& operator++() override;

	};

	/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
