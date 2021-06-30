
namespace lasd {

	/* List - Default constructor */
	template<typename Data>
	List<Data>::List()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	/* List - Constructor with param [Linear Container] */
	template<typename Data>
	List<Data>::List(const LinearContainer<Data>& con)
	{
		unsigned long size = con.Size();
		for (unsigned long i = 0; i < size; i++) {
			InsertAtBack(con[i]);
		}
	}

	/* List - Copy constructor */
	template<typename Data>
	List<Data>::List(const List<Data>& lst)
	{
		struct Node* curr = lst.head;
		while (curr != nullptr) {
			InsertAtBack(curr->element);
			curr = curr->next;
		}
	}	

	/* List - Copy assignment */
	template<typename Data>
	List<Data>& List<Data>::operator=(const List<Data>& lst)
	{
		Clear();
		struct Node* curr = lst.head;
		while (curr != nullptr) {
			InsertAtBack(curr->element);
			curr = curr->next;
		}
		return *this;
	}

	/* List - Move constructor */
	template<typename Data>
	List<Data>::List(List<Data>&& lst) noexcept
	{
		std::swap(head, lst.head);
		std::swap(tail, lst.tail);
		std::swap(size, lst.size);
	}

	/* List - Move assignment */
	template<typename Data>
	List<Data>& List<Data>::operator=(List<Data>&& lst) noexcept
	{
		std::swap(head, lst.head);
		std::swap(tail, lst.tail);
		std::swap(size, lst.size);
		return *this;
	}

	/* List - Destructor */
	template<typename Data>
	List<Data>::~List()
	{
		Clear();
	}

	/* Node - Constructor with param */
	template<typename Data>
	List<Data>::Node::Node(Data element)
	{	
		element = element;
		next = nullptr;
	}

	/* Node - Copy constructor */
	template<typename Data>
	List<Data>::Node::Node(const Node& node)
	{
		element = node.element;
		next = node.next;
	}

	/* Node - Move constructor */
	template<typename Data>
	List<Data>::Node::Node(Node&& node) noexcept
	{
		std::swap(element, node.element);
		std::swap(next, node.next);
	}

	/* Node - Destructor */
	template<typename Data>
	List<Data>::Node::~Node()
	{
		next = nullptr;
	}

	template<typename Data>
	void List<Data>::InsertAtBack(const Data& value) 
	{
		struct Node* node = new Node();
		node->element = value;
		node->next = nullptr;
		if (size == 0) {
			head = node;
		}
		else {
			tail->next = node;
		}
		tail = node;
		size += 1;
	}

	template<typename Data>
	void List<Data>::InsertAtBack(Data&& value) 
	{
		struct Node* node = new Node();
		node->element = value;
		node->next = nullptr;
		if (size == 0) {
			head = node;
		}
		else {
			tail->next = node;
		}
		tail = node;
		size += 1;
	}

	template<typename Data>
	void List<Data>::InsertAtFront(const Data& value) 
	{
		struct Node* node = new Node();
		node->element = value;
		node->next = head;
		head = node;
		if (size == 0) {
			tail = node;
		}
		size += 1;
	}

	template<typename Data>
	void List<Data>::InsertAtFront(Data&& value) 
	{
		struct Node* node = new Node();
		node->element = value;
		node->next = head;
		head = node;
		if (size == 0) {
			tail = node;
		}
		size += 1;
	}

	template<typename Data>
	void List<Data>::RemoveFromFront() 
	{
		if (size == 0) {
			throw std::length_error("The list is empty!");
		}
		struct Node* temp;
		temp = head;
		head = head->next;
		delete temp;
		size -= 1;
		if (size == 0) {
			tail = nullptr;
		}
	}

	template<typename Data>
	Data List<Data>::FrontNRemove()
	{
		if (size == 0) {
			throw std::length_error("The list is empty!");
		}
		Data temp = Front();
		RemoveFromFront();
		return temp;
	}

	template<typename Data>
	Data& List<Data>::Front() const
	{
		if (size == 0) {
			throw std::length_error("The list is empty!");
		}
		return head->element;
	}

	template<typename Data>
	Data& List<Data>::Back() const
	{
		if (size == 0) {
			throw std::length_error("The list is empty!");
		}
		return tail->element;
	}

	template<typename Data>
	Data& List<Data>::operator[](const unsigned long index) const
	{
		struct Node* curr = head;
		if (index > size-1) {
			throw std::out_of_range("No existing element!");
		}
		for (unsigned long i = 0; i < index; i++) {
			curr = curr->next;
		}
		return curr->element;
	}

	template<typename Data>
	void List<Data>::Clear()
	{	
		struct Node* temp = head;
		while (head != nullptr) {
			temp = head;
			head = head->next;
			delete temp;	
		}
		tail = nullptr;
		size = 0;
	}

	template<typename Data>
	bool List<Data>::operator==(const List<Data>& lst) const noexcept
	{	
		struct Node* curr = head;
		struct Node* curr_lst = lst.head;
		if (size != lst.size) {
			return false;
		}
		for (unsigned long i = 0; i < lst.size; i++) {
			if (curr->element != curr_lst->element) {
				return false;
			}
			curr = curr->next;
			curr_lst = curr_lst->next;
		}
		return true;
	}

	template<typename Data>
	inline bool List<Data>::operator!=(const List<Data>& lst) const noexcept
	{
		return !(*this == lst);
	}

	template <typename Data>
	void List<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc) const {
		FoldPreOrder(fun, par, acc, head);
	}

	template<typename Data>
	void List<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc) const {
		FoldPostOrder(fun, par, acc, head);

	}

	template<typename Data>
	void List<Data>::MapPreOrder(MapFunctor fun, void* par) {
		MapPreOrder(fun, par, head);
	}

	template<typename Data>
	void List<Data>::MapPostOrder(MapFunctor fun, void* par) {
		MapPostOrder(fun, par, head);
	}
	
	template <typename Data>
	void List<Data>::MapPreOrder(MapFunctor fun, void* par, struct Node* head) {
  		if(head != nullptr ) {
    		fun(head->element, par);
    		MapPreOrder(fun, par, head->next);
  		}
	}

	template <typename Data>
	void List<Data>::MapPostOrder(MapFunctor fun, void* par, struct Node* head) {
  		if(head != nullptr) {
    		if(head->next != nullptr ) {
      			MapPostOrder(fun, par, head->next);
      		}	
    		fun(head->element, par);
  		}
	}
	template<typename Data>
	void List<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc, struct Node* head) const {
  		if( head != nullptr ) {
    		fun(head->element, par, acc);
    		FoldPreOrder(fun, par, acc, head->next);
  		}
	}

	template<typename Data>
	void List<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc, struct Node* head) const {
  		if(head != nullptr) {
    		if(head->next != nullptr ) {
      			FoldPostOrder(fun, par, acc, head->next);
      		}
    		fun(head->element, par, acc);
  		}
	}
}