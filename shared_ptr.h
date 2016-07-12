
class sp_counted_base
{
private:
    int use_count_;        // #shared
    int weak_count_;       // #weak + (#shared != 0)
	
public:
	sp_counted_base(): use_count_( 1 ), weak_count_( 1 )
    {
    }
	
}

struct shared_count
{
	sp_counted_base * pi_;
	
	shared_count(): pi_(0) // nothrow
	{
		
	}
}

template <class T>
struct shared_ptr
{
	shared_ptr(T* object) 
		: m_helper(object)
	{
	}
	
	shared_ptr(const shared_ptr<T>& other)
	{
		
	}
	
	shared_ptr<T> operator=(const shared_ptr<T>& other)
	{
		
	}
	
	T* get() { return px; }
private:
	
	element_type * px;                 // contained pointer
    shared_count pn;    // reference counter
}

struct SomeClass
{
	SomeClass(int i) { someValue = i; }
	void foo() { std::cout << "foo call" << std::endl; }
	int someValue;
}

main() 
{
	shared_ptr<SomeClass> ptr = new shared_ptr<SomeClass>(10);
	ptr->foo();
	
	shared_ptr<SomeClass> otherPtr(ptr);
	
}