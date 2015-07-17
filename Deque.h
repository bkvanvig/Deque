// --------------------------
// projects/c++/deque/Deque.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef Deque_h
#define Deque_h

// --------
// includes
// --------

#include <algorithm> // copy, equal, lexicographical_compare, max, swap
#include <iostream>  // cout, endls
#include <cassert>   // assert
#include <iterator>  // iterator, bidirectional_iterator_tag
#include <memory>    // allocator
#include <stdexcept> // out_of_range
#include <utility>   // !=, <=, >, >=

// -----
// using
// -----

using std::rel_ops::operator!=;
using std::rel_ops::operator<=;
using std::rel_ops::operator>;
using std::rel_ops::operator>=;


#define INNER_SIZE 100

// -------
// destroy
// -------

template <typename A, typename BI>
BI destroy (A& a, BI b, BI e) {
    while (b != e) {
        --e;
        a.destroy(&*e);}
    return b;}

// ------------------
// uninitialized_copy
// ------------------

template <typename A, typename II, typename BI>
BI uninitialized_copy (A& a, II b, II e, BI x) {
    BI p = x;
    try {
        while (b != e) {
            a.construct(&*x, *b);
            ++b;
            ++x;}}
    catch (...) {
        destroy(a, p, x);
        throw;}
    return x;}

// ------------------
// uninitialized_fill
// ------------------

template <typename A, typename BI, typename U>
BI uninitialized_fill (A& a, BI b, BI e, const U& v) {
    BI p = b;
    try {
        while (b != e) {
            a.construct(&*b, v);
            //std::cout << "v " << v << std::endl;
            ++b;}}
    catch (...) {
        destroy(a, p, b);
        throw;}
    return e;}

// -------
// my_deque
// -------

template < typename T, typename A = std::allocator<T> >
class my_deque {
    public:
        // --------
        // typedefs
        // --------

        typedef A                                        allocator_type;
        typedef typename allocator_type::value_type      value_type;

        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::difference_type difference_type;

        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;

        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::const_reference const_reference;


        typedef typename A::template rebind<pointer>::other      B;

    public:
        // -----------
        // operator ==
        // -----------

        /**
         * Compares two my_deques for equality
         * @param my_deque lhs
         * @param my_deque rhs
         * @return boolean 
         */
        friend bool operator == (const my_deque& lhs, const my_deque& rhs) {
            // <your code>
            // you must use std::equal()
            // The equals is calling the wrong begin & end
            //std::cout << lhs.size() << "    " << rhs.size() << std::endl;
            return (lhs.size() == rhs.size()) && std::equal(lhs.begin(), lhs.end(), rhs.begin());
            }

        // ----------
        // operator <
        // ----------

        /**
         * Compares two my_deques for less than operator
         * @param my_deque lhs
         * @param my_deque rhs
         * @return boolean if lhs < rhs
         */
        friend bool operator < (const my_deque& lhs, const my_deque& rhs) {
            // <your code>
            // you must use std::lexicographical_compare()
            //std::cout << lhs.size() << "    " << rhs.size() << std::endl;
            // if (lhs.size() > rhs.size())
            //     return std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
            return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
            }

    private:
        // ----
        // data
        // ----

        allocator_type _a;
        int OUTER_SIZE;

        B _balloc; 

        pointer* outer_b;
        pointer* outer_e;
        pointer _bstart;
        pointer _estart;
        pointer _b;
        pointer _e;
        pointer _l;

        int _size;
        int _offset;

        // <your data>

    private:
        // -----
        // valid
        // -----

        bool valid () const {
            // <your code>
            return true;
}

    public:
        // --------
        // iterator
        // --------

        class iterator {
            public:
                // --------
                // typedefs
                // --------

                typedef          std::bidirectional_iterator_tag iterator_category;
                typedef typename my_deque::value_type            value_type;
                typedef typename my_deque::difference_type       difference_type;
                typedef typename my_deque::pointer               pointer;
                typedef typename my_deque::reference             reference;

            public:
                // -----------
                // operator ==
                // -----------

                /**
                 * @param iterator lhs
                 * @param difference_type rhs
                 * @return true if lhs==rhs, false otherwise
                 */
                friend bool operator == (const iterator& lhs, const iterator& rhs) {
                    // <your code>
                    if ((lhs._index == rhs._index))
                    {
                        return true;
                    }
                    return false;}

                /**
                 * @param iterator lhs
                 * @param difference_type rhs
                 * @return true if lhs!=rhs, false otherwise
                 */
                friend bool operator != (const iterator& lhs, const iterator& rhs) {
                    return !(lhs == rhs);}

                // ----------
                // operator +
                // ----------

                /**
                 * @param iterator lhs
                 * @param difference_type rhs
                 * @return iterator lhs+rhs
                 */
                friend iterator operator + (iterator lhs, difference_type rhs) {
                    return lhs += rhs;}

                // ----------
                // operator -
                // ----------

                /**
                 * @param iterator lhs
                 * @param difference_type rhs
                 * @return iterator lhs-rhs
                 */
                friend iterator operator - (iterator lhs, difference_type rhs) {
                    return lhs -= rhs;}

            private:
                // ----
                // data
                // ----

                // <your data>
                my_deque* _d;
                size_type _index;

            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    // <your code>
                    if (_index >= 0)
                        return true;
                    return false;
            }

            public:
                // -----------
                // constructor
                // -----------

                /**
                 * iterator constructor
                 * @param my_deque* d
                 * @param size_type s
                 * @return iterator pointing to my_deque d at position s
                 */
                iterator (my_deque* d, size_type s) :

                    _d (d),
                    _index (s){
                    // <your code>
                    assert(valid());}

                // Default copy, destructor, and copy assignment.
                // iterator (const iterator&);
                // ~iterator ();
                // iterator& operator = (const iterator&);

                // ----------
                // operator *
                // ----------

                /**
                 * @return reference at _d[_index]
                 */
                reference operator * () const {
                    // <your code>
                    
                    return (*_d)[_index];}

                // -----------
                // operator ->
                // -----------

                /**
                 * @return pointer to this object which can be dereferenced as an rvalue
                 */
                pointer operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
                 * prefix ++ 
                 * @return iterator incremented
                 */
                iterator& operator ++ () {
                    // <your code>
                    ++_index;
                    assert(valid());
                    return *this;}

                /**
                 * postfix ++
                 * @param int
                 * @return iterator pointing to original value with internal value decremented
                 */
                iterator operator ++ (int) {
                    iterator x = *this;
                    ++(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator --
                // -----------

                /**
                 * prefix --
                 * @return iterator decremented
                 */
                iterator& operator -- () {
                    // <your code>
                    --_index;
                    assert(valid());
                    return *this;}

                /**
                 * postfix --
                 * @param int
                 * @return iterator pointing to original value with internal value decremented
                 */
                iterator operator -- (int) {
                    iterator x = *this;
                    --(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator +=
                // -----------

                /**
                 * @param difference_type d
                 * @return iterator to current position + d
                 */
                iterator& operator += (difference_type d) {
                    // <your code>
                    _index += d;
                    assert(valid());
                    return *this;}

                // -----------
                // operator -=
                // -----------

                /**
                 * @param difference_type d
                 * @return iterator to current position - d
                 */
                iterator& operator -= (difference_type d) {
                    // <your code>
                    _index -= d;
                    assert(valid());
                    return *this;}};

    public:
        // --------------
        // const_iterator
        // --------------

        class const_iterator {
            public:
                // --------
                // typedefs
                // --------

                typedef          std::bidirectional_iterator_tag iterator_category;
                typedef typename my_deque::value_type            value_type;
                typedef typename my_deque::difference_type       difference_type;
                typedef typename my_deque::const_pointer         pointer;
                typedef typename my_deque::const_reference       reference;

            public:
                // -----------
                // operator ==
                // -----------

                /**
                 * @param const_iterator lhs
                 * @param difference_type rhs
                 * @return true if lhs == rhs, false otherwise
                 */
                friend bool operator == (const const_iterator& lhs, const const_iterator& rhs) {
                    // <your code>
                    if (lhs._cindex == rhs._cindex){
                        return true;
                    }
                    return false;
                }

                /**
                 * @param const_iterator lhs
                 * @param difference_type rhs
                 * @return true if lhs != rhs, false otherwise
                 */
                friend bool operator != (const const_iterator& lhs, const const_iterator& rhs) {
                    return !(lhs == rhs);}

                // ----------
                // operator +
                // ----------

                /**
                 * @param const_iterator lhs
                 * @param difference_type rhs
                 * @return lhs._cindex + rhs
                 */
                friend const_iterator operator + (const_iterator lhs, difference_type rhs) {
                    return lhs += rhs;}

                // ----------
                // operator -
                // ----------

                /**
                 * @param const_iterator lhs
                 * @param difference_type rhs
                 * @return lhs._cindex - rhs
                 */
                friend const_iterator operator - (const_iterator lhs, difference_type rhs) {
                    return lhs -= rhs;}

            private:
                // ----
                // data
                // ----

                // <your data>
                const my_deque* _cd;
                size_type _cindex;

            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    // <your code>
                    if (_cindex >= 0)
                        return true;
                    return false;
            }

            public:
                // -----------
                // constructor
                // -----------

                /**
                 * const_iterator constructor
                 * @param const my_deque d
                 * @param size_type s, index iterator will point to within d
                 * @return const_iterator pointing to const my_deque d at position s
                 */
                const_iterator (const my_deque* d, size_type s)  :

                    _cd (d),
                    _cindex (s){
                    // <your code>
                    assert(valid());}

                // Default copy, destructor, and copy assignment.
                // const_iterator (const const_iterator&);
                // ~const_iterator ();
                // const_iterator& operator = (const const_iterator&);

                // ----------
                // operator *
                // ----------

                /**
                 * @return reference, element at _cindex of _cd
                 */
                reference operator * () const {
                    // <your code>
                    // dummy is just to be able to compile the skeleton, remove it
                    return (*_cd)[_cindex];}

                // -----------
                // operator ->
                // -----------

                /**
                 * @return pointer to this object which can be dereferenced as an rvalue
                 */
                pointer operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
                 * Pre-fix ++
                 * @return const_iterator with updated _cindex value
                 */
                const_iterator& operator ++ () {
                    // <your code>
                    ++_cindex;
                    assert(valid());
                    return *this;}

                /**
                 * Post-fix ++
                 * @param int
                 * @return const_iterator this with previous value, but updates _cindex internally
                 */
                const_iterator operator ++ (int) {
                    const_iterator x = *this;
                    ++(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator --
                // -----------

                /**
                 * Pre-fix --
                 * @return const_iterator this, with updated _cindex value
                 */
                const_iterator& operator -- () {
                    // <your code>
                    --_cindex;
                    assert(valid());
                    return *this;}

                /**
                 * Post-fix --
                 * @param int
                 * @return const_iterator this with previous value, but updates _cindex internally
                 */
                const_iterator operator -- (int) {
                    const_iterator x = *this;
                    --(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator +=
                // -----------

                /**
                 * @param difference_type d, the value to be added from const_iterator
                 * @return const_iterator this, with updated _cindex value
                 */
                const_iterator& operator += (difference_type d) {
                    // <your code>
                    _cindex+= d;
                    assert(valid());
                    return *this;}

                // -----------
                // operator -=
                // -----------

                /**
                 * @param difference_type d, the value to be subtracted from const_iterator
                 * @return const_iterator this, with updated _cindex value
                 */
                const_iterator& operator -= (difference_type d) {
                    // <your code>
                    _cindex-=d;
                    assert(valid());
                    return *this;}};

    public:
        // ------------
        // constructors
        // ------------

        /**
         * my_deque constructor
         * @param allocator_type a, optional specification of an allocator for specific types of elements
         * @return my_deque, empty
         */
        explicit my_deque (const allocator_type& a = allocator_type()) :

                 _a (a) {
                    _b = 0;
                    _e = 0;
                    OUTER_SIZE = 1;
                    outer_b = _balloc.allocate(OUTER_SIZE);
                    outer_e = outer_b+OUTER_SIZE;
                    outer_b[0] = _a.allocate(INNER_SIZE);
                    _size = 0;
                    _bstart = 0;
                    _estart = 0;
                    int begin_index = (capacity() - size()) / 2;
                    int end_index = (capacity() + size()) / 2;
                    int outerbegin = begin_index/INNER_SIZE;
                    int outerend = end_index/INNER_SIZE;
                    // _bstart = outerbegin;
                    // _estart = outerend;
                    _b = &outer_b[outerbegin][begin_index];
                    _e = &outer_b[outerend][end_index];
                    _offset = begin_index;
                    
            assert(valid());}

        /**
         * my_deque constructor
         * @param size_type s, the size of my_deque
         * @param const_reference v, an optional value to be written in each index
         * @return my_deque containing size s, and optional value v
         */
        explicit my_deque (size_type s, const_reference v = value_type(), const allocator_type& a = allocator_type()) :

            _a (a) {

            OUTER_SIZE = 1;
            outer_b = _balloc.allocate(OUTER_SIZE*sizeof(pointer));
            outer_e = outer_b+OUTER_SIZE;
            outer_b[0] = _a.allocate(INNER_SIZE);
            _size = 0;  

            // _bstart = 0;
            // _estart = 0;
            _offset = 0;
            _b = 0;
            _e = 0;

            // std::cout<<"begin " << *begin() << std::endl;
            // std::cout<<"end " << *end() << std::endl;

            // std::cout<<"_b " << *_b << std::endl;
            // std::cout<<"_e " << *_e << std::endl;
            //Need something to handle s being bigger than 100 (aka INNER_SIZE)

            //std::cout << "intial size" << s << std::endl;

            while (s >= capacity()){
                 //std::cout << "intial capacity" << capacity() << std::endl;
                resize(3*capacity());

            }

            

            //std::cout << "out of while loop" << std::endl;
            _size = s;  //move below resize calls to avoid issues when resizing

            //std::cout<< "s " << size() << std::endl;
            //std::cout <<"edn" << *end() << std::endl;

            //Set _b & _e
            int begin_index = (capacity() - size()) / 2;
            int end_index = (capacity() + size()) / 2;

            _offset = begin_index;

            //std::cout<<"begin_index " << begin_index << std::endl;
            //std::cout<<"end_index " << end_index << std::endl;

            int outerbegin = begin_index/INNER_SIZE;
            int outerend = end_index/INNER_SIZE;
            // _bstart = outerbegin;
            // _estart = outerend;

            //std::cout<<"outerbegin " << outerbegin << std::endl;
            //std::cout<<"outerend " << outerend << std::endl;

            _b = &outer_b[outerbegin][begin_index];
           // std::cout<<"_b " << *_b << std::endl;
            _e = &outer_b[outerend][end_index];

            
            
            
            //std::cout<<"_e " << *_e << std::endl;

           // std::cout<<"offset " << _offset << std::endl;

           // std::cout<<"begin " << *begin() << std::endl;
           // std::cout<<"end " << *end() << std::endl;

            uninitialized_fill(_a, begin(), end(), v);
            //std::cout << "after fill" << std::endl;
            assert(valid());}

        /**
         * my_deque constructor
         * @param my_deque that, the object to be assigned to *this
         * @return my_deque containing a copy of that
         */
        my_deque (const my_deque& that) : 

            _a (that._a) {

            OUTER_SIZE = that.OUTER_SIZE;

            //std::cout << "outersize " << OUTER_SIZE << std::endl;
            outer_b = _balloc.allocate(OUTER_SIZE);
            for (int i = 0; i < OUTER_SIZE; ++i)
            {
                outer_b[i] = _a.allocate(INNER_SIZE);
            }
            _size = that.size();

            //std::cout<< "s " << size() << std::endl;
            //std::cout <<"edn" << *end() << std::endl;

            //Set _b & _e
            int begin_index = (capacity() - size()) / 2;
            int end_index = (capacity() + size()) / 2;

            _offset = begin_index;

            //std::cout<<"begin_index " << begin_index << std::endl;
            //std::cout<<"end_index " << end_index << std::endl;

            int outerbegin = begin_index/INNER_SIZE;
            int outerend = end_index/INNER_SIZE;
            // _bstart = outerbegin;
            // _estart = outerend;

            //std::cout<<"outerbegin " << outerbegin << std::endl;
            //std::cout<<"outerend " << outerend << std::endl;

            _b = &outer_b[outerbegin][begin_index];
            //std::cout<<"_b " << *_b << std::endl;
            _e = &outer_b[outerend][end_index];

            
            //std::cout<<"_e " << *_e << std::endl;
            

            //std::cout<<"offset " << _offset << std::endl;

            //std::cout<<"begin " << *begin() << std::endl;
            //std::cout<<"end " << *end() << std::endl;




            uninitialized_copy(_a, that.begin(), that.end(), begin());
            assert(valid());
        }

        // ----------
        // destructor
        // ----------

        /**
         * Destroys the my_deque element 
         */
        ~my_deque () {
    
            for (int i = 0; i < OUTER_SIZE; ++i)
            {
                /* code */
                _a.deallocate(outer_b[i], INNER_SIZE);
            }
            _balloc.deallocate(outer_b, OUTER_SIZE);
            assert(valid());}

        // ----------
        // operator =
        // ----------

        /**
         * Assigns rhs to *this
         * @param my_deque& rhs
         * @return my_deque *this, which was previously my_deque rhs
         */
        my_deque& operator = (const my_deque& rhs) {
            // <your code>
            //*this = my_deque(rhs);
            if (*this == rhs)
                return *this;
            if (rhs.size() == size())
                std::copy(rhs.begin(), rhs.end(), begin());
            else if (rhs.size() < size()) {
                std::copy(rhs.begin(), rhs.end(), begin());
                _size = rhs.size();}
            else if (rhs.size() <= capacity()) {
                std::copy(rhs.begin(), rhs.begin() + size(), begin());
                _e = &*uninitialized_copy(_a, rhs.begin() + size(), rhs.end(), end());}
            else {
                clear();
                reserve(rhs.size());
                _e = &*uninitialized_copy(_a, rhs.begin(), rhs.end(), begin());}
            assert(valid());
            return *this;
}

        // -----------
        // operator []
        // -----------

        /**
         * @param size_type index, the index requested
         * @return the reference to that index
         */
         reference operator [] (size_type index) {
            // This needs to be capacity - beginning padding
            //std::cout << "capacity " << capacity() << std::endl;
            if (index > (_size) || (index < 0))
                throw std::out_of_range("Deque: []");

            // Do mod & division to find index, from _b index
            int outer_b_index = (index + _offset )/INNER_SIZE;

            
            int inner_index = (index + _offset)%INNER_SIZE;
            

            return outer_b[outer_b_index][inner_index];
        }

        /**
         * @param size_type index, the index requested
         * @return the const_reference to that index
         */
         
         const_reference operator [] (size_type index) const {
            if (index > (_size ) || (index < 0))
                throw std::out_of_range("Deque: const []");
             return const_cast<my_deque&>(*this)[index];}

        // --
        // at
        // --

        /**
         * @param size_type index, the index requested
         * @return the reference to that index
         */
        reference at (size_type index) {
            if (index >= (capacity()- _offset))
                throw std::out_of_range("Deque: at");
            return *(begin()+index);}

        /**
         * @param size_type index, the index requested
         * @return the const_reference to that index
         */
        const_reference at (size_type index) const {
            return const_cast<my_deque*>(this)->at(index);}

        // ----
        // back
        // ----

        /**
         * @return reference, the last element of my_deque
         */
        reference back () {
            assert(!empty());
            return *(end() - 1);}

        /**
         * @return const_reference, the last element of my_deque
         */
        const_reference back () const {
            return const_cast<my_deque*>(this)->back();}

        // -----
        // begin
        // -----

        /**
         * @return iterator to begining of my_deque
         */
        iterator begin () {
            return iterator(this, 0);
        }

        /**
         * @return const_iterator to beginning of my_deque
         */
        const_iterator begin () const {
            // <your code>
            return const_iterator(this,0 );}



        //----------
        // capacity
        // ---------

        /**
         * @return the full capacity of my_deque
         */

        size_type capacity () const {
            //std::cout << "capacity " << INNER_SIZE*OUTER_SIZE << std::endl;
            return INNER_SIZE*OUTER_SIZE;}

        // -----
        // clear
        // -----

        /**
         * Removes all elements of my_deque
         * Does not deallocate pointer to my_deque
         */
        void clear () {
            resize(0);
            assert(valid());}

        // -----
        // empty
        // -----

        /**
         * @return true if size is 0, aka my_deque is empty
         */
        bool empty () const {
            return !size();}

        // ---
        // end
        // ---

        /**
         * @return iterator to end of my_deque
         */
        iterator end () {
            // <your code>
            return iterator(this, _size );}

        /**
         * @return const_iterator to end of my_deque
         */ 
        const_iterator end () const {
            // <your code>
            return const_iterator(this, _size );}

        // -----
        // erase
        // -----

        /**
         * @param iterator it, the position of element to be removed
         * @return iterator to current position of updated element
         */
        iterator erase (iterator it) {
            // <your code>
            auto curr = it;
            auto next = ++it;
            auto end = iterator(this, _size);
            while(next != end){
                *curr = *next;
                ++next;
                ++curr;
            }
            pop_back();
            assert(valid());
            return curr;}

        // -----
        // front
        // -----

        /**
         * @return refrence of the beginning of my_deque
         */
        reference front () {
            assert(!empty());
            return *begin();}

        /**
         * @return const_reference of the beginning of my_deque
         */
        const_reference front () const {
            return const_cast<my_deque*>(this)->front();}

        // ------
        // insert
        // ------

        /**
         * @param iterator it, the position
         * @param const_reference v, reference to be inserted
         * @return iterator to new element
         */
        iterator insert (iterator it, const_reference val) {
            // <your code>
            auto curr = it;
            auto next = ++it;
            auto end = iterator(this, _size);
            auto tmp = *it;
            while(next != end){
                tmp = *next;
                *next = *curr;
                ++next;
                ++curr;
            }
            push_back(tmp);
            --it;
            *it = val;
            assert(valid());


            return it;
}

        // ---
        // pop
        // ---

        /**
         * Removes last element of my_deque
         */
        void pop_back () {
            assert(!empty());
            //resize(size() - 1);
            --_e;
            --_size;
            assert(valid());}

        /**
         * Removes the first element of my_deque
         */
        void pop_front () {
            // <your code>
            ++_offset;
            --_b;
            --_size;
            assert(valid());}

        // ----
        // push
        // ----

        /**
         * @param const_reference v, a reference to be added to the back of deque
         */
        void push_back (const_reference v) {
            if (_size+_offset < capacity()){
                ++_size;
                *_e = v;
               // std::cout << "pushed value: " << v << std::endl;
                ++_e;
            }
            else{
                resize(_size+_offset);
            }


            assert(valid());}

        /**
         * @param const_reference v, a reference to be added to the front of deque
         */
        void push_front (const_reference v) {
            // <your code>
            if (_size < capacity()){
                ++_size;
                --_b;
                --_offset;
                *_b = v;
            }
            assert(valid());}

        // ------
        // resize
        // ------

        /**
         * @param size_type s
         * @param const_reference v, an optional value to be written, which we do not utilize
         */
        void resize (size_type s, const_reference v = value_type()) {
            //std::cout << size() << std::endl;
            //std::cout << s << std::endl;
            //std::cout << capacity() << std::endl;
            // if (s == size())
            //     return;
            if (s < size()){
                _e = &*destroy(_a, begin() + s, end());
                _size = s;
            }
                
            else if (s < capacity()){
                _size = s;
                int begin_index = (capacity() - size()) / 2;
                int end_index = (capacity() + size()) / 2;

                _offset = begin_index;

                //std::cout<<"begin_index " << begin_index << std::endl;
                //std::cout<<"end_index " << end_index << std::endl;

                int outerbegin = begin_index/INNER_SIZE;
                int outerend = end_index/INNER_SIZE;
                // _bstart = outerbegin;
                // _estart = outerend;

                //std::cout<<"outerbegin " << outerbegin << std::endl;
                //std::cout<<"outerend " << outerend << std::endl;

                _b = &outer_b[outerbegin][begin_index];
                //std::cout<<"_b " << *_b << std::endl;
                _e = &outer_b[outerend][end_index];
                return;
                // std::cout<<"dfsfsd" <<std::endl;                
                // std::cout<<"begin" << *begin() << std::endl;
                // std::cout <<"edn" << *end() << std::endl;

                // //_e = &*uninitialized_fill(_a, end(), begin() + s, v);
                // std::cout<<"dfsfsd" <<std::endl;                
            }
            else {
                //std::cout << "else reserve" << std::endl;
                reserve(std::max(2 * size(), s));
                //resize(s, v);
            }
            assert(valid());}

        //-----------
        // reserve
        // ---------

        /** 
         * Allocates new space for resize method
         * @param size_type c
         */
         void reserve (size_type c) {
            //std::cout << "reserve" << std::endl;
            pointer* tmp = _balloc.allocate(OUTER_SIZE*3*sizeof(pointer));
            for(int i = 0; i < OUTER_SIZE; ++i){
                tmp[OUTER_SIZE+i] = outer_b[i];
            }

            // _bstart = ((_bstart - *outer_b) + OUTER_SIZE);
            // _estart = ((_estart - *outer_b) + OUTER_SIZE);

            _balloc.deallocate(outer_b, OUTER_SIZE);

            outer_b = tmp;

            OUTER_SIZE*=3;

            for (int i = 0; i < OUTER_SIZE; ++i)
            {
                if ((i >= OUTER_SIZE/3) && (i < 2*OUTER_SIZE/3)){
                    continue;
                }
                outer_b[i] = _a.allocate(INNER_SIZE);
            }
            outer_e = outer_b+OUTER_SIZE;
            
            assert(valid());}

        // ----
        // size
        // ----

        /**
         * @return the size of my_deque object
         */
        size_type size () const {
            // <your code>
            //std::cout << "size "<< _size << std::endl;
            return _size;}

        // ----
        // swap
        // ----

        /**
         * Assigns all elements rhs to lhs and vice versa
         * @param my_deque rhs
         */
        void swap (my_deque& rhs) {
            // <your code>
            my_deque tmp(*this);
            *this = rhs;
            rhs = tmp;
            assert(valid());}


            };

#endif // Deque_h
