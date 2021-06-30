
namespace lasd {

/* ************************************************************************** */

    /* Default constructor */
    template<typename Data>
    StackVec<Data>::StackVec()
    {
        const unsigned long newSize = 16;
        Elements = new Data[newSize] {};
        size = newSize;
    }

    /* Destructor */
    template<typename Data>
    StackVec<Data>::~StackVec()
    {
        Clear();
    }

    /* Specific constructor */
    template<typename Data>
    StackVec<Data>::StackVec(const LinearContainer<Data>& con) : Vector<Data>(con)
    {
        top = con.Size();
    }

    /* Copy constructor */
    template<typename Data>
    StackVec<Data>::StackVec(const StackVec<Data>& stackvec) : Vector<Data>(stackvec) 
    {
        top = stackvec.top;
    }

    /* Move constructor */
    template<typename Data>
    StackVec<Data>::StackVec(StackVec<Data>&& stackvec) noexcept : Vector<Data>(stackvec) 
    {
        std::swap(top, stackvec.top);
    }

    /* Copy assignment */
    template<typename Data>
    StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stackvec)
    {
        Vector<Data>::operator=(stackvec);
        top = stackvec.top;
        return *this;
    }

    /* Move assignment */
    template<typename Data>
    StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& stackvec) noexcept
    {
        Vector<Data>::operator=(stackvec);
        std::swap(top, stackvec.top);
        return *this;
    }

    /* Comparison operators */
    template<typename Data>
    bool StackVec<Data>::operator==(const StackVec<Data>& stackvec) const noexcept
    {
        unsigned long size = Size();
		if (size == stackvec.Size()) {
			for(unsigned long index = 0; index < size; index++) {
				if (Elements[index] != stackvec.Elements[index]) {
					return false;
				}
			}
			return true;
		}
		else {
			return false;
		}	
	}

    template<typename Data>
    bool StackVec<Data>::operator!=(const StackVec<Data>& stackvec) const noexcept
    {
        return Vector<Data>::operator!=(stackvec);
    }

    /* Push */
    template<typename Data>
    void StackVec<Data>::Push(const Data& value) 
    {
        if (top == size-1)
            Expand();
        Elements[top++] = value;
    }

    template<typename Data>
    void StackVec<Data>::Push(Data&& value) noexcept
    {
        if (top == size-1)
            Expand();
        Elements[top++] = value;
    }

    /* Top */
    template<typename Data>
    Data& StackVec<Data>::Top() const
    {
        if (Empty())
            throw std::length_error("The stack is empty!");
        return Elements[top-1];
    }

    /* TopNPop */
    template<typename Data>
    Data StackVec<Data>::TopNPop()
    {
        if (Empty())
            throw std::length_error("The stack is empty!");
        Data temp = Top();
        Pop();
        return temp;
    }

    /* Pop */
    template<typename Data>
    void StackVec<Data>::Pop() 
    {
        if (Empty())
            throw std::length_error("The stack is empty!");
        
        top--;
        if (top < size / 2)
            Reduce();
    }

    /* Empty */
    template<typename Data>
    bool StackVec<Data>::Empty() const noexcept
    {
        return (top == 0);
    }

    /* Size */
    template<typename Data>
    unsigned long StackVec<Data>::Size() const noexcept
    {
        return top;
    }

    /* Clear */
    template<typename Data>
    void StackVec<Data>::Clear()
    {
        Vector<Data>::Clear();
        Vector<Data>::Resize(1);
        top = 0;
    }

    /* Expand */
    template<typename Data>
    void StackVec<Data>::Expand()
    {   
        const unsigned short coeff = 2;
        Vector<Data>::Resize(size * coeff);
    }

    /* Reduce */
    template<typename Data>
    void StackVec<Data>::Reduce()
    {
        const float coeff = 1.5;
        Vector<Data>::Resize(size / (2 * coeff));
    }
/* ************************************************************************** */

}
