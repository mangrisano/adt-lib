#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {
  
	template<typename Data>
  	class Vector: virtual public LinearContainer<Data>,
                  virtual public MappableContainer<Data>,
                  virtual public FoldableContainer<Data> {

		private:

		protected:

			using LinearContainer<Data>::size;
			Data* Elements = nullptr;

		public:

			// Default constructor
			Vector() = default;

			// Specific constructors
			Vector(unsigned long);
			Vector(const LinearContainer<Data>&);

			// Copy constructor
			Vector(const Vector&);

			// Move constructor
			Vector(Vector&&) noexcept;

			// Destructor
			virtual ~Vector();

			// Copy assignment
			Vector& operator=(const Vector&);

			// Move assignment
			Vector& operator=(Vector&&) noexcept;

			// Comparison operators
			bool operator==(const Vector&) const noexcept;
			bool operator!=(const Vector&) const noexcept;

			// Specific member functions
			void Resize(const unsigned long); // Resize the vector to a given size

			// Specific member functions (inherited from Container)
			void Clear() override; // Override Container member

			// Specific member functions (inherited from LinearContainer)

			Data& Front() const override; // Override LinearContainer member (must throw std::length_error when empty)
			Data& Back() const override; // Override LinearContainer member (must throw std::length_error when empty)
			Data& operator[](unsigned long) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

			// Specific member functions (inherited from MappableContainer)
			using typename MappableContainer<Data>::MapFunctor;

			void MapPreOrder(const MapFunctor, void*) override; // Override MappableContainer member
			void MapPostOrder(const MapFunctor, void*) override; // Override MappableContainer member

			// Specific member functions (inherited from FoldableContainer)
			using typename FoldableContainer<Data>::FoldFunctor;

			void FoldPreOrder(const FoldFunctor, const void*, void*) const override; // Override FoldableContainer member
			void FoldPostOrder(const FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

	};

} 

#include "vector.cpp"
#endif
