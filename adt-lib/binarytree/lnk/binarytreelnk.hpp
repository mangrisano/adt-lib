
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

	template <typename Data>
	class BinaryTreeLnk : virtual public BinaryTree<Data> { // Must extend BinaryTree<Data>

		protected:
			
			using BinaryTree<Data>::size;

			struct NodeLnk : public BinaryTree<Data>::Node { // Must extend Node

				private:

				protected:

				public:

					Data value;
					NodeLnk* left = nullptr;
					NodeLnk* right = nullptr;

					NodeLnk(const Data&);

					virtual ~NodeLnk();

					Data& Element() noexcept override;
					const Data& Element() const noexcept override;
					bool IsLeaf() const noexcept override;
					bool HasLeftChild() const noexcept override;
					bool HasRightChild() const noexcept override;
					NodeLnk& LeftChild() const override;
					NodeLnk& RightChild() const override;

					friend class BinaryTreeLnk<Data>;

			};

			NodeLnk* root = nullptr;

		private:

			void generateBT(unsigned long, BinaryTreeLnk<Data>::NodeLnk*, const LinearContainer<Data>&);
			NodeLnk* copyBT(const BinaryTreeLnk<Data>::NodeLnk*);

		public:

			// Default constructor
			BinaryTreeLnk() = default;

			/* ************************************************************************ */

			// Specific constructors
			BinaryTreeLnk(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer

			/* ************************************************************************ */

			// Copy constructor
			// BinaryTreeLnk(argument) specifiers;
			BinaryTreeLnk(const BinaryTreeLnk&);

			// Move constructor
			// BinaryTreeLnk(argument) specifiers;
			BinaryTreeLnk(BinaryTreeLnk&&) noexcept;

			/* ************************************************************************ */

			// Destructor
			virtual ~BinaryTreeLnk();

			/* ************************************************************************ */

			// Copy assignment
			// type operator=(argument) specifiers;
			BinaryTreeLnk& operator=(const BinaryTreeLnk&);

			// Move assignment
			// type operator=(argument) specifiers;
			BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;

			/* ************************************************************************ */

			// Comparison operators
			// type operator==(argument) specifiers;
			/*bool operator==(const BinaryTreeLnk&) const noexcept;
			// type operator!=(argument) specifiers;
			bool operator!=(const BinaryTreeLnk&) const noexcept;*/

			/* ************************************************************************ */

			// Specific member functions (inherited from BinaryTree)

			// type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
			NodeLnk& Root() const override;

			/* ************************************************************************ */

			// Specific member functions (inherited from Container)

			// type Clear() specifiers; // Override Container member
			void Clear() override;

	};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
