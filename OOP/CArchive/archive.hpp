#pragma once
#define STEP_CAPACITY 15

enum State { empty, busy, deleted };

namespace algorithms {
    template<typename T>
    inline void swap(T& val_1, T& val_2) noexcept {
        T tmp = val_1;
        val_1 = val_2;
        val_2 = tmp;
    }
}

template <typename T>
class TArchive {
    T* _data;                  // динамический массив данных
    State* _states;            // состояния ячеек
    size_t _capacity;          // реальный размер массива
    size_t _size;              // количество хранимых данных
    size_t _deleted;           // количество "удалённых" позиций
public:
    TArchive();
    TArchive(const TArchive& archive);
    TArchive(const T* arr, size_t n);
    TArchive(size_t n, T value);
    TArchive(const TArchive& archive, size_t pos, size_t n);

    ~TArchive();

    void print() const noexcept;

    inline bool empty() const noexcept;
    inline bool full() const noexcept;

    inline size_t size() const noexcept;
    inline size_t capacity() const noexcept;
    inline const T* data() const noexcept;

    void swap(TArchive& archive) noexcept;

    TArchive& assign(const TArchive& archive);

    void clear();
    void resize(size_t n);
    void reserve(size_t n);

    void push_back(T value);             // вставка элемента (в конец)
    void pop_back();                     // удаление элемента (из конца)
    void push_front(T value);            // вставка элемента (в начало)
    void pop_front();                    // удаление элемента (из начала)

    TArchive& insert(T value, size_t pos);

    TArchive& replace(size_t pos, T new_value);

    TArchive& erase(size_t pos, size_t n);
    TArchive& remove_all(T value);
    TArchive& remove_first(T value);
    TArchive& remove_last(T value);
    TArchive& remove_by_index(size_t pos);

    size_t* find_all(T value);
    size_t find_first(T value);
    size_t find_last(T value);
private:
    size_t count_value(T value);
};

template <typename T>
TArchive<T>::TArchive() {
    _size = 0;
    _capacity = STEP_CAPACITY;
    _data = new T[_capacity];
    _states = new State[_capacity];
    _deleted = 0;
    for (size_t i = 0; i < STEP_CAPACITY; i++) {
        _states[i] = State::empty;
    }
}

template <typename T>
TArchive<T>::TArchive(const TArchive& archive) {
    _size = archive._size();
    _capacity = archive._capacity;
    _deleted = archive._deleted;
    _states = new State[_capacity];
    _data = new T[_capacity];
    for (size_t i = 0; i < _size; i++){
        _states[i] = archive._states[i];
        _data[i] = archive._data[i];
    }
}

template <typename T>
TArchive<T>::TArchive(const T* arr, size_t n) {
    _size = n;
    _capacity = (_size * STEP_CAPACITY) / STEP_CAPACITY + STEP_CAPACITY;
    _deleted = 0;
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < _size; i++){
        _data[i] = arr[i];
        _states[i] = State::busy;
    }
}

template <typename T>
TArchive<T>::TArchive(size_t n, T value)
{
    _size = n;
    _capacity = (_size * STEP_CAPACITY) / STEP_CAPACITY + STEP_CAPACITY;
    _deleted = 0;
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < _size; i++){
        _data[i] = value;
        _states[i] = State::busy;
    }
}

template <typename T>
TArchive<T>::TArchive(const TArchive& archive, size_t pos, size_t n)
{
    _size = n;
    _capacity = (_size * STEP_CAPACITY) / STEP_CAPACITY + STEP_CAPACITY;
    _data = new T[_capacity];
    _deleted = 0;
    _states = new State[_capacity];
    for (size_t i = 0; i < _size; i++)
    {
        _data[i] = archive._data[pos + i];
        _states[i] = archive._states[pos + i];
        if (_states[i] == State::deleted) _deleted++;
    }

}

template <typename T>
TArchive<T>::~TArchive() {
    delete[] _data;
    _data = nullptr;
}

template <typename T>
inline bool TArchive<T>::empty() const noexcept {
    return _size == 0;
}

template <typename T>
inline bool TArchive<T>::full() const noexcept {
    return _size == _capacity;
}

template <typename T>
inline size_t TArchive<T>::size() const noexcept{
    return _size;
}

template<typename T>
inline size_t TArchive<T>::capacity() const noexcept{
    return _capacity;
}

template<typename T>
inline const T* TArchive<T>::data() const noexcept{
    return _data;
}

template<typename T>
void TArchive<T>::swap(TArchive& archive) noexcept
{
    TArchive temp(this);
    if (temp.empty() || this->empty()) { throw std::logic_error("Error in function \"void swap(TArchive& archive)\": One of the archives was empty."); }

    _size = archive._size;
    _capacity = archive._capacity;
    _deleted = archive._deleted;

    delete[] _data;
    _data = new T[_capacity];
    delete[] _states;
    _states = new State[_capacity];

    for (size_t i = 0; _size; i++)
    {
        _states[i] = archive._states[i];
        _data[i] = archive._data[i];
    }

    archive._size = temp._size;
    archive._capacity = temp._capacity;
    archive._deleted = temp._deleted;

    delete[] archive._data;
    archive._data = new T[_capacity];
    delete[] archive._states;
    archive._states = new State[_capacity];

    for (size_t i = 0; archive._size; i++)
    {
        archive._states[i] = temp._states[i];
        archive._data[i] = temp._data[i];
    }
}

template<typename T>
TArchive<T>& TArchive<T>::assign(const TArchive& archive)
{
    _size = archive._size;
    _capacity = archive._capacity;
    _deleted = archive._deleted;

    _data = new T[_capacity];
    _states = new State[_capacity];

    for (size_t i = 0; i < _size; i++)
    {
        _data = archive._data[i];
        _states = archive._states[i];
    }

    return *this;
}

template <typename T>
void TArchive<T>::clear()
{
    delete[] _data;
    delete[] _states;
    _size = 0;
    _capacity = STEP_CAPACITY;
    _data = new T[_capacity];
    _states = new State[_capacity];
    _deleted = 0;
    for (size_t i = 0; i < STEP_CAPACITY; i++) {
        _states[i] = State::empty;
    }
}

template <typename T>
void TArchive<T>::resize(size_t n)
{
    T* oldata = new T[_capacity];
    State* oldState = new State[_capacity];
    for (size_t i = 0; i<_capacity; i++)
    {
        oldata[i] = _data[i];
        oldState[i] = _states[i];
    }

	_capacity = ((_capacity + n) / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < _capacity; i++)
    {
        _data[i] = oldata[i];
        _states[i] = oldState[i];
    }
    for (size_t i = _capacity; i<_capacity + n; i++){
        _states[i] = State::empty;
    }
}
template <typename T>
void TArchive<T>::reserve(size_t n)
{
	while (_deleted!=0)
	{
        for (size_t i = 0; i < _size; i++)
        {
            if (_states[i] == State::deleted)
            {
                _states[i] = State::busy;
                for (size_t q = 0; i + q < _size; q++) {
                    _data[i + q] = _data[i + q + 1];
                }
                _size--;
                _deleted--;
                break;
            }
        }
	}
    for (size_t i = _size; i < _capacity; i++) {
        _states[i] = State::empty;
    }
    if (this->full()) this->resize(n);
}
 
template<typename T>
inline void TArchive<T>::push_back(T value)
{
    this->insert(value, _size);
}

template<typename T>
inline void TArchive<T>::pop_back()
{
    this->remove_by_index(_size - 1);
}

template<typename T>
inline void TArchive<T>::push_front(T value)
{
    this->insert(value, 0);
}

template<typename T>
inline void TArchive<T>::pop_front()
{
    this->remove_by_index(0);
}


template <typename T>
TArchive<T>& TArchive<T>::insert(T value, size_t pos) {
    if (_size < pos) {
        throw std::logic_error("Error in function \
\"TArchive<T>& insert(T value, size_t pos)\": wrong position value.");
    }
    
    // действия при переполнении
    if (this->full()) {
        this->reserve(15);
        // + внутри reserve() исключение, если достигнем масимально
        // возможного значения _capacity
    }
    
    for (size_t i = _size; i > pos; i--) {
        _data[i] = _data[i - 1];
    }
    _data[pos] = value;
    _states[pos] = State::busy;
    _size++;
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::replace(size_t pos, T new_value)
{
    if (_size < pos) { throw std::logic_error("Error in function \"TArchive<T>& TArchive<T>::replace(size_t pos, T new_value)\": wrong position value."); }
    _data[pos] = new_value;
    return *this;
}

template<typename T>
TArchive<T>& TArchive<T>::erase(size_t pos, size_t n)
{
    for (size_t i = 0; i < n; i++){
        _data[pos + i] = NULL;
        _states[pos + i] = State::deleted;
        _deleted++;
    }
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::remove_all(T value)
{
    if (this->empty()) throw std::logic_error("Error in function \"TArchive<T>& TArchive<T>::remove_all(T value)\": Archive is empty.");

    size_t* pos = this->find_all(value);
    if (pos == nullptr) throw std::logic_error("Error in function \"TArchive<T>& TArchive<T>::remove_all(T value)\": No matching value found.");

    for (size_t i = 1; i <= pos[0]; i++)
    {
        _states[pos[i]] = State::deleted; 
        _deleted++;
    }

    return *this;
}

template<typename T>
TArchive<T>& TArchive<T>::remove_first(T value)
{
    if (this->empty()) throw std::logic_error("Error in function \"TArchive<T>& TArchive<T>::remove_first(T value)\": Archive is empty.");

    size_t pos = this->find_first(value);
    if (pos == -1) throw std::logic_error("Error in function \"TArchive<T>& TArchive<T>::remove_first(T value)\": position is not found.");

    _states[pos] = State::deleted;
    _deleted++;

    return *this;
}

template<typename T>
TArchive<T>& TArchive<T>::remove_last(T value)
{
    if (this->empty()) throw std::logic_error("Error in function \"TArchive<T>& TArchive<T>::remove_first(T value)\": Archive is empty.");

    size_t pos = this->find_last(value);
    if (pos == -1) throw std::logic_error("Error in function \"TArchive<T>& TArchive<T>::remove_first(T value)\": position is not found.");

    _states[pos] = State::deleted;
    _deleted++;

    return *this;
}

template<typename T>
 TArchive<T>& TArchive<T>::remove_by_index(size_t pos)
{
     if (pos == _size) 
         _states[pos] = State::empty;
     else 
         _states[pos] = State::deleted;

     _deleted++;
     return *this;
}

 template<typename T>
 size_t* TArchive<T>::find_all(T value)
 {
     size_t count = this->count_value(value);
     if (count == 0) { return nullptr; }
     size_t* found_positions = new size_t[count + 1];
     found_positions[0] = count;

     for (size_t i = 0, j = 1; j < count + 1; i++)
     {
         if (_data[i] == value){
         	found_positions[j] = i;
         	j++;
         }
     }

     return found_positions;
 }

 template<typename T>
 size_t TArchive<T>::find_first(T value)
 {
     for (size_t i = 0; i < _size; i++)
     {
         if (_data[i] == value) 
             return i; 
     }
     return -1;
 }

 template<typename T>
 inline size_t TArchive<T>::find_last(T value)
 {
     size_t found_positions = -1;
     for (size_t i = 0; i < _size; i++)
     {
         if (_data[i] == value) 
             found_positions = i; 
     }
     return found_positions;
 }

 template<typename T>
 size_t TArchive<T>::count_value(T value){
     size_t count = 0;
     for (size_t i = 0; i <= this->_size; i++)
         if (this->_data[i] == value) 
             count++;
     return count;
 }

template <typename T>
void TArchive<T>::print() const noexcept {
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] != State::deleted) {
            std::cout << _data[i] << ", ";
        }
    }
}