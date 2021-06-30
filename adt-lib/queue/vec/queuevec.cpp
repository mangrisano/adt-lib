
namespace lasd {

/* ************************************************************************** */

    /* Default constructor */
    template<typename Data>
    QueueVec<Data>::QueueVec()
    {
        unsigned long newSize = 16;
        Elements = new Data[newSize] {};
        size = newSize;
        front = -1;
        rear = -1;
    }

    /* Destructor */
    template<typename Data>
    QueueVec<Data>::~QueueVec() 
    {
        Clear();
    }

    /* Specific constructor */
    template<typename Data>
    QueueVec<Data>::QueueVec(const LinearContainer<Data>& con) : Vector<Data>(con) 
    {
        rear = con.Size() - 1;
    }

    /* Copy constructor */
    template<typename Data>
    QueueVec<Data>::QueueVec(const QueueVec<Data>& queuevec) : Vector<Data>(queuevec) {
        front = queuevec.front;
        rear = queuevec.rear;
    }

    /* Move constructor */
    template<typename Data>
    QueueVec<Data>::QueueVec(QueueVec<Data>&& queuevec) noexcept: Vector<Data>(queuevec) 
    {
        std::swap(front, queuevec.front);
        std::swap(rear, queuevec.rear);
    }

    /* Copy assignment */
    template<typename Data>
    QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& queuevec) 
    {
        Vector<Data>::operator=(queuevec);
        front = queuevec.front;
        rear = queuevec.rear;
        return *this;
    }

    /* Move assignment */
    template<typename Data>
    QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& queuevec) noexcept 
    {
        Vector<Data>::operator=(queuevec);
        std::swap(front, queuevec.front);
        std::swap(rear, queuevec.rear);
        return *this;
    }


    /* Comparison operators */
    template<typename Data>
    bool QueueVec<Data>::operator==(const QueueVec<Data>& queuevec) const noexcept 
    {
        unsigned long size = Size();
		if (size == queuevec.Size()) {
			for(unsigned long index = 0; index < size; index++) {
				if (Elements[index] != queuevec.Elements[index]) {
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
    bool QueueVec<Data>::operator!=(const QueueVec<Data>& queuevec) const noexcept 
    {
        return Vector<Data>::operator!=(queuevec);
    }

    /* Enqueue */
    template<typename Data>
    void QueueVec<Data>::Enqueue(const Data& value) 
    {
        if (Empty()) {
            front = 0;
            rear = 0;
        } 
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        } 
        else {
            if (rear == size - 1 && front == 0) {
                Expand();
            }
            else if (rear == (front - 1)) {
                front = 0;
                rear = size - 1;
                Expand();
            }
            rear = (rear + 1) % size;
        }
        Elements[rear] = value;
    }

    /* Enqueue */
    template<typename Data>
    void QueueVec<Data>::Enqueue(Data&& value) noexcept 
    {
        if (Empty()) {
            front = 0;
            rear = 0;
        } 
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        } 
        else {
            if (rear == size - 1 && front == 0) {
                Expand();
            }
            else if (rear == (front - 1)) {
                front = 0;
                rear = size - 1;
                Expand();
            }
            rear = (rear + 1) % size;
        }
        Elements[rear] = value;
    }

    /* Head */
    template<typename Data>
    Data& QueueVec<Data>::Head() const 
    {
        if (Empty()) {
            throw std::length_error("The queue is empty!");
        }
        return Elements[front];
    }

    /* Dequeue */
    template<typename Data>
    void QueueVec<Data>::Dequeue() 
    {
        if (Empty()) {
            throw std::length_error("The queue is empty!");
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } 
        else if (front == size - 1) {
            front = 0;
        } 
        else {
            front = (front + 1) % size;
        }
        if (front > rear / 2) {
            Reduce();
            SwapVectors(size);
        }

    }

    /* HeadNDequeue */
    template<typename Data>
    Data QueueVec<Data>::HeadNDequeue() 
    {
        if (Empty()) {
            throw std::length_error("The queue is empty!");
        }
        Data tmp = Head();
        Dequeue();
        return tmp;
    }

    /* Empty */
    template<typename Data>
    bool QueueVec<Data>::Empty() const noexcept 
    {
        return (front == -1);
    }

    /* Size */
    template<typename Data>
    unsigned long QueueVec<Data>::Size() const noexcept 
    {
        if (rear == -1)
            return rear + 1;
        return (rear - front) + 1;
    }

    /* Clear */
    template<typename Data>
    void QueueVec<Data>::Clear() 
    {
        Vector<Data>::Clear();
        Vector<Data>::Resize(1);
        front = -1;
        rear = -1;
    }

    /* Expand */
    template<typename Data>
    void QueueVec<Data>::Expand() 
    {
        const unsigned short coeff = 2;
        const unsigned long newsize = size * coeff;
        Vector<Data>::Resize(newsize);
    }

    /* Reduce */
    template<typename Data>
    void QueueVec<Data>::Reduce() 
    {   
        const float coeff = 1.5;
        const unsigned long newsize = size / (2 * coeff);
        Vector<Data>::Resize(newsize);
    }

    /* Swap Vectors */
    template<typename Data>
    void QueueVec<Data>::SwapVectors(unsigned long newsize) noexcept 
    {
        Data* vector = new Data[newsize] {};
        unsigned long index = 0;
        while (front < rear+1) {
            std::swap(vector[index], Elements[front]);
            front += 1;
            index += 1;
        }
        std::swap(vector, Elements);
        delete[] vector;
        front = 0;
        rear = index - 1;
    }


    /* ************************************************************************** */

}
