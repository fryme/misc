
template <class T>
struct shared_count
{
	shared_count(T* p) : ptr(p), use_count(1), weak_count(1)
	{
	}
	
	void release()
	{
		if (--use_count == 0)
		{
			destroy();
		}
	}

	void add_ref()
	{
		use_count++;
	}

	void destroy()
	{
		delete ptr;
	}

	void swap(shared_count* other)
	{
		std::swap(this->use_count, other->use_count);
		std::swap(this->weak_count, other->weak_count);
		std::swap(this->ptr, other->ptr);
	}

	int use_count;        // #shared 
	int weak_count;       // #weak + (#shared != 0)
	T* ptr;
};

template <class T>
struct shared_ptr
{
	explicit shared_ptr(T* p) : ptr(p), counter(p)
	{
	}
	/*
	shared_ptr(shared_ptr p)
	{

	}
	*/

	explicit shared_ptr(shared_ptr& p)
	{
		this->swap(p);
	}
	
	~shared_ptr()
	{
		counter.release();
	}

	shared_ptr& operator=(shared_ptr const& other)
	{
		other.swap(*this);
		return *this;
	}
	
	void swap(shared_ptr& other)
	{
		std::swap(this->ptr, other.ptr);
		counter.swap(other.counter);
	}

	T* operator-> () const
	{
		// BOOST_ASSERT(px != 0);
		return ptr;
	}
	
	T* get() 
	{ 
		return ptr;
	}

private:
	
	T* ptr;						// contained pointer
    shared_count<T> counter;	// reference counter
};

/*
template<class T, class... Args>
shared_ptr<T> make_shared(Args && ... args)
{
	shared_ptr<T> ptr(;
}
*/