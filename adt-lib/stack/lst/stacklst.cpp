
namespace lasd {

/* ************************************************************************** */

	/* Destructor */
	template<typename Data>
	StackLst<Data>::~StackLst()
	{
		Clear();
	}

	/* Specific constructor */
    template<typename Data>
    StackLst<Data>::StackLst(const LinearContainer<Data>& con) : List<Data>(con) {}

	/* Copy constructor */
    template<typename Data>
    StackLst<Data>::StackLst(const StackLst<Data>& stacklst) : List<Data>(stacklst) {} 

	/* Copy assignment */
    template<typename Data>
    StackLst<Data>& StackLst<Data>::operator=(const StackLst<Data>& stacklst) 
	{
		List<Data>::operator=(stacklst);
		return *this;
    }

	/* Move constructor */
	template<typename Data>
	StackLst<Data>::StackLst(StackLst<Data>&& stacklst) noexcept : List<Data>(std::move(stacklst)) {}

	/* Move assignment */
	template<typename Data>
	StackLst<Data>& StackLst<Data>::operator=(StackLst<Data>&& stacklst) noexcept
	{
		List<Data>::operator=(std::move(stacklst));
		return *this;
	}

	/* Comparison operators */
	template<typename Data>
	bool StackLst<Data>::operator==(const StackLst<Data>& stacklst) const noexcept
	{
		return List<Data>::operator==(stacklst);
	}

	template<typename Data>
	bool StackLst<Data>::operator!=(const StackLst<Data>& stacklst) const noexcept
	{
		return List<Data>::operator!=(stacklst);
	}

	/* Push */
	template<typename Data>
	void StackLst<Data>::Push(const Data& value) 
	{
		List<Data>::InsertAtFront(value);
	}

	template<typename Data>
	void StackLst<Data>::Push(Data&& value) noexcept
	{
		List<Data>::InsertAtFront(value);
	}

	/* Top */
	template<typename Data>
	Data& StackLst<Data>::Top() const
	{
		return List<Data>::Front();
	}

	/* Pop */
	template<typename Data>
	void StackLst<Data>::Pop() 
	{
		List<Data>::RemoveFromFront();
	}

	/* TopNRemove */
	template<typename Data>
	Data StackLst<Data>::TopNPop()
	{
		return List<Data>::FrontNRemove();
	}

	/* Clear */
	template<typename Data>
	void StackLst<Data>::Clear()
	{
		List<Data>::Clear();
	}
    /* ************************************************************************** */

}
