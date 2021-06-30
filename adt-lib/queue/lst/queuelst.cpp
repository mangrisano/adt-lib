
namespace lasd {

/* ************************************************************************** */

    /* Destructor */
    template<typename Data>
    QueueLst<Data>::~QueueLst()
    {
        Clear();
    }

    /* Specific constructor */
    template<typename Data>
    QueueLst<Data>::QueueLst(const LinearContainer<Data>& con) : List<Data>(con) {}

    /* Copy constructor */
    template<typename Data>
    QueueLst<Data>::QueueLst(const QueueLst<Data>& queuelst) : List<Data>(queuelst) {}

    /* Copy assignment */
    template<typename Data>
    QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst<Data>& queuelst)
    {
        List<Data>::operator=(queuelst);
        return *this;
    }

    /* Move constructor */
    template<typename Data>
    QueueLst<Data>::QueueLst(QueueLst<Data>&& queuelst) noexcept : List<Data>(std::move(queuelst)) {}

    /* Move assignment */
    template<typename Data>
    QueueLst<Data>& QueueLst<Data>::operator=(QueueLst<Data>&& queuelst) noexcept
    {
        List<Data>::operator=(std::move(queuelst));
        return *this;
    }

    /* Comparison operators */
    template<typename Data>
    bool QueueLst<Data>::operator==(const QueueLst<Data>& queuelst) const noexcept
    {
        return List<Data>::operator==(queuelst);
    }

    template<typename Data>
    bool QueueLst<Data>::operator!=(const QueueLst<Data>& queuelst) const noexcept
    {
        return List<Data>::operator!=(queuelst);
    }

    /* Enqueue */
    template<typename Data>
    void QueueLst<Data>::Enqueue(const Data& value)
    {
        List<Data>::InsertAtBack(value);
    }

    template<typename Data>
    void QueueLst<Data>::Enqueue(Data&& value)
    {
        List<Data>::InsertAtBack(value);
    }

    /* Head */
    template<typename Data>
    Data& QueueLst<Data>::Head() const
    {
        return List<Data>::Front();
    }

    /* Dequeue */
    template<typename Data>
    void QueueLst<Data>::Dequeue() 
    {
        List<Data>::RemoveFromFront();
    }

    /* HeadNDequeue */
    template<typename Data>
    Data QueueLst<Data>::HeadNDequeue()
    {
        return List<Data>::FrontNRemove();
    }

    /* Clear */
    template<typename Data>
    void QueueLst<Data>::Clear()
    {
        List<Data>::Clear();
    }
/* ************************************************************************** */

}
