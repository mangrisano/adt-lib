
#include "../queue/lst/queuelst.hpp"

namespace lasd {

	/* Node: Comparison Operators */
	template<typename Data>
	bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept
	{
		bool is_equal_left = false;

		if (Element() != node.Element()) return false;

		if (IsLeaf() && node.IsLeaf()) return true;

		if (HasLeftChild() != node.HasLeftChild()) return false;

		if (HasRightChild() != node.HasRightChild()) return false;
		
		if (!HasLeftChild())
			is_equal_left = true;
		else 
			is_equal_left = (LeftChild() == node.LeftChild());

		if (is_equal_left) {
			if (!HasRightChild())
				return true;
			else
				return (RightChild() == node.RightChild());
		}
		return false;
	}

	template<typename Data>
	bool BinaryTree<Data>::Node::operator!=(const Node& node) const noexcept
	{
		return !(*this == node);
	}

	/* BinaryTree: Comparison Operators */
	template<typename Data>
	bool BinaryTree<Data>::operator==(const BinaryTree<Data>& bt) const noexcept
	{
		if (size != bt.size) return false;

		if (size == 0 && bt.size == 0) return true;
		
		if (Root() != bt.Root()) return false;

		return true;
	}

	template<typename Data>
	bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& bt) const noexcept
	{
		return !(*this == bt);
	}

	template<typename Data>
	void BinaryTree<Data>::MapInOrder(const MapFunctor fun, void* par)
	{		
		if (this->Size() != 0)
			MapInOrder(fun, par, Root());
	}

	template<typename Data>
	void BinaryTree<Data>::MapInOrder(const MapFunctor fun, void* par, Node& node)
	{
		if (node.HasLeftChild())
			MapInOrder(fun, par, node.LeftChild());

		fun(node.Element(), par);

		if (node.HasRightChild())
			MapInOrder(fun, par, node.RightChild());
	}

	template<typename Data>
	void BinaryTree<Data>::FoldInOrder(const FoldFunctor fun, const void* par, void* acc) const
	{
		if (this->Size() != 0)
			FoldInOrder(fun, par, acc, Root());
	}

	template<typename Data>
	void BinaryTree<Data>::FoldInOrder(const FoldFunctor fun, const void* par, void* acc, Node& node) const
	{
		if (node.HasLeftChild())
			FoldInOrder(fun, par, acc, node.LeftChild());

		fun(node.Element(), par, acc);

		if (node.HasRightChild())
			FoldInOrder(fun, par, acc, node.RightChild());
	}

	template<typename Data>
	void BinaryTree<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc) const 
	{
		if (this->Size() != 0)
			FoldPreOrder(fun, par, acc, Root());
	}

	template<typename Data>
	void BinaryTree<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc) const 
	{
		if (this->Size() != 0)
			FoldPostOrder(fun, par, acc, Root());

	}

	template<typename Data>
	void BinaryTree<Data>::MapPreOrder(const MapFunctor fun, void* par) 
	{
		if (this->Size() != 0)
			MapPreOrder(fun, par, Root());
	}

	template<typename Data>
	void BinaryTree<Data>::MapPostOrder(const MapFunctor fun, void* par) 
	{
		if (this->Size() != 0)
			MapPostOrder(fun, par, Root());
	}
	
	template <typename Data>
	void BinaryTree<Data>::MapPreOrder(const MapFunctor fun, void* par, Node& node) 
	{
		fun(node.Element(), par);

		if (node.HasLeftChild())
			MapPreOrder(fun, par, node.LeftChild());

		if (node.HasRightChild())
			MapPreOrder(fun, par, node.RightChild());
	}

	template <typename Data>
	void BinaryTree<Data>::MapPostOrder(const MapFunctor fun, void* par, Node& node) 
	{
		if (node.HasLeftChild())
			MapPostOrder(fun, par, node.LeftChild());

		if (node.HasRightChild())
			MapPostOrder(fun, par, node.RightChild());

		fun(node.Element(), par);
	}

	template<typename Data>
	void BinaryTree<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc, Node& node) const 
	{
		fun(node.Element(), par, acc);

		if (node.HasLeftChild())
			FoldPreOrder(fun, par, acc, node.LeftChild());

		if (node.HasRightChild())
			FoldPreOrder(fun, par, acc, node.RightChild());
	}

	template<typename Data>
	void BinaryTree<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc, Node& node) const
	{
    	if(node.HasLeftChild())
      		FoldPostOrder(fun, par, acc, node.LeftChild());

    	if(node.HasRightChild())
      		FoldPostOrder(fun, par, acc, node.RightChild());

    	fun(node.Element(), par, acc);
	}

	template <typename Data>
	void BinaryTree<Data>::MapBreadth(const MapFunctor fun, void* par) 
	{
		QueueLst<Node*> queuelst;
		Node* curr;
		queuelst.Enqueue(&Root());
		while (queuelst.Size() > 0) {
			curr = queuelst.HeadNDequeue();
			if (curr->HasLeftChild())
				queuelst.Enqueue(&curr->LeftChild());
				
			if (curr->HasRightChild())
				queuelst.Enqueue(&curr->RightChild());

			fun(curr->Element(), par);
		}
	}

	template<typename Data>
	void BinaryTree<Data>::FoldBreadth(const FoldFunctor fun, const void* par, void* acc) const
	{
		QueueLst<Node*> queuelst;
		Node* curr;
		queuelst.Enqueue(&Root());
		while (queuelst.Size() > 0) {
			curr = queuelst.HeadNDequeue();
			if (curr->HasLeftChild())
				queuelst.Enqueue(&curr->LeftChild());
				
			if (curr->HasRightChild())
				queuelst.Enqueue(&curr->RightChild());

			fun(curr->Element(), par, acc);
		}
	}

	/* ########################### PreOrder Iterator ########################### */

	/* BTPreOrderIterator: Specific Costructor */
	template<typename Data>
	BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& bt)
	{
		curr = &(bt.Root());

	}

	/* BTPreOrderIterator: Copy Costructor */
	template<typename Data>
	BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& bt)
	{
		curr = bt.curr;
		stacklst = bt.stacklst;
	}

	/* BTPreOrderIterator: Move Costructor */
	template<typename Data>
	BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& bt) noexcept
	{
		std::swap(curr, bt.curr);
		std::swap(stacklst, bt.stacklst);
	}

	/* BTPreOrderIterator: Copy assignment */
	template<typename Data>
	BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data>& bt)
	{
		curr = bt.curr;
		stacklst = bt.stacklst;
		return *this;
	}	

	/* BTPreOrderIterator: Move assignment */
	template<typename Data>
	BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& bt) noexcept
	{
		std::swap(curr, bt.curr);
		std::swap(stacklst, bt.stacklst);
		return *this;
	}

	/* Comparison Operators */
	template<typename Data>
	bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& bt) const noexcept
	{
		return ((curr == bt.curr) && (stacklst == bt.stacklst));
	}
	
	template<typename Data>
	bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data>& bt) const noexcept
	{
		return !(*this ==  bt);
	}

	/* Derefercing operator */
	template<typename Data>
	Data& BTPreOrderIterator<Data>::operator*() const 
	{
		if (Terminated())
			throw std::out_of_range("The Iterator is terminated!");

		return curr->Element();
	}
	
	/* Terminated */
	template<typename Data>
	bool BTPreOrderIterator<Data>::Terminated() const noexcept
	{
		return curr == nullptr;
	}

	/* Forward Operator */
	template<typename Data>
	BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++()
	{
		if (Terminated())
			throw std::out_of_range("The PreOrder Iterator is terminated!");
		
		if (curr->HasRightChild())
			stacklst.Push(&(curr->RightChild()));
		
		if (curr->HasLeftChild())
			stacklst.Push(&(curr->LeftChild()));
		
		if (stacklst.Empty())
			curr = nullptr;
		else
			curr = stacklst.TopNPop();

		return *this;
	}

	/* ########################### Breadth Iterator ########################### */

	/* BTBreadthIterator: Specific Costructor */
	template<typename Data>
	BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& bt)
	{
		curr = &(bt.Root());

	}

	/* BTBreadthIterator: Copy Costructor */
	template<typename Data>
	BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& bt)
	{
		curr = bt.curr;
		queuelst = bt.queuelst;
	}

	/* BTBreadthIterator: Move Costructor */
	template<typename Data>
	BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& bt) noexcept
	{
		std::swap(curr, bt.curr);
		std::swap(queuelst, bt.queuelst);
	}

	/* BTBreadthIterator: Copy assignment */
	template<typename Data>
	BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data>& bt)
	{
		curr = bt.curr;
		queuelst = bt.queuelst;
		return *this;
	}	

	/* BTBreadthIterator: Move assignment */
	template<typename Data>
	BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data>&& bt) noexcept
	{
		std::swap(curr, bt.curr);
		std::swap(queuelst, bt.queuelst);
		return *this;
	}

	/* Comparison Operators */
	template<typename Data>
	bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data>& bt) const noexcept
	{
		return ((curr == bt.curr) && (queuelst == bt.queuelst));	
	}
	
	template<typename Data>
	bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data>& bt) const noexcept
	{
		return !(*this ==  bt);
	}

	/* Derefercing operator */
	template<typename Data>
	Data& BTBreadthIterator<Data>::operator*() const 
	{
		if (Terminated())
			throw std::out_of_range("The Iterator is terminated!");

		return curr->Element();
	}
	
	/* Terminated */
	template<typename Data>
	bool BTBreadthIterator<Data>::Terminated() const noexcept
	{
		return curr == nullptr;
	}

	/* Forward Operator */
	template<typename Data>
	BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++()
	{
		if (Terminated())
			throw std::out_of_range("The Breadth Iterator is terminated!");
		
		if (curr->HasLeftChild())
			queuelst.Enqueue(&(curr->LeftChild()));
		
		if (curr->HasRightChild())
			queuelst.Enqueue(&(curr->RightChild()));
		
		if (queuelst.Empty())
			curr = nullptr;
		else
			curr = queuelst.HeadNDequeue();
		
		return *this;
	}

/* 	/* ########################### InOrder Iterator ########################### */

/* BTInOrderIterator: Specific Costructor */
	template<typename Data>
	BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& bt)
	{
		curr = &findMostLeftChild((bt.Root()));
	}

	/* BTInOrderIterator: Copy Costructor */
	template<typename Data>
	BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data>& bt)
	{
		curr = bt.curr;
		stacklst = bt.stacklst;
	}

	/* BTInOrderIterator: Move Costructor */
	template<typename Data>
	BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data>&& bt) noexcept
	{
		std::swap(curr, bt.curr);
		std::swap(stacklst, bt.stacklst);
	}

	/* BTInOrderIterator: Copy assignment */
	template<typename Data>
	BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data>& bt)
	{
		curr = bt.curr;
		stacklst = bt.stacklst;
		return *this;
	}	

	/* BTInOrderIterator: Move assignment */
	template<typename Data>
	BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data>&& bt) noexcept
	{
		std::swap(curr, bt.curr);
		std::swap(stacklst, bt.stacklst);
		return *this;
	}

	/* Comparison Operators */
	template<typename Data>
	bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data>& bt) const noexcept
	{
		return ((curr == bt.curr) && (stacklst == bt.stacklst));
	}
	
	template<typename Data>
	bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data>& bt) const noexcept
	{
		return !(*this ==  bt);
	}

	/* Derefercing operator */
	template<typename Data>
	Data& BTInOrderIterator<Data>::operator*() const 
	{
		if (Terminated())
			throw std::out_of_range("The Iterator is terminated!");

		return curr->Element();
	}

	/* Terminated */
	template<typename Data>
	bool BTInOrderIterator<Data>::Terminated() const noexcept
	{
		return curr == nullptr;
	}
	
	/* FindMostLeftChild */
	template<typename Data>
    typename BinaryTree<Data>::Node& BTInOrderIterator<Data>::findMostLeftChild(typename BinaryTree<Data>::Node& node)
    {
    	if (node.HasLeftChild()) {
      		stacklst.Push(&node);
      		return findMostLeftChild(node.LeftChild());
    	}
    	return node;
    }

	/* Forward Operator */
	template<typename Data>
	BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++()
	{
		
		if (Terminated()) throw std::out_of_range("The InOrder Iterator is Terminated!");

      	if(curr->HasRightChild())
        	curr = &findMostLeftChild(curr->RightChild());
	
      	else if (stacklst.Empty())
	      	curr = nullptr;
      	else 
          	curr = stacklst.TopNPop();

    	return *this;

	}

	/* 	/* ########################### BTPostOrder Iterator ########################### */

/* BTPostOrderIterator: Specific Costructor */
	template<typename Data>
	BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& bt)
	{
		curr = &(bt.Root());
		findLeftMostLeaf();
		last = curr;
		
	}

	/* BTPostOrderIterator: Copy Costructor */
	template<typename Data>
	BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data>& bt)
	{
		curr = bt.curr;
		stacklst = bt.stacklst;
		last = bt.last;
	}

	/* BTPostOrderIterator: Move Costructor */
	template<typename Data>
	BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data>&& bt) noexcept
	{
		std::swap(curr, bt.curr);
		std::swap(stacklst, bt.stacklst);
		std::swap(last, bt.last);
	}
	
	/* BTPostOrderIterator: Copy assignment */
	template<typename Data>
	BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data>& bt)
	{
		curr = bt.curr;
		stacklst = bt.stacklst;
		last = bt.last;
		return *this;
	}	

	/* BTPostOrderIterator: Move assignment */
	template<typename Data>
	BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data>&& bt) noexcept
	{
		std::swap(curr, bt.curr);
		std::swap(stacklst, bt.stacklst);
		return *this;
	}

	/* Comparison Operators */
	template<typename Data>
	bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data>& bt) const noexcept
	{
		return ((curr == bt.curr) && (stacklst == bt.stacklst));	
	}
	
	template<typename Data>
	bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data>& bt) const noexcept
	{
		return !(*this ==  bt);
	}

	/* Derefercing operator */
	template<typename Data>
	Data& BTPostOrderIterator<Data>::operator*() const 
	{
		if (Terminated())
			throw std::out_of_range("The Iterator is terminated!");

		return curr->Element();
	}

	/* Terminated */
	template<typename Data>
	bool BTPostOrderIterator<Data>::Terminated() const noexcept
	{
		return curr == nullptr;
	}

	/* findMostLeftLeaf */
	template<typename Data>
	void BTPostOrderIterator<Data>::findLeftMostLeaf()
	{
		while (curr->HasLeftChild()) {
			stacklst.Push(curr);
			curr = &curr->LeftChild();
		}
		if (curr->HasRightChild()) {
			stacklst.Push(curr);
			curr = &curr->RightChild();
			findLeftMostLeaf();
		}
	}
	/* Forward Operator */
	template <typename Data>
	BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() 
	{
		if (Terminated())
			throw std::out_of_range("Iterator is terminated");
	
		if (!stacklst.Empty()) {
			curr = stacklst.TopNPop();
			if (curr->HasRightChild()) {
				if (&curr->RightChild() != last) {
					stacklst.Push(curr);
					curr = &curr->RightChild();
					findLeftMostLeaf();
				}
			}
		}
		else
			curr = nullptr;

		last = curr;

		return *this;
	} 
}