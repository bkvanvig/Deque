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
#include <iostream>
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
         * <your documentation>
         */
        friend bool operator == (const my_deque& lhs, const my_deque& rhs) {
            // <your code>
            // you must use std::equal()
            //std::cout << lhs.size() << "    " << rhs.size() << std::endl;
            return (lhs.size() == rhs.size()) && std::equal(lhs.begin(), lhs.end(), rhs.begin());
            }

        // ----------
        // operator <
        // ----------

        /**
         * <your documentation>
         */
        friend bool operator < (const my_deque& lhs, const my_deque& rhs) {
            // <your code>
            // you must use std::lexicographical_compare()
            return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
            }

    private:
        // ----
        // data
        // ----

        allocator_type _a;
        int OUTER_SIZE = 1;

        pointer* outer_b;
        pointer* outer_e;
        pointer _bstart;
        pointer _estart;
        pointer _b;
        pointer _e;
        pointer _l;
        int _size;


        // <your data>

    private:
        // -----
        // valid
        // -----

        bool valid () const {
            // <your code>
            return (!_b && !_e && !_l) || ((_b <= _e) && (_e <= _l));
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
                 * <your documentation>
                 */
                friend bool operator == (const iterator& lhs, const iterator& rhs) {
                    // <your code>
                    if ((lhs._index == rhs._index) && (*lhs == *rhs)){
                        return true;
                    }
                    return false;}

                /**
                 * <your documentation>
                 */
                friend bool operator != (const iterator& lhs, const iterator& rhs) {
                    return !(lhs == rhs);}

                // ----------
                // operator +
                // ----------

                /**
                 * <your documentation>
                 */
                friend iterator operator + (iterator lhs, difference_type rhs) {
                    return lhs += rhs;}

                // ----------
                // operator -
                // ----------

                /**
                 * <your documentation>
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
                 * <your documentation>
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
                 * <your documentation>
                 */
                reference operator * () const {
                    // <your code>
                    // dummy is just to be able to compile the skeleton, remove it
                    
                    return (*_d)[_index];}

                // -----------
                // operator ->
                // -----------

                /**
                 * <your documentation>
                 */
                pointer operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
                 * prefix ++ 
                 * Doesn't check out of bounds
                 */
                iterator& operator ++ () {
                    // <your code>
                    ++_index;
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
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
                 * Prefix --
                 * Doesn't check out of bounds
                 */
                iterator& operator -- () {
                    // <your code>
                    --_index;
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
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
                 * <your documentation>
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
                 * <your documentation>
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
                 * <your documentation>
                 */
                friend bool operator == (const const_iterator& lhs, const const_iterator& rhs) {
                    // <your code>
                    if ((lhs._cindex == rhs._cindex) && (*lhs == *rhs)){
                        return true;
                    }
                    return false;
                }

                /**
                 * <your documentation>
                 */
                friend bool operator != (const const_iterator& lhs, const const_iterator& rhs) {
                    return !(lhs == rhs);}

                // ----------
                // operator +
                // ----------

                /**
                 * <your documentation>
                 */
                friend const_iterator operator + (const_iterator lhs, difference_type rhs) {
                    return lhs += rhs;}

                // ----------
                // operator -
                // ----------

                /**
                 * <your documentation>
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
                 * <your documentation>
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
                 * <your documentation>
                 */
                reference operator * () const {
                    // <your code>
                    // dummy is just to be able to compile the skeleton, remove it
                    return (*_cd)[_cindex];}

                // -----------
                // operator ->
                // -----------

                /**
                 * <your documentation>
                 */
                pointer operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
                 * <your documentation>
                 */
                const_iterator& operator ++ () {
                    // <your code>
                    ++_cindex;
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
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
                 * <your documentation>
                 */
                const_iterator& operator -- () {
                    // <your code>
                    --_cindex;
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
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
                 * <your documentation>
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
                 * <your documentation>
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
         * Create a my_deque
         */
        explicit my_deque (const allocator_type& a = allocator_type()) :

                 _a (a) {
                    *outer_b = _a.allocate(OUTER_SIZE);
                    outer_e = outer_b+OUTER_SIZE;
                    _e = _b = _l = 0;
            assert(valid());}

        /**
         * <your documentation>
         */
        explicit my_deque (size_type s, const_reference v = value_type(), const allocator_type& a = allocator_type()) :

            _a (a) {

            *outer_b = _a.allocate(OUTER_SIZE);
            if (OUTER_SIZE == 1){
                // We don't want _b at the very beginning of the allocated block,
                // We want it in the middle

                outer_b[0] = _a.allocate(INNER_SIZE);
                _size = s;
                _bstart = 0;
                _estart = 0;
            }
            // Need something to handle s being bigger than 100 (aka INNER_SIZE)
            while (s > capacity()){
                resize(3*capacity());
            }
            //Set _b & _e
            

            uninitialized_fill(_a, begin(), end(), v);
            assert(valid());}

        /**
         * <your documentation>
         */
        my_deque (const my_deque& that) : 

            _a (that._a) {
            _b = _a.allocate(that.size());
            _e = _l = _b + that.size();
            uninitialized_copy(_a, that.begin(), that.end(), begin());
            assert(valid());}

        // ----------
        // destructor
        // ----------

        /**
         * <your documentation>
         */
        ~my_deque () {
            // <your code>
                if (!empty()) {
                clear();
                _a.deallocate(_b, capacity());}
            assert(valid());}

        // ----------
        // operator =
        // ----------

        /**
         * <your documentation>
         */
        my_deque& operator = (const my_deque& rhs) {
            // <your code>
            // if (this == &rhs)
            //     return *this;
            // if (rhs.size() == size())
            //     std::copy(rhs.begin(), rhs.end(), begin());
            // else if (rhs.size() < size()) {
            //     std::copy(rhs.begin(), rhs.end(), begin());
            //     resize(rhs.size());}
            // else if (rhs.size() <= capacity()) {
            //     std::copy(rhs.begin(), rhs.begin() + size(), begin());
            //     _e = &*uninitialized_copy(_a, rhs.begin() + size(), rhs.end(), end());}
            // else {
            //     clear();
            //     reserve(rhs.size()); 
            //     _e = &*uninitialized_copy(_a, rhs.begin(), rhs.end(), begin());}
            // assert(valid());
            return *this;}

        // -----------
        // operator []
        // -----------

        /**
         * <your documentation>
         */
         reference operator [] (size_type index) {
            if (index >= size())
                throw std::out_of_range("Deque: []");
           return *(begin()+index);}

        // *
        //  * <your documentation>
         
         const_reference operator [] (size_type index) const {
            if (index >= size())
                throw std::out_of_range("Deque: const []");
             return const_cast<my_deque&>(*this)[index];}

        // --
        // at
        // --

        /**
         * <your documentation>
         */
        reference at (size_type index) {
            if (index >= size())
                throw std::out_of_range("Deque: at");
            return *(begin()+index);}

        /**
         * <your documentation>
         */
        const_reference at (size_type index) const {
            return const_cast<my_deque*>(this)->at(index);}

        // ----
        // back
        // ----

        /**
         * <your documentation>
         */
        reference back () {
            assert(!empty());
            return *(end() - 1);}

        /**
         * <your documentation>
         */
        const_reference back () const {
            return const_cast<my_deque*>(this)->back();}

        // -----
        // begin
        // -----

        /**
         * <your documentation>
         */
        iterator begin () {
            
            return iterator(this, 0);
        }

        /**
         * <your documentation>
         */
        const_iterator begin () const {
            // <your code>
            return const_iterator(this, 0);}



        //----------
        // capacity
        // ---------

        /**
         * Helper function for resize, reserve
         */

        size_type capacity () const {
            return _l - _b;}

        // -----
        // clear
        // -----

        /**
         * <your documentation>
         */
        void clear () {
            resize(0);
            assert(valid());}

        // -----
        // empty
        // -----

        /**
         * <your documentation>
         */
        bool empty () const {
            return !size();}

        // ---
        // end
        // ---

        /**
         * <your documentation>
         */
        iterator end () {
            // <your code>
            return iterator(this, 0);}

        /**
         * <your documentation>
         */ 
        const_iterator end () const {
            // <your code>
            return const_iterator(this, 0);}

        // -----
        // erase
        // -----

        /**
         * Change return
         */
        iterator erase (iterator) {
            // <your code>
            assert(valid());
            return iterator(this, 0);}

        // -----
        // front
        // -----

        /**
         * <your documentation>
         */
        reference front () {
            assert(!empty());
            return *begin();}

        /**
         * <your documentation>
         */
        const_reference front () const {
            return const_cast<my_deque*>(this)->front();}

        // ------
        // insert
        // ------

        /**
         * Change return
         */
        iterator insert (iterator, const_reference) {
            // <your code>
            assert(valid());
            return iterator(this, 0);}

        // ---
        // pop
        // ---

        /**
         * <your documentation>
         */
        void pop_back () {
            assert(!empty());
            resize(size() - 1);
            assert(valid());}

        /**
         * <your documentation>
         */
        void pop_front () {
            // <your code>
            assert(valid());}

        // ----
        // push
        // ----

        /**
         * <your documentation>
         */
        void push_back (const_reference v) {
            resize(size() + 1, v);
            assert(valid());}

        /**
         * <your documentation>
         */
        void push_front (const_reference v) {
            // <your code>
            assert(valid());}

        // ------
        // resize
        // ------

        /**
         * <your documentation>
         */
        void resize (size_type s, const_reference v = value_type()) {
            std::cout << size() << std::endl;
            if (s == size())
                return;
            if (s < size())
                _e = &*destroy(_a, begin() + s, end());
            else if (s <= capacity())
                _e = &*uninitialized_fill(_a, end(), begin() + s, v);
            else {
                reserve(std::max(2 * size(), s));
                resize(s, v);}
            assert(valid());}

        //-----------
        // reserve
        // ---------

        /** 
         * Helper function for resize
         */
         void reserve (size_type c) {
            if (c > capacity()) {
                my_deque x(*this);
                // May need a resize here to size c

                swap(x);}
            assert(valid());}

        // ----
        // size
        // ----

        /**
         * <your documentation>
         */
        size_type size () const {
            // <your code>
            std::cout << "e-b "<< _e-_b << std::endl;
            return _e - _b;}

        // ----
        // swap
        // ----

        /**
         * <your documentation>
         */
        void swap (my_deque& rhs) {
            // <your code>
            if (_a == rhs._a) {
                std::swap(_b, rhs._b);
                std::swap(_e, rhs._e);
                std::swap(_l, rhs._l);}
            else {
                my_deque x(*this);
                *this = rhs;
                rhs  = x;}
            assert(valid());}


            };

#endif // Deque_h
