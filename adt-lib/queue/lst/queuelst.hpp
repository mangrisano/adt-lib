#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

	template <typename Data>
	class QueueLst: virtual public Queue<Data>,
					protected List<Data> {
		private:

		protected:

		public:

			// Default constructor
			QueueLst() = default;

			/* ************************************************************************ */

			// Specific constructor
			QueueLst(const LinearContainer<Data>&); // A queue obtained from a LinearContainer

			/* ************************************************************************ */

			// Copy constructor
			QueueLst(const QueueLst&);

			// Move constructor
			QueueLst(QueueLst&&) noexcept;

			/* ************************************************************************ */

			// Destructor
			virtual ~QueueLst();

			/* ************************************************************************ */

			// Copy assignment
			// type operator=(argument);
			QueueLst& operator=(const QueueLst&);

			// Move assignment
			// type operator=(argument);
			QueueLst& operator=(QueueLst&&) noexcept;

			/* ************************************************************************ */

			// Comparison operators
			bool operator==(const QueueLst&) const noexcept;
			bool operator!=(const QueueLst&) const noexcept;

			/* ************************************************************************ */

			// Specific member functions (inherited from Queue)

			// type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
			void Enqueue(const Data&) override;
			// type Enqueue(argument) specifiers; // Override Queue member (move of the value)
			void Enqueue(Data&&) override;
			// type Head() specifiers; // Override Queue member (must throw std::length_error when empty)
			Data& Head() const override;
			// type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
			void Dequeue() override;
			// type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
			Data HeadNDequeue() override;

			/* ************************************************************************ */

			// Specific member functions (inherited from Container)

			// type Clear() specifiers; // Override Container member
			void Clear() override;

	};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
