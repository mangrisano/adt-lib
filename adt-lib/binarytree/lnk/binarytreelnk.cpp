
namespace lasd {

	/* Node: Constructor */
	template<typename Data>
	BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& val)
	{
		value = val;
		left = nullptr;
		right = nullptr;
	}

	/* Specific Constructor */
	template<typename Data>
	BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& con)
	{
		size = con.Size();
		if (size != 0) {
			root = new NodeLnk(con[0]);
			generateBT(0, root, con);
		}
	}

	/* Generate BT */
	template<typename Data>
	void BinaryTreeLnk<Data>::generateBT(unsigned long index, BinaryTreeLnk<Data>::NodeLnk* node, const LinearContainer<Data>& con)
	{
  		if ((index * 2 + 1) <= (con.Size() - 1)) {
      		node->left = new NodeLnk(con[index * 2 + 1]);
      		generateBT(index * 2 + 1, node->left, con);
    	}	

    	if ((index * 2 + 2) <= (con.Size() - 1)) {
      		node->right = new NodeLnk(con[index * 2 + 2]);
      		generateBT(index * 2 + 2, node->right, con);
    	}
	}

	/* Copy BT */
	template<typename Data>
	typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::copyBT(const BinaryTreeLnk<Data>::NodeLnk* root_source)
	{
		if (root_source == nullptr) return nullptr;
		typename BinaryTreeLnk<Data>::NodeLnk* root_dest = new NodeLnk(root_source->Element());
		if (root_source->HasLeftChild())
			root_dest->left = copyBT(root_source->left);
			
		if (root_source->HasRightChild())
			root_dest->right = copyBT(root_source->right);
		return root_dest;

	}

	/* Copy Constructor */
	template<typename Data>
	BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data>& bt)
	{
		size = bt.size;
		if (size != 0)
			root = copyBT(bt.root);
	}

	/* Move Constructor */
	template<typename Data>
	BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data>&& bt) noexcept
	{
		std::swap(root, bt.root);
		std::swap(size, bt.size);
	}

	/* Copy Assignment */
	template<typename Data>
	BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& bt)
	{
		size = bt.size;
		if (size != 0)
			root = copyBT(bt.root);
		return *this;
	}

	/* Move Assignment */
	template<typename Data>
	BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data>&& bt) noexcept
	{
		std::swap(root, bt.root);
		std::swap(size, bt.size);
		return *this;
	}

	/* Comparison Operators */
	/*template<typename Data>
	bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data>& bt) const noexcept
	{
	}	

	template<typename Data>
	bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data>& bt) const noexcept
	{
	}*/

	/* Destructor */
	template<typename Data>
	BinaryTreeLnk<Data>::~BinaryTreeLnk()
	{
		if (size != 0)
			Clear();
	}

	/* NodeLnk: Destructor */
	template<typename Data>
	BinaryTreeLnk<Data>::NodeLnk::~NodeLnk()
	{
		if (HasLeftChild()) {
			delete left;
		}	
		if (HasRightChild()) {
			delete right;
		}	
	}

	/* Element */
	template<typename Data>
	Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept
	{
		return value;
	}

	template<typename Data>
	const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept
	{
		return value;
	}

	/* IsLeaf */
	template<typename Data>
	bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept
	{
		return (!HasLeftChild() && !HasRightChild());

	}

	/* HasLeftChild */
	template<typename Data>
	bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept
	{
		return (left != nullptr);
	}

	/* HasRightChild */
	template<typename Data>
	bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept
	{
		return (right != nullptr);
	}

	/* LeftChild */
	template<typename Data>
	typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const
	{
		if (!HasLeftChild())
			throw std::out_of_range("The left child doesn't exists");
		
		return *left;
	}

	/* RightChild */
	template<typename Data>
	typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const
	{
		if (!HasRightChild())
			throw std::out_of_range("The right child doesn't exists");
		
		return *right;
	}

	/* Root */
	template<typename Data>
	typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root() const
	{
		if (size == 0)
			throw std::length_error("The Binary Tree is Empty!");
		
		return *root;
	}

	/* Clear */
	template<typename Data>
	void BinaryTreeLnk<Data>::Clear()
	{
		if (size != 0) {
			delete root;
			root = nullptr;
			size = 0;
		}
	}
}
