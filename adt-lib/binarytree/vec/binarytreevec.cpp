
namespace lasd {


	/* Node: Constructor */
	template<typename Data>
	BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& nodeValue, unsigned long indx, Vector<NodeVec*>* vec)
	{
		value = nodeValue;
		index = indx;
		nodeVec = vec;
	}

	/* BinaryTreeVec: Specific Constructor */
	template<typename Data>
	BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data>& con)
	{
		if (con.Size() != 0) {
			size = con.Size();
			treevec.Resize(size);

			for(unsigned long i = 0; i < size; i++) {
				treevec[i] = new NodeVec(con[i], i, &treevec);
			}	
		}
	}

	/* Destructor */
	template<typename Data>
	BinaryTreeVec<Data>::~BinaryTreeVec()
	{
		if (size != 0) {
			for (unsigned long i = 0; i < size; i++)
				delete treevec[i];
		}
	}

	/* Copy Constructor */
	template<typename Data>
	BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& bt)
	{
		Clear();
		size = bt.size;
		treevec.Resize(size);

		for (unsigned long i = 0; i < size; i++)
			treevec[i] = new NodeVec(bt.treevec[i]->Element(), i, &treevec);
	}

	/* Move Constructor */
	template<typename Data>
	BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& bt) noexcept
	{
		std::swap(size, bt.size);
		std::swap(treevec, bt.treevec);
	}

	/* Copy Assignment */
	template<typename Data>
	BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& bt)
	{
		Clear();
		size = bt.size;
		treevec.Resize(size);

		for (unsigned long i = 0; i < size; i++)
			treevec[i] = new NodeVec(bt.treevec[i]->Element(), i, &treevec);
		
		return *this;
	}

	/* Move Assignment */
	template<typename Data>
	BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& bt) noexcept
	{
		std::swap(size, bt.size);
		std::swap(treevec, bt.treevec);
		return *this;
	}

	/* Comparison Operators */
	/*template<typename Data>
	bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec<Data>& bt) const noexcept
	{
		return BinaryTree<Data>::operator==(bt);
	}		

	template<typename Data>
	bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec<Data>& bt) const noexcept
	{
		return !(BinaryTree<Data>::operator==(bt));
	}*/

	/* Element */
	template<typename Data>
	Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept
	{
		return value;
	}

	template<typename Data>
	const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept
	{
		return value;
	}

	/* IsLeaf */
	template<typename Data>
	bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept
	{
		return (!HasLeftChild() && !HasRightChild());
	}

	/* HasLeftChild */
	template<typename Data>
	bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept
	{		
		return (2 * index + 1) <= nodeVec->Size() - 1;
	}

	/* HasRightChild */
	template<typename Data>
	bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept
	{
		return (2 * index + 2) <= nodeVec->Size() - 1;
	}

	/* LeftChild */
	template<typename Data>
	typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const
	{
		if (!HasLeftChild())
			throw std::out_of_range("The left child doesn't exists");
		
		return *((*nodeVec)[2 * index + 1]);
	}

	/* RightChild */
	template<typename Data>
	typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const
	{
		if (!HasRightChild())
			throw std::out_of_range("The right child doesn't exists");

		return *((*nodeVec)[2 * index + 2]);
	}

	/* Root */
	template<typename Data>
	typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const
	{
		if (size == 0)
			throw std::length_error("The Binary Tree is Empty!");
		
		return *(treevec[0]);
	}

	/* Clear */
	template<typename Data>
	void BinaryTreeVec<Data>::Clear()
	{
		if (size != 0) {
			for (unsigned long i = 0; i < size; i++)
				delete treevec[i];

			treevec.Clear();
			size = 0;
		}
	}

	template <typename Data>
	void BinaryTreeVec<Data>::MapBreadth(const MapFunctor fun, void* par) 
	{
		for (unsigned long i = 0; i < size; i++)
			fun(treevec[i]->Element(), par);
	}

	template<typename Data>
	void BinaryTreeVec<Data>::FoldBreadth(const FoldFunctor fun, const void* par, void* acc) const
	{
		for (unsigned long i = 0; i < size; i++)
			fun(treevec[i]->Element(), par, acc);
	}
}
