
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

	template<typename Data>
	class List : virtual public LinearContainer<Data>,
				 virtual public MappableContainer<Data>,
				 virtual public FoldableContainer<Data> {

		private:

			// ...

		protected:

			using LinearContainer<Data>::size;

			struct Node
			{
				Data element;
				struct Node *next;

				Node() = default;

				// Specific constructors
				Node(Data element);

				// Copy constructor
				Node(const Node&);

				// Move constructor
				Node(Node&&) noexcept;

				// Destructor
				virtual ~Node();

				// Comparison operators
				bool operator==(const struct Node*&) const noexcept;
				bool operator!=(const struct Node*&) const noexcept;

				// Specific member functions

			};

		public:

			struct Node *head = nullptr;
			struct Node *tail = nullptr;

			// Default constructor
			List();

			// Specific constructor
			List(const LinearContainer<Data>&);

			// Copy constructor
			List(const List&);

			// Move constructor
			List(List&&) noexcept;

			// Destructor
			virtual ~List();

			// Copy assignment
			List& operator=(const List&);

			// Move assignment
			List& operator=(List&&) noexcept;

			// Comparison operators
			bool operator==(const List&) const noexcept;
			inline bool operator!=(const List&) const noexcept;

			// Specific member functions

			// type InsertAtFront(argument) specifier; // Copy of the value
			void InsertAtFront(const Data&);

			// type InsertAtFront(argument) specifier; // Move of the value
			void InsertAtFront(Data&&);

			// type RemoveFromFront() specifier; // (must throw std::length_error when empty)
			void RemoveFromFront();

			// type FrontNRemove() specifier; // (must throw std::length_error when empty)
			Data FrontNRemove();

			// type InsertAtBack(argument) specifier; // Copy of the value
			void InsertAtBack(const Data&);

			// type InsertAtBack(argument) specifier; // Move of the value
			void InsertAtBack(Data&&);

			// Specific member functions (inherited from Container)

			void Clear() override; // Override Container member

			// Specific member functions (inherited from LinearContainer)

			Data& Front() const override; // Override LinearContainer member (must throw std::length_error when empty)
			Data& Back() const override; // Override LinearContainer member (must throw std::length_error when empty)
			Data& operator[](const unsigned long) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

			// Specific member functions (inherited from MappableContainer)

			using typename MappableContainer<Data>::MapFunctor;

			void MapPreOrder(const MapFunctor, void*) override; // Override MappableContainer member
			void MapPostOrder(const MapFunctor, void*) override; // Override MappableContainer member

			// Specific member functions (inherited from FoldableContainer)

			using typename FoldableContainer<Data>::FoldFunctor;

			void FoldPreOrder(const FoldFunctor, const void*, void*) const override; // Override FoldableContainer member
			void FoldPostOrder(const FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

		protected:

			//using typename MappableContainer<Data>::MapFunctor;

			void MapPreOrder(const MapFunctor, void*, struct Node*);
			void MapPostOrder(const MapFunctor, void*, struct Node*);


			//using typename FoldableContainer<Data>::FoldFunctor;

			void FoldPreOrder(const FoldFunctor, const void*, void*, struct Node*) const;
			void FoldPostOrder(const FoldFunctor, const void*, void*, struct Node*) const;

	};

}

#include "list.cpp"

#endif
