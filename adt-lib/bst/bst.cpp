
namespace lasd {

	/* ************************************************************************** */

	/* Specific Constructor */ 
	template<typename Data>
	BST<Data>::BST(const LinearContainer<Data>& con)
	{
		for (unsigned long i = 0; i < con.Size(); i++)
			Insert(con[i]);
	}

	/* Copy Constructor */
	template<typename Data>
	BST<Data>::BST(const BST<Data>& bst) : BinaryTreeLnk<Data>(bst) {}

	/* Move Constructor */
	template<typename Data>
	BST<Data>::BST(BST<Data>&& bst) noexcept : BinaryTreeLnk<Data>(std::move(bst)) {}

	/* Copy Assignment */
	template<typename Data>
	BST<Data>& BST<Data>::operator=(const BST<Data>& bst)
	{
		BinaryTreeLnk<Data>::operator=(bst);
		return *this;
	}

	/* Move Assignment */
	template<typename Data>
	BST<Data>& BST<Data>::operator=(BST<Data>&& bst) noexcept
	{
		BinaryTreeLnk<Data>::operator=(std::move(bst));
		return *this;
	}

	/* Comparison Operators */
	template<typename Data>
	bool BST<Data>::operator==(const BST<Data>& bst) const noexcept
	{
		if (size != bst.Size()) return false;

		BTInOrderIterator<Data> this_it(*this);
		BTInOrderIterator<Data> other_it(bst);
		for (; !other_it.Terminated(); ++this_it, ++other_it) {
			if (*this_it != *other_it)
				return false;
		}
		return true;

	}

	template<typename Data>
	bool BST<Data>::operator!=(const BST<Data>& bst) const noexcept
	{
		return !(*this == bst);
	}

	/* Insert */
	template<typename Data>
	void BST<Data>::Insert(const Data& val) noexcept
	{
		NodeLnk*& ptr = FindPointerTo(root, val);
		if (ptr == nullptr) {
			ptr = new NodeLnk(val);
			size++;
		}
	}

	template<typename Data>
	void BST<Data>::Insert(Data&& val) noexcept
	{
		NodeLnk*& ptr = FindPointerTo(root, val);
		if (ptr == nullptr) {
			ptr = new NodeLnk(std::move(val));
			size++;
		} 
	}

	/* Remove */
	template<typename Data>
	void BST<Data>::Remove(const Data& val) noexcept
	{
		delete Detach(FindPointerTo(root, val));
	}

	/* Min */
	template<typename Data>
	const Data& BST<Data>::Min() const
	{	
		if (root == nullptr) throw std::length_error("The Min value is not found!");
		return FindPointerToMin(root)->value;
	}

	/* MinNRemove */
	template<typename Data>
	Data BST<Data>::MinNRemove()
	{	
		if (root == nullptr) throw std::length_error("The Min value to remove is not found!"); 
		return DataNDelete(DetachMin(root));
	}

	/* RemoveMin */
	template<typename Data>
	void BST<Data>::RemoveMin()
	{
		if (root == nullptr) throw std::length_error("The Min value to remove is not found!");
		delete DetachMin(root);
	}
	/* Max */
	template<typename Data>
	const Data& BST<Data>::Max() const
	{
		if (root == nullptr) throw std::length_error("The Max value is not found!");
		return FindPointerToMax(root)->value;
	}

	/* MaxNRemove */
	template<typename Data>
	Data BST<Data>::MaxNRemove()
	{
		if (root == nullptr) throw std::length_error("The Max value to remove is not found!");
		return DataNDelete(DetachMax(root));
	
	}

	/* RemoveMax */
	template<typename Data>
	void BST<Data>::RemoveMax()
	{
		if (root == nullptr) throw std::length_error("The Max value to remove is not found!");
		delete DetachMax(root);
	}
	
	/* Predecessor */
	template<typename Data>
	const Data& BST<Data>::Predecessor(const Data& val) const
	{
		NodeLnk* const & pred = FindPointerToPredecessor(root, val);
		if (pred != nullptr) {
			return (*pred).value;
		}
		
		throw std::length_error("The Predecessor value is not found");
	}

	/* PredecessorNRemove */
	template<typename Data>
	Data BST<Data>::PredecessorNRemove(const Data& val)
	{
		NodeLnk*& pred = FindPointerToPredecessor(root, val);
		if (pred != nullptr)
			return DataNDelete(Detach(pred));
		else
			throw std::length_error("The Predecessor value to remove is not found!");
	}

	/* RemovePredecessor */
	template<typename Data>
	void BST<Data>::RemovePredecessor(const Data& val)
	{
		NodeLnk*& pred = FindPointerToPredecessor(root, val);
		if (pred != nullptr)
			delete Detach(pred);
		else
			throw std::length_error("The Predecessor value to remove is not found!");
	}

	/* Successor */
	template<typename Data>
	const Data& BST<Data>::Successor(const Data& val) const
	{
		NodeLnk* const & succ = FindPointerToSuccessor(root, val);
		if (succ != nullptr)
			return (*succ).value;
		else
			throw std::length_error("The Successor value is not found!");
	}

	/* SuccessorNRemove */
	template<typename Data>
	Data BST<Data>::SuccessorNRemove(const Data& val)
	{
		NodeLnk*& succ = FindPointerToSuccessor(root, val);
		if (succ != nullptr)
			return DataNDelete(Detach(succ));
		else
			throw std::length_error("The Successor value to remove is not found!");
	}

	/* RemoveSuccessor */
	template<typename Data>
	void BST<Data>::RemoveSuccessor(const Data& val)
	{
		NodeLnk*& succ = FindPointerToSuccessor(root, val);
		if (succ != nullptr)
			delete Detach(succ);
		else
			throw std::length_error("The Successor value to remove is not found!");
	}

	template<typename Data>
	bool BST<Data>::Exists(const Data& val) const noexcept
	{
		return (FindPointerTo(root, val) != nullptr);
	}

	/* DataNDelete */
	template<typename Data>
	Data BST<Data>::DataNDelete(NodeLnk* node) noexcept
	{
		Data val;
		std::swap(val, node->value);
		delete node;
		return val;

	}

	/* Detach */
	template<typename Data>
	typename BST<Data>::NodeLnk* BST<Data>::Detach(NodeLnk*& node) noexcept
	{
		if (node != nullptr) {
			if (node->left != nullptr && node->right != nullptr) {
				NodeLnk* min = DetachMin(node->right);
				std::swap(node->value, min->value);
				return min;
			}
			else {
				if (node->left == nullptr)
					return SkipOnRight(node);

				if (node->right == nullptr)
					return SkipOnLeft(node);
			}
		}
		return nullptr;
	}

	/* DetachMin */
	template<typename Data>
	typename BST<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk*& node) noexcept
	{
		return SkipOnRight(FindPointerToMin(node));

	}

	/* DetachMax */
	template<typename Data>
	typename BST<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk*& node) noexcept
	{
		return SkipOnLeft(FindPointerToMax(node));
	}

	/* SkipOnLeft */
	template<typename Data>
	typename BST<Data>::NodeLnk* BST<Data>::SkipOnLeft(NodeLnk*& node) noexcept
	{
		if (node == nullptr) return nullptr;
		NodeLnk* tmp_left = nullptr;
		std::swap(tmp_left, node->left);
		std::swap(tmp_left, node);
		size--;

		return tmp_left;	

	}
	/* SkipOnRight */
	template<typename Data>
	typename BST<Data>::NodeLnk* BST<Data>::SkipOnRight(NodeLnk*& node) noexcept {
		if (node == nullptr) return nullptr;
		NodeLnk* tmp_right = nullptr;
		std::swap(tmp_right, node->right);
		std::swap(tmp_right, node);
		size--;

		return tmp_right;
	}

	/* FindPointerToMin */
	template<typename Data>
	typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk*& node) noexcept
	{
		return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMin(node));
	}

	template<typename Data>
	typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(NodeLnk* const& node) const noexcept
	{
		NodeLnk* const *ptr = &node;
		NodeLnk* curr = node;
		if (curr != nullptr) {
			while (curr->left != nullptr) {
				ptr = &curr->left;
				curr = curr->left;
			}
		}

		return *ptr;
	}
	
	/* FindPointerToMax */
	template<typename Data>
	typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& node) noexcept
	{
		return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMax(node));
	}

	template<typename Data>
	typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(NodeLnk* const& node) const noexcept
	{
		NodeLnk* const * ptr = &node;
		NodeLnk* curr = node;
		if (curr != nullptr) {
			while (curr->right != nullptr) {
				ptr = &curr->right;
				curr = curr->right;
			}
		}

		return *ptr;
	}
	
	/* FindPointerTo */
	template<typename Data>
	typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& node, const Data& val) noexcept
	{
		return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerTo(node, val));
	}

	template<typename Data>
	typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerTo(NodeLnk* const& node, const Data& val) const noexcept
	{
		NodeLnk* const * ptr = &node;
		NodeLnk* curr = node;
		if (curr != nullptr) {
			while (curr != nullptr) {
				if (val < curr->value) {
					ptr = &curr->left;
					curr = curr->left;
				}	
				else if (val > curr->value) {
					ptr = &curr->right;
					curr = curr->right;
				}
				else	
					return *ptr;
			}
		}

		return *ptr;

	}

	/* FindPointerToPredecessor */
	template<typename Data>
	typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToPredecessor(NodeLnk*& node, const Data& val) noexcept
	{
		return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToPredecessor(node, val));
	}

	template<typename Data>
	typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToPredecessor(NodeLnk* const& node, const Data& val) const noexcept
	{
		NodeLnk* const* ptr = nullptr;
 		NodeLnk* const* curr = &node;
 
 		while ((*curr) != nullptr && (*curr)->value != val) {
 			if ((*curr)->value < val) {
 				ptr = curr;
 				curr = &(*curr)->right;
 			}
 			else
 				curr = &(*curr)->left; 
 		}
 
 		if ((*curr) != nullptr && (*curr)->left != nullptr)
 			ptr = &FindPointerToMax((*curr)->left);

		if (ptr == nullptr) {
        	if (*curr == nullptr)
            	ptr = curr;

        	else {
            	curr = &(*curr)->left;
            	ptr = curr;
        	}
    	}

 		return *ptr;
	}

	/* FindPointerToSuccessor */
	template<typename Data>
	typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToSuccessor(NodeLnk*& node, const Data& val) noexcept
	{
		return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(node, val));
	}

	template<typename Data>
	typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToSuccessor(NodeLnk* const& node, const Data& val) const noexcept
	{
		NodeLnk* const * ptr = nullptr;
		NodeLnk* const * curr = &node;
		while ((*curr) != nullptr && (*curr)->value != val) {
			if ((*curr)->value > val) {
				ptr = curr;
				curr = &(*curr)->left;
			}
			else {
				curr = &(*curr)->right;
			}
		}
		if ((*curr) != nullptr && (*curr)->right != nullptr)
			ptr = &FindPointerToMin((*curr)->right);

		if (ptr == nullptr) {
        	if (*curr == nullptr)
            	ptr = curr;

        	else {
            	curr = &(*curr)->right;
            	ptr = curr;
        	}
    	}

		return *ptr;
	}

	 /* ************************************************************************** */

}
