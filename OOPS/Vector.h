#pragma once
// vector elements are heap allocated -> dynamic memory allocation

template<typename T>
class Vector
{
public:
    Vector() {
        // allocate memory for 2 elements even when nothing is pushed as of now.
        ReAlloc(2);
    }

    Vector(size_t size) {
        ReAlloc(size);
        m_Size = size;
    }

    Vector(const Vector& v) {
        ReAlloc(v.Size());
        m_Size = v.Size();
        for(size_t i = 0; i < v.Size(); ++i) {
            m_Data[i] = v[i];
        }
    }

    void PushBack(const T& value) {
        if(m_Size >= m_Capacity) {
            ReAlloc(m_Capacity * 1.5);
        }
        m_Data[m_Size++] = value;
    }

    void PopBack() {
        if(m_Size > 0) {
            m_Size--;
            m_Data[m_Size].~T();    // explicitly call the destructor of T datatype(had it been some non-primitive datatype)
        }
    }

    void Clear() {
        for(size_t i = 0; i < m_Size; i++) {
            m_Data[i].~T();
        }
        m_Size = 0;
    }

    const size_t Size() const {     // must keep the latter const. Because when v.Size() is called for some (const Vector<T> &v) then the compiler must know that calling v.Size() does not changes the Vector v.
        return m_Size;
    }

    // const version
    const T& operator[](size_t index) const {
        if(index >= m_Size) {
            // assert
            // exit(0);
        }
        return m_Data[index];
    }

    // non-const version
    T& operator[](size_t index) {
        if(index >= m_Size) {
            // assert
            // exit(0);
        }
        return m_Data[index];
    }
private:
    void ReAlloc(size_t newCapacity) {
        // 1. Allocate a new block of memory of given size
        // 2. copy/move elements from old block to new
        // 3. delete old block

        T* newBlock = new T[newCapacity];

        // if the size shrinks than its normal size, i.e when elements are popped
        if(newCapacity < m_Size) {
            m_Size = newCapacity;       // m_Size changes
        }

        for(size_t i = 0; i < m_Size; i++) {
            newBlock[i] = m_Data[i];
        }
        // don't use memcpy for the simple fact that we need to call the constructors for all the elements, had the elements themselves been some class(datatype).
        delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }

private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};