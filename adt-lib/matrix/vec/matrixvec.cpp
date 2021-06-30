
namespace lasd {

	/* ************************************************************************** */

	/* Specific Constructor */
	template<typename Data>
	MatrixVec<Data>::MatrixVec(unsigned long r, unsigned long c)
	{
		Elements = new Data[r * c] {};
		row = r;
		col = c;
		size = r * c;
	}

	/* Copy Constructor */
	template<typename Data>
	MatrixVec<Data>::MatrixVec(const MatrixVec<Data>& matvec) : Vector<Data>(matvec)
	{
		row = matvec.row;
		col = matvec.col;
	}

	/* Move Constructor */
	template<typename Data>
	MatrixVec<Data>::MatrixVec(MatrixVec<Data>&& matvec) noexcept : Vector<Data>(std::move(matvec))
	{
		std::swap(row, matvec.row);
		std::swap(col, matvec.col);
	}

	/* Destructor */
	template<typename Data>
	MatrixVec<Data>::~MatrixVec()
	{
		Clear();
	}

	/* Copy Assignment */
	template<typename Data>
	MatrixVec<Data>& MatrixVec<Data>::operator=(const MatrixVec<Data>& matvec)
	{
		Vector<Data>::operator=(matvec);
		row = matvec.row;
		col = matvec.col;
		return *this;
	}

	/* Move Assignment */
	template<typename Data>
	MatrixVec<Data>& MatrixVec<Data>::operator=(MatrixVec<Data>&& matvec) noexcept
	{
		Vector<Data>::operator=(std::move(matvec));
		std::swap(row, matvec.row);
		std::swap(col, matvec.col);
		return *this;
	}

	/* Comparison Operators */
	template<typename Data>
	bool MatrixVec<Data>::operator==(const MatrixVec<Data>& matvec) const noexcept
	{
		if (size != matvec.size) return false;
		if (row != matvec.row) return false;
		if (col != matvec.col) return false;

		return Vector<Data>::operator==(matvec);
	}

	template<typename Data>
	bool MatrixVec<Data>::operator!=(const MatrixVec<Data>& matvec) const noexcept
	{
		return !(*this == matvec);
	}

	template<typename Data>
	void MatrixVec<Data>::RowResize(const unsigned long newRowSize) noexcept
	{
		if (newRowSize == 0)
			Clear();
		else {
			if (col == 0)
				col = 1;
			Vector<Data>::Resize(newRowSize * col);
			row = newRowSize;
			size = row * col;
		}
	}

	template<typename Data>
	void MatrixVec<Data>::ColumnResize(const unsigned long newColSize) noexcept
	{
		unsigned long i = 0;
		unsigned long j = 0;
		unsigned long newSize = 0;
		unsigned long newSizeCol = 0;

		if (newColSize == 0)
			Clear();
		else {	
			newSize = row * newColSize;
			newSizeCol = (newColSize < col) ? newColSize : col;
			Data* tmpvec = new Data[newSize] {};
			if (newColSize != col) {
				while (i < row) {
					j = 0;
					while (j < newSizeCol) {
						std::swap(tmpvec[(i * newColSize) + j], Elements[(i * col) + j]);
						j++;
					}
					i++;
				}
			}
			std::swap(Elements, tmpvec);
			col = newColSize;
			size = newSize;
			delete[] tmpvec;
		}
	}

	template<typename Data>
	bool MatrixVec<Data>::ExistsCell(const unsigned long r, const unsigned long c) const noexcept
	{
		return (r < row && c < col);
	}

	template<typename Data>
	Data& MatrixVec<Data>::operator()(const unsigned long r, const unsigned long c)
	{
		return const_cast<Data&>(static_cast<const MatrixVec<Data>*>(this)->operator()(r, c));
	}

	template<typename Data>
	const Data& MatrixVec<Data>::operator()(const unsigned long r, const unsigned long c) const
	{
		if (ExistsCell(r, c))
			return Elements[(r * col) + c];
		else
			throw std::out_of_range("There is no value with these coordinates!");
	}

	template<typename Data>
	void MatrixVec<Data>::Clear()
	{
		if (size != 0) {
			Vector<Data>::Clear();
			row = 0;
			col = 0;
		}
	}

/* ************************************************************************** */

}
