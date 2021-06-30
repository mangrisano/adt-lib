
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template <typename Data>
    class QueueVec : virtual public Queue<Data>,
                     protected Vector<Data> {

    private:

		long front = 0;
		long rear = 0;

    protected:

		using Vector<Data>::size;
	    using Vector<Data>::Elements;

    public:

      	// Default constructor
    	QueueVec();

      /* ************************************************************************ */

		// Specific constructor
		// QueueVec(argument) specifiers; // A queue obtained from a LinearContainer
		QueueVec(const LinearContainer<Data>&);

		/* ************************************************************************ */

		// Copy constructor
		QueueVec(const QueueVec&);

		// Move constructor
		QueueVec(QueueVec&&) noexcept;

		/* ************************************************************************ */

		// Destructor
		virtual ~QueueVec();

      /* ************************************************************************ */

		// Copy assignment
		QueueVec& operator=(const QueueVec&);

		// Move assignment
		QueueVec& operator=(QueueVec&&) noexcept;

		/* ************************************************************************ */

		// Comparison operators
		bool operator==(const QueueVec&) const noexcept;
		bool operator!=(const QueueVec&) const noexcept;

		/* ************************************************************************ */

		// type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
		void Enqueue(const Data&) override;
		// type Enqueue(argument) specifiers; // Override Queue member (move of the value)
		void Enqueue(Data&&) noexcept override;
		// type Head() specifiers; // Override Queue member (must throw std::length_error when empty)
		Data& Head() const override;
		// type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
		void Dequeue() override;
		// type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
		Data HeadNDequeue() override;
		/* ************************************************************************ */

		inline bool Empty() const noexcept override;

		inline unsigned long Size() const noexcept override;

		void Clear() override;

	protected:

		void Expand();
		void Reduce();
		void SwapVectors(unsigned long) noexcept;

	};

    /* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
