
namespace lasd {

/* ************************************************************************** */

	/* Default Constructor */
	template<typename Data>
	MatrixCSR<Data>::MatrixCSR()
	{
		rowVec.Resize(1);
		rowVec[0] = &head;
	}

	/* Specific Constructor */
	template<typename Data>
	MatrixCSR<Data>::MatrixCSR(unsigned long r, unsigned long c)
	{
		row = r;
		col = c;
		rowVec.Resize(r + 1);
		for (unsigned long i = 0; i <= r; i++) {
			rowVec[i] = &head;
		}
	}

	/* Copy Constructor */
	template<typename Data>
	MatrixCSR<Data>::MatrixCSR(const MatrixCSR<Data>& mat) : MatrixCSR<Data>(mat.row, mat.col)
	{
		for (unsigned long i = 0; i < row; i++) {
			for (Node** ptr = mat.rowVec[i]; ptr != mat.rowVec[i + 1]; ptr = &((*ptr)->next)) {
				Node& node = **ptr;
				(*this)(i, node.element.second) = node.element.first;
			}
		}
	}

	/* Move Constructor */
	template<typename Data>
	MatrixCSR<Data>::MatrixCSR(MatrixCSR<Data>&& mat) noexcept : List<std::pair<Data, unsigned long>>(std::move(mat))
	{
		std::swap(row, mat.row);
		std::swap(col, mat.col);
		std::swap(rowVec, mat.rowVec);

		rowVec[0] = &head;

		for (unsigned long i = 0; i < mat.size && mat.rowVec[i] == &head; i++) {
			mat.rowVec[i] = &mat.head;
		}
	}

	/* Copy Assignment */
	template<typename Data>
	MatrixCSR<Data>& MatrixCSR<Data>::operator=(const MatrixCSR<Data>& mat)
	{
		row = mat.row;
		col = mat.col;
		rowVec.Resize(row + 1);
		for (unsigned long i = 0; i <= row; i++) {
			rowVec[i] = &head;
		}
		for (unsigned long i = 0; i < row; i++) {
			for (Node** ptr = mat.rowVec[i]; ptr != mat.rowVec[i + 1]; ptr = &((*ptr)->next)) {
				Node& node = **ptr;
				(*this)(i, node.element.second) = node.element.first;
			}
		}

		return *this;
	}

	/* Move Assignment */
	template<typename Data>
	MatrixCSR<Data>& MatrixCSR<Data>::operator=(MatrixCSR<Data>&& mat) noexcept
	{
		List<std::pair<Data, unsigned long>>::operator=(std::move(mat));
		std::swap(row, mat.row);
		std::swap(col, mat.col);
		std::swap(rowVec, mat.rowVec);
		
		for (unsigned long i = 0; i < size && rowVec[i] == &mat.head; i++) {
			rowVec[i] = &head;
		}

		for (unsigned long i = 0; i < mat.size && mat.rowVec[i] == &head; i++) {
			mat.rowVec[i] = &mat.head;
		}

		return *this;
	}
	
	/* Comparison operators */
	template <typename Data>
	bool MatrixCSR<Data>::operator==(const MatrixCSR<Data>& mat) const noexcept
	{
		if (size != mat.size) return false;
		if (row != mat.row) return false;
		if (col != mat.col) return false;
		unsigned long i = 0;
		Node** ptr = rowVec[i];
		Node** other_ptr = mat.rowVec[i];
		while (ptr != rowVec[row]) {
			if ((*ptr)->element.second != (*other_ptr)->element.second)
				return false;

			ptr = &((*ptr)->next);
			other_ptr = &((*other_ptr)->next);
			if (ptr == rowVec[i+1]) {
				i++;
				ptr = rowVec[i];
				other_ptr = mat.rowVec[i];
			}
			if (ptr == rowVec[row])
				return true;
		}
		return false;

	}

	template <typename Data>
	bool MatrixCSR<Data>::operator!=(const MatrixCSR<Data>& mat) const noexcept
	{
    	return !(*this == mat);
	}

	/* Row Resize */
	template<typename Data>
	void MatrixCSR<Data>::RowResize(const unsigned long newRowSize) noexcept
	{
		if (newRowSize == 0)
			Clear();
		else if (newRowSize < row) 
		{
			Node** ptr = rowVec[newRowSize];
			Node* current = *ptr;
			while (current != nullptr) {
				Node* temp = current->next;
				delete current;
				size--;
				current = temp;
			}
			*ptr = nullptr;
			rowVec[newRowSize] = ptr;
			rowVec.Resize(newRowSize + 1);

		} 
		else if (newRowSize > row) {
			rowVec.Resize(newRowSize + 1);
			for (unsigned long i = row; i <= newRowSize; i++) {
				rowVec[i] = rowVec[row];
			}
		}
    	row = newRowSize;
	}

	/* Column Resize */
	template<typename Data>
	void MatrixCSR<Data>::ColumnResize(const unsigned long newColSize) noexcept
	{
		if (newColSize == 0)
		{
			List<std::pair<Data, unsigned long>>::Clear();
		}
		else if (newColSize < col) {
			unsigned long i = 1;
			Node** ptr = &head;
			while (i <= row) {
				Node* node;
				Node** prox = rowVec[i];
				while (ptr != prox && (*ptr)->element.second < newColSize) {
					node = *ptr;
					ptr = &(node->next);
				}
				if (ptr != prox) {
					if (prox == rowVec[row]) {
						tail = node;
					} 
					Node* tmp = *ptr;
					*ptr = *prox;
					*prox = nullptr;

					Node* current = tmp;
					while (current != nullptr) {
						Node* temp = current->next;
						delete current;
						size--;
						current = temp;

					}
				}
				for (; i <= row && rowVec[i] == prox; i++) {
					rowVec[i] = ptr;
				}
			}
		}
		col = newColSize;
	}
	
	/* ExistsCell */
	template <typename Data>
	bool MatrixCSR<Data>::ExistsCell(const unsigned long r, const unsigned long c) const noexcept 
	{
		if ((r < row) && (c < col)) {
			Node** ptr = rowVec[r];
			while (ptr != rowVec[r + 1]) { // Fa un confronto tra il puntatore e la riga successiva. Se uguale, non esiste la riga, quindi nemmeno la cella.
				Node& node = **ptr;
				if (node.element.second == c) { // Controlla se il nodo è presente nella colonna 'c'.
					return true;
				}
				ptr = &(node.next);
			}
		}
		return false;
	}

	/* Operator () */
	template <typename Data>
	Data& MatrixCSR<Data>::operator()(const unsigned long r, const unsigned long c) 
	{
		if (r < row && c < col) {
			Node** ptr = rowVec[r];
			Node** prox = rowVec[r + 1];
			while (ptr != prox && (*ptr)->element.second <= c) { // Fa un confronto tra il puntatore e la riga successiva. Se uguale, non esiste la riga, quindi nemmeno la cella.
				Node& node = **ptr;
				if (node.element.second == c) { // Controlla se il nodo è presente nella colonna 'c'.	
					return node.element.first;
				}
				else
					ptr = &((*ptr)->next);
			}
			if (ptr == prox) { // Le righe sono uguali, quindi la riga non esiste e bisogna aggiungere.
				Node* tmp = new Node();
				tmp->element.second = c;
				tmp->next = *ptr;
				*ptr = tmp;
				for (unsigned long i = r+1; i <= row; i++) {
					if (rowVec[i] == prox)
						rowVec[i] = &((*ptr)->next);
					else
						break;
				}
				size++;
				return tmp->element.first;
			}
			else { 				
				Node* tmp = new Node();
				tmp->element.second = c;
				tmp->next = *ptr;
				*ptr = tmp;
				size++;
				return tmp->element.first;

			}
		}
		else
			throw std::out_of_range("There is no value with these coordinates!");
	}

	template <typename Data>
	const Data& MatrixCSR<Data>::operator()(const unsigned long r, const unsigned long c) const
	{
		if (r < row && c < col) {
			Node** ptr = rowVec[r];
			Node** prox = rowVec[r + 1];
			while (ptr != prox && (*ptr)->element.second <= c) { // Fa un confronto tra il puntatore e la riga successiva. Se uguale, non esiste la riga, quindi nemmeno la cella.
				Node& node = **ptr;
				if (node.element.second == c) { // Controlla se il nodo è presente nella colonna 'c'.	
					return node.element.first;
				}
				else
					ptr = &((*ptr)->next);
			}
		}
		else
			throw std::out_of_range("There is no value with these coordinates!");
	}

	/* Clear */
	template <typename Data>
	void MatrixCSR<Data>::Clear() 
	{
		List<std::pair<Data, unsigned long>>::Clear();
		row = 0;
		col = 0;
		rowVec.Resize(1);
		rowVec[0] = &head;
	}

	/* Map */
	template<typename Data>
	void MatrixCSR<Data>::MapPreOrder(const MapFunctor fun, void* par) 
	{
		List<std::pair<Data, unsigned long>>::MapPreOrder([&fun](std::pair<Data, unsigned long>& mdat, void* mpar) { fun(mdat.first, mpar); }, par);
	}

	template<typename Data>
	void MatrixCSR<Data>::MapPostOrder(const MapFunctor fun, void* par) 
	{	
		List<std::pair<Data, unsigned long>>::MapPostOrder([&fun](std::pair<Data, unsigned long>& mdat, void* mpar) { fun(mdat.first, mpar); }, par);
	}

	/* Fold */
	template<typename Data>
	void MatrixCSR<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc) const 
	{
		List<std::pair<Data, unsigned long>>::FoldPreOrder([&fun](const std::pair<Data, unsigned long>& mdat, const void* mpar, void* macc) { fun(mdat.first, mpar, macc); }, par, acc);
	}

	template<typename Data>
	void MatrixCSR<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc) const 
	{
		List<std::pair<Data, unsigned long>>::FoldPostOrder([&fun](const std::pair<Data, unsigned long>& mdat, const void* mpar, void* macc) { fun(mdat.first, mpar, macc); }, par, acc);
	}

	/* ************************************************************************** */

}
