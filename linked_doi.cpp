template <class _Ti> class LinkedList
{
protected:
    class baseList
    {
    public:
        baseList *next, *prev;
        baseList()
        {
            next = prev = this;
        }

        void insertAfter(baseList *p);
        void remove();

        void makeEmpty();

    };

    class infoList : public baseList
    {
    public:
        _Ti info;
        infoList(const _Ti& i) : info(i) { }
        _Ti * Info()
        {
            return &info;
        }
    };

    baseList h;
    int n;

public:
    LinkedList() : n(0) { }
    ~LinkedList()
    {
        h.makeEmpty();
    }

public:
    int IsEmpty()
    {
        return n == 0;
    }
    int Count()
    {
        return n;
    }

public:
    void RemoveAll()
    {
        h.makeEmpty();
        n = 0;
    }
    _Ti PopBegin()
    {
        baseList * p = h.next;
        _Ti i = ((infoList *)p)->info;
        p->remove();
        delete p;
        n--;
        return i;
    }

    _Ti PopEnd()
    {
        baseList *p = h.prev;
        _Ti i = ((infoList *)p)->info;
        p->remove();
        delete p;
        n--;
        return i;
    }

public:
    void PushBegin(const _Ti& i)
    {
        h.insertAfter(new infoList(i));
        n++;
    }

    void PushEnd(const _Ti& i)
    {
        h.Prev()->insertAfter(new infoList(i));
        n++;
    }
};

template <class _Ti>
void LinkedList<_Ti>::baseList::insertAfter(baseList * p)
{
    p->next = next;
    p->prev = this;

    next->prev = p;
    next = p;
}

template <class _Ti>
void LinkedList<_Ti>::baseList::remove()
{
    next->prev = prev;
    prev->next = next;
}

template <class _Ti>
void LinkedList<_Ti>::baseList::makeEmpty()
{
    baseList *p;
    while ((p = next) != this)
    {
        next = p->next;
        delete p;
    }
    prev = this;
}
