#include "string.hpp"

/// <summary>
/// ����������� �� ���������.
/// </summary>
CString::CString()
{
	size_ = 0;
	capacity_ = step_capacity;
	data_ = new char[capacity_];
	data_[0] = '\0';
}

/// <summary>
/// ����������� �����������.
/// </summary>
/// <param name="str"> - ���������� ������</param>
CString::CString(const CString& str)
{
	size_ = str.size_;
	capacity_ = str.capacity_;
	data_ = new char[capacity_];
	for (size_t i = 0; i = size_ - 1; i++)
	{
		data_[i] = str.data_[i];
	}
	data_[size_-1] = '\0';
}

/// <summary>
/// ����������� ������
/// </summary>
/// <param name="c_str"> - ������.</param>
CString::CString(const char* c_str)
{
	size_ = 0;
	while (c_str[size_] != '\0') size_++;

	capacity_ = (size_ / step_capacity) * step_capacity + step_capacity;
	data_ = new char[capacity_];
	for (size_t i = 0; i < size_; i++)
	{
		data_[i] = c_str[i];
	}
	data_[size_] = '\0';
}

/// <summary>
/// ����������� ������ � ������������ ������������ ��������
/// </summary>
/// <param name="c_str"> - ������.</param>
/// <param name="n"> - ���-�� ��������.</param>
CString::CString(const char* c_str, size_t n)
{
	size_ = 0;
	while (c_str[size_] != '\0' && size_ < n) size_++;

	capacity_ = (size_ / step_capacity) * step_capacity + step_capacity;
	data_ = new char[capacity_];
	for (size_t i = 0; i < size_; i++)
	{
		data_[i] = c_str[i];
	}
	data_[size_] = '\0';
}

/// <summary>
/// �����������, ��������� ����� ������� n ���
/// </summary>
/// <param name="n"> - ���-�� ����� �������.</param>
/// <param name="c"> - ������.</param>
CString::CString(size_t n, char c)
{
	size_ = n;
	capacity_ = (size_ / step_capacity) * step_capacity + step_capacity;
	data_ = new char[capacity_];
	for (size_t i = 0; i < size_; i++)
	{
		data_[i] = c;
	}
	data_[size_] = '\0';
}

/// <summary>
/// ����������� ������� "��������" �����
/// </summary>
/// <param name="str"> - ������</param>
/// <param name="pos"> - ������� ������</param>
/// <param name="len"> - ���-�� ��������</param>
CString::CString(const CString& str, size_t pos, size_t len)
{
	if (pos + len > str.size_)
		throw CString("No enough size");
	size_ = len;

	capacity_ = (size_ / step_capacity) * step_capacity + step_capacity;
	delete[] data_;
	data_ = new char[capacity_];
	for (size_t i = 0; i < size_; i++)
	{
		data_[i] = str.data_[pos + i];
	}
	data_[size_] = '\0';
}

/// <summary>
/// ����������.
/// </summary>
CString::~CString()
{
	delete[] data_;
	data_ = nullptr;
}

/// <summary>
/// ����� ������ � �������
/// </summary>
void CString::print() const noexcept
{
	std::cout << data_ << '\n';
}

/// <summary>
/// �������� ������ �� �������.
/// </summary>
bool CString::empty() const noexcept
{
	return size_ == 0;
}

/// <summary>
/// �������� ������ �� �������������.
/// </summary>
bool CString::full() const noexcept
{
	return size_ == capacity_;
}

/// <summary>
/// �������� ������ �� ������������.
/// </summary>
bool CString::overflow() const noexcept
{
	return size_ > capacity_;
}


/// <summary>
/// ������ ��� ������� ������.
/// </summary>
/// <returns>������ (�����) ������</returns>
size_t CString::size() const noexcept
{
	return size_;
}

/// <summary>
/// ������ ��� ������� ���������
/// </summary>
/// <returns>������ (�����) ������ </returns>
size_t CString::capacity() const noexcept
{
	return capacity_;
}

/// <summary>
/// ������ ��� ���������
/// </summary>
/// <returns>��������� � ���� char*</returns>
const char* CString::data() const
{
	return data_;
}

/// <summary>
/// ������ ������� ������ ���� �������
/// </summary>
void CString::swap(CString& str) noexcept
{
	CString& temp(str);

	str.size_ = size_;
	str.capacity_ = capacity_;
	str.data_ = data_;

	size_ = temp.size();
	capacity_ = temp.capacity();
	for (size_t i = 0; i < size_; i++) 
		data_[i] = temp.data_[i];
}

/// <summary>
/// �������� ������� ������ � ���������� ����������
/// </summary>
size_t CString::copy(char* buf, size_t len, size_t pos) const
{
	for (size_t i = 0; i < len; i++)
		buf[i] = data_[pos + i];
	return len;
}

/// <summary>
/// �������� ������� ������ � ����� �����
/// </summary>
CString CString::substr(size_t pos, size_t len) const
{
	CString temp;
	temp.size_ = len;
	for (size_t i = 0; i < size_; i++)
		if (i >= pos && i <= pos + len)
			temp.data_[i] = data_[i];
	temp.capacity_ = (temp.size_ / step_capacity) * step_capacity + step_capacity;
	temp.data_[temp.size_] = '\0';

	return temp;
}

/// <summary>
/// �������� ��� ������ �� ����������� ������
/// </summary>
CString& CString::assign(const CString& str)
{
	size_ = str.size_;
	capacity_ = str.capacity_;
	data_ = new char[capacity_];
	for (size_t i = 0; i < size_; i++)
		data_[i] = str.data_[i];
	data_[size_] = '\0';
	return *this;
}

/// <summary>
/// �������� ������� ������ �� ����������� ������
/// </summary>
CString& CString::assign(const CString& str, size_t pos, size_t len)
{
	size_ = len;
	capacity_ = (size_ / step_capacity) * step_capacity + step_capacity;
	data_ = new char[capacity_];
	for (size_t i = 0; i < size_; i++)
		data_[i] = str.data_[pos + i];
	data_[size_] = '\0';
	return *this;
}

/// <summary>
/// �������� ������ �� ������� char
/// </summary>
CString& CString::assign(const char* s)
{
	size_ = 0;
	while (s[size_] != '\0')
		size_++;
	capacity_ = (size_ / step_capacity) * step_capacity + step_capacity;
	data_ = new char[capacity_];
	for (size_t i = 0; i < size_; i++)
		data_[i] = s[i];
	data_[size_] = '\0';
	return *this;
}

/// <summary>
/// �������� ������ �� ������� char ������ �� n-��� �������
/// </summary>
CString& CString::assign(const char* s, size_t n)
{
	size_ = 0;
	while (s[size_] != '\0')
		size_++;
	size_ = n;
	capacity_ = (n / step_capacity) * step_capacity + step_capacity;
	data_ = new char[capacity_];
	for (size_t i = 0; i < n; i++)
		data_[i] = s[i];
	data_[n] = '\0';
	return *this;
}

/// <summary>
/// �������� ������ n ���
/// </summary>
CString& CString::assign(size_t n, char c)
{
	size_ = n;
	capacity_ = (size_ / step_capacity) * step_capacity + step_capacity;
	data_ = new char[capacity_];
	for (size_t i = 0; i < size_; i++)
		data_[i] = c;
	data_[size_] = '\0';
	return *this;
}

/// <summary>
/// ������� ��������� (�������������������).
/// </summary>
int CString::compare(const CString& str) const noexcept
{
	for (size_t i = 0; i < algorithms::min(size_, str.size_); i++)
	{
		if (this->data_[i] < str.data_[i]) return 1;
		else if (this->data_[i] > str.data_[i]) return -1;
	}
	if (this->size_ > str.size_) return 1;
	else if (this->size_ < str.size_) return -1;
	else return 0;
}

/// <summary>
/// ������� ��������� �������
/// </summary>
int CString::compare(size_t pos, size_t len, const CString& str) const
{
	for (size_t i = 0; i < algorithms::min(len, str.size_); i++)
	{
		if (this->data_[pos + i] < str.data_[i]) return 1;
		else if (this->data_[pos + i] > str.data_[i]) return -1;
	}
	if (len > str.size_) return 1;
	else if (len < str.size_) return -1;
	else return 0;
}

/// <summary>
/// ������� ��������� ��������
/// </summary>
int CString::compare(size_t pos, size_t len, const CString& str, size_t subpos, size_t sublen) const
{
	for (size_t i = 0; i < algorithms::min(len, sublen); i++)
	{
		if (this->data_[pos + i] < str.data_[subpos + i]) return 1;
		else if (this->data_[pos + i] > str.data_[subpos + i]) return -1;
	}
	if (len > sublen) return 1;
	else if (len < sublen) return -1;
	else return 0;
}

/// <summary>
/// ������� ��������� � �������
/// </summary>
int CString::compare(const char* s) const
{
	for (size_t i = 0; i < algorithms::min(size_, sizeof(s)); i++)
	{
		if (this->data_[i] < s[i]) return 1;
		else if (this->data_[i] > s[i]) return -1;
	}
	if (this->size_ > sizeof(s)) return 1;
	else if (this->size_ < sizeof(s)) return -1;
	else return 0;
}

/// <summary>
/// ������� ��������� ������� � �������
/// </summary>
int CString::compare(size_t pos, size_t len, const char* s) const
{
	for (size_t i = 0; i < algorithms::min(len, sizeof(s)); i++)
	{
		if (this->data_[pos + i] < s[i]) return 1;
		else if (this->data_[pos + i] > s[i]) return -1;
	}
	if (this->size_ > sizeof(s)) return 1;
	else if (this->size_ < sizeof(s)) return -1;
	else return 0;
}

/// <summary>
/// ������� ��������� ������� � �������� ������
/// </summary>
int CString::compare(size_t pos, size_t len, const char* s, size_t n) const
{
	for (size_t i = 0; i < algorithms::min(len, n); i++)
	{
		if (this->data_[pos + i] < s[i]) return 1;
		else if (this->data_[pos + i] > s[i]) return -1;
	}
	if (this->size_ > n) return 1;
	else if (this->size_ < n) return -1;
	else return 0;
}

/// <summary>
/// ������� ���������
/// </summary>
void CString::clear() noexcept
{
	size_ = 0;
	capacity_ = step_capacity;
	delete[] data_;
	data_ = new char[capacity_];
	data_[0] = '\0';
}

/// <summary>
/// ������������� ������ ���������
/// </summary>
void CString::resize(size_t n)
{
	size_ = n;
	if (n > capacity_)
		capacity_ = (size_ / step_capacity) * step_capacity + step_capacity;
	delete[] data_;
	data_ = new char[capacity_];
	data_[size_] = '\0';
}

/// <summary>
/// ����������� ������ ���������
/// </summary>
void CString::reserve(size_t n)
{
	size_ += n;
	if (n > size_)
		capacity_ = (n / step_capacity) * step_capacity + step_capacity;
	delete[] data_;
	data_ = new char[capacity_];

}

/// <summary>
/// ������� ������� � ����� ������.
/// </summary>
/// <param name="c"> - ������ ��� �������</param>
void CString::push_back(char c)
{
	if (this->full())
		this->reserve(capacity_);
	data_[size_] = c;
	data_[++size_] = '\0';
}

/// <summary>
/// �������� ������� �� ����� ������.
/// <exception cref="std::logic_error">����������, ���� �������� ������ �����.</exception>
/// </summary>
void CString::pop_back()
{
	if (this->empty())
	{
		throw std::logic_error("Error in function \
                  \"void pop_back()\": source CString is empty");
	}
	data_[--size_] = '\0';
}

/// <summary>
/// �������� �������
/// </summary>
CString& CString::erase(size_t pos, size_t len)
{
	if (len + pos > size_) throw std::invalid_argument("unmatching size for CString imput");

	CString Temp;
	for (size_t i = 0; i < size_; i++)
		if (!(i >= pos && i <= pos + len))
			Temp.data_[i] = data_[i];
	Temp.size_ = size_ - len;
	Temp.capacity_ = (Temp.size_ / step_capacity) * step_capacity + step_capacity;
	delete[] Temp.data_;
	Temp.data_ = new char[capacity_];
	Temp.data_[Temp.size_] = '\0';
	this->swap(Temp);
	return *this;
}

/// <summary>
/// ���������� ����� �� ������
/// </summary>
CString& CString::append(const CString& str)
{
	size_t temp = size_;
	size_ += str.size_;
	for (size_t i = 0; i < str.size_; i++)
		data_[temp + i] = str.data_[i];
	data_[size_] = '\0';
	if (this->full() || this->overflow())
		capacity_ = (size_ / step_capacity) * step_capacity + step_capacity;
	return *this;
}

/// <summary>
/// ���������� ������� �� ������
/// </summary>
CString& CString::append(const CString& str, size_t subpos, size_t sublen)
{
	CString str_2 = str.substr(subpos, sublen);
	size_t temp = size_;
	size_ += str_2.size_;
	for (size_t i = 0; i < str_2.size_; i++)
		data_[temp + i] = str_2.data_[i];
	data_[size_] = '\0';
	if (this->full() || this->overflow())
		capacity_ = (size_ / step_capacity) * step_capacity + step_capacity;
	return *this;
}

/// <summary>
/// ���������� ����� �� ������� char
/// </summary>
CString& CString::append(const char* s)
{
	size_t temp = size_;
	size_ += sizeof(s);
	for (size_t i = 0; i < sizeof(s); i++)
		data_[temp + i] = s[i];
	data_[size_] = '\0';
	if (this->full() || this->overflow())
		capacity_ = (size_ / step_capacity) * step_capacity + step_capacity;
	return *this;
}

/// <summary>
/// ���������� ������� �� ������� char
/// </summary>
CString& CString::append(const char* s, size_t n)
{
	size_t temp = size_;
	size_ += n;
	for (size_t i = 0; i < n; i++)
		data_[temp + i] = s[i];
	data_[size_] = '\0';
	if (this->full() || this->overflow())
		capacity_ = (size_ / step_capacity) * step_capacity + step_capacity;
	return *this;
}

/// <summary>
/// ���������� ����� ������� n ���
/// </summary>
CString& CString::append(size_t n, char c)
{
	size_t temp = size_;
	size_ += n;
	for (size_t i = 0; i < n; i++)
		data_[temp + i] = c;
	data_[size_] = '\0';
	if (this->full() || this->overflow())
		capacity_ = (size_ / step_capacity) * step_capacity + step_capacity;
	return *this;
}

/// <summary>
/// ������� ������ ����� �������� ������� � ��������.
/// </summary>
CString& CString::insert(size_t pos, const CString& str)
{
	CString begin(*this, 0, pos);
	CString end(*this, pos, size_ - pos);
	begin.append(str);
	begin.append(end);
	this->swap(begin);
	return *this;
}

/// <summary>
/// ������� ������� ����� �������� ������� � ��������.
/// </summary>
CString& CString::insert(size_t pos, const CString& str, size_t subpos, size_t sublen)
{
	CString begin(*this, 0, pos);
	CString end(*this, pos, size_ - pos);
	CString Temp(str, subpos, sublen);

	begin.append(Temp);
	begin.append(end);
	this->swap(begin);
	return *this;
}

/// <summary>
/// ������� ������ ����� �������� ������� � ��������.
/// </summary>
CString& CString::insert(size_t pos, const char* s)
{
	CString begin(*this, 0, pos);
	CString end(*this, pos, size_ - pos);
	CString Temp(s);

	begin.append(Temp);
	begin.append(end);
	this->swap(begin);
	return *this;
}

/// <summary>
/// ������� ������� ����� �������� ������� � ��������.
/// </summary>
CString& CString::insert(size_t pos, const char* s, size_t n)
{
	CString begin(*this, 0, pos);
	CString end(*this, pos, size_ - pos);
	CString Temp(s, n);

	begin.append(Temp);
	begin.append(end);
	this->swap(begin);
	return *this;
}

/// <summary>
/// ������� ������� n ��� ����� �������� ������� � ��������.
/// </summary>
CString& CString::insert(size_t pos, size_t n, char c)
{
	CString begin(*this, 0, pos);
	CString end(*this, pos, size_ - pos);
	CString Temp(n, c);

	begin.append(Temp);
	begin.append(end);
	this->swap(begin);
	return *this;
}

/// <summary>
/// ������ ������� � ������
/// </summary>
CString& CString::replace(size_t pos, size_t len, const CString& str)
{
	for (size_t i = 0; i < len; i++) this->data_[pos + i] = str.data_[i];
	return *this;
}

/// <summary>
/// ������ ������� � ������
/// </summary>
CString& CString::replace(size_t pos, size_t len, const CString& str, size_t subpos, size_t sublen)
{
	if (len + pos > this->size_ || subpos + sublen > str.size_) throw std::invalid_argument(
		"unmatching size for CString imput");
	if (str.empty()) throw std::invalid_argument("unmatching size for CString imput");
	CString Temp = str.substr(subpos, sublen);
	for (size_t i = 0; i < len; i++)
		this->data_[pos + i] = Temp.data_[i];
	return *this;
}

/// <summary>
/// ������ ������� � ������
/// </summary>
CString& CString::replace(size_t pos, size_t len, const char* s, size_t n)
{
	if (len + pos > this->size_) throw std::invalid_argument("unmatching size for CString imput");
	for (size_t i = 0; i < algorithms::min(this->size_, n); i++)
		this->data_[pos + i] = s[i];
	return *this;
}

/// <summary>
/// ������ ������� � ������ �� ������
/// </summary>
CString& CString::replace(size_t pos, size_t len, size_t n, char c)
{
	if (len + pos > this->size_) throw std::invalid_argument("unmatching size for CString imput");
	for (size_t i = 0; i < len; i++)
		this->data_[pos + i] = c;
	return *this;
}

/// <summary>
/// ����� �������
/// </summary>
size_t CString::find(const CString& str) const
{
	size_t pos = 0;
	if (str.empty()) throw std::invalid_argument("The CString data is empty");

	for (size_t i = 0, j = 0; i < size_ && j < str.size_;)
	{
		if (data_[i] == str.data_[j])
		{
			if (j == 0)
				pos = i;
			j++;
			i++;
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return pos;
}

/// <summary>
/// ����� �������
/// </summary>
size_t CString::find(const char* s) const
{
	size_t pos = 0;
	size_t ssize = 0;
	while (s[ssize] != '\0') ssize++;

	for (size_t i = 0, j = 0; i < size_ && j < ssize;)
	{
		if (data_[i] == s[j])
		{
			if (j == 0)
				pos = i;
			j++;
			i++;
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return pos;
}

/// <summary>
/// ����� �������
/// </summary>
size_t CString::find(const char* s, size_t n) const
{
	size_t pos = 0;
	size_t ssize = 0;
	while (s[ssize] != '\0') { ssize++; }
	if (n > ssize) throw std::invalid_argument("Incorrect imput");
	ssize = n;

	for (size_t i = 0, j = 0; i < size_ && j < n;)
	{
		if (data_[i] == s[j])
		{
			if (j == 0)
				pos = i;
			j++;
			i++;
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return pos;
}

/// <summary>
/// ����� �������
/// </summary>
size_t CString::find(char c, size_t start) const
{
	size_t pos = 0;
	for (size_t i = start; i < size_; i++)
		if (data_[i] == c)
			pos = i;
	return pos;
}

/// <summary>
/// ����� ������� ���������� � �������� ������ � ����� �� �������� �������� ������.
/// </summary>
size_t CString::find_first_of(const CString& str) const
{
	if (str.empty()) throw std::invalid_argument("unmatching size for CString imput");
	for (size_t i = 0; i < size_; i++)
		for (size_t j = 0; j < str.size_; j++)
			if (data_[i] == str.data_[j])
				return i;
	return -1;
}

/// <summary>
/// ����� ������� ���������� � �������� ������ � ����� �� �������� �������� ������.
/// </summary>
size_t CString::find_first_of(const char* s) const
{
	size_t fsize = 0;
	while (s[fsize] != '\0') fsize++;
	for (size_t i = 0; i < size_; i++)
		for (size_t j = 0; j < fsize; j++)
			if (data_[i] == s[j])
				return i;
	return -1;
}

/// <summary>
/// ����� ������� ���������� � �������� ������ � ����� �� �������� �������� ������.
/// </summary>
size_t CString::find_first_of(const char* s, size_t n) const
{
	size_t fsize = 0;
	while (s[fsize] != '\0') fsize++;
	if (n > fsize) throw std::invalid_argument("Incorrect imput.");
	for (size_t i = 0; i < size_; i++)
		for (size_t j = 0; j < n; j++)
			if (data_[i] == s[j])
				return i;
	return -1;
}

/// <summary>
/// ����� ������� ���������� � �������� ������ � �������� .
/// </summary>
size_t CString::find_first_of(char c) const
{
	for (size_t i = 0; i < size_; i++)
		if (data_[i] == c)
			return i;
	return -1;
}

/// <summary>
/// ����� ������� ������������ � �������� ������ � ����� �� �������� �������� ������.
/// </summary>
size_t CString::find_first_not_of(const CString& str) const
{
	if (str.empty()) throw std::invalid_argument("unmatching size for CString imput");
	bool found_not = 1;
	for (size_t i = 0; i < size_; i++)
	{
		size_t count = 0;
		do
		{
			if (str.data_[count] == data_[i])
				found_not = 0;
			count++;
		}
		while (count < str.size_);
		if (found_not)
			return i;
	}
	return -1;
}

/// <summary>
/// ����� ������� ������������ � �������� ������ � ����� �� �������� �������� ������.
/// </summary>
size_t CString::find_first_not_of(const char* s) const
{
	size_t len = 0;
	while (s[len] != '/0') len++;

	bool found_not = 1;

	for (size_t i = 0; i < size_; i++)
	{
		size_t count = 0;
		do
		{
			if (s[count] == data_[i]) { found_not = 0; }
			count++;
		}
		while (count < len);
		if (found_not) return i;
	}
	return -1;
}

/// <summary>
/// ����� ������� ������������ � �������� ������ � ����� �� �������� �������� ������.
/// </summary>
size_t CString::find_first_not_of(const char* s, size_t n) const
{
	size_t len = 0;
	while (s[len] != '/0') len++;
	if (n > len) throw std::invalid_argument("unmatching size for CString imput");
	bool found_not = 1;

	for (size_t i = 0; i < size_; i++)
	{
		size_t count = 0;
		do
		{
			if (s[count] == data_[i]) { found_not = 0; }
			count++;
		}
		while (count < n);
		if (found_not) return i;
	}
	return -1;
}

/// <summary>
/// ����� ������� ������������ � �������� ������ � ��������.
/// </summary>
size_t CString::find_first_not_of(char c) const
{
	for (size_t i = 0; i < size_; i++)
		if (data_[i] != c)
			return i;
	return -1;
}
