#include "IntegerArray.h"

// Exceptions methods
const char* bad_length::what() const noexcept
{
    return "ERROR: Bad length of array!";
}
const char* bad_range::what() const noexcept
{
    return "ERROR: Bad range of array!";
}
// IntegerArray methods
IntegerArray::IntegerArray(int length) :
    m_length{ length }
{
    if (length < 0)
        throw bad_length();
    if (length > INT_MAX)
        throw bad_length();
    if (length > 0)
        m_data = new int[length] {};
    else
        m_data = nullptr;
}
IntegerArray::IntegerArray(IntegerArray& copy)
{
    m_length = copy.getLength();
    m_data = new int[m_length];
    for (int i(0); i < m_length; i++)
        m_data[i] = copy[i];
}
IntegerArray::~IntegerArray()
{
    delete[] m_data;
}
void IntegerArray::erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}
int& IntegerArray::operator[](int index)
{
    if (index < 0 || index >= m_length)
        throw bad_range();
    return m_data[index];
}
void IntegerArray::resize(int newLength)
{
    // if the array is already the right length, we're done
    if (newLength == m_length)
        return;

    if (newLength < 0)
        throw bad_length();
    // If we are resizing to an empty array, do that and return
    if (newLength == 0)
    {
        erase();
        return;
    }
    int* data{ new int[newLength] };

    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
        int index = 0;
        for (; index < elementsToCopy; ++index)
            data[index] = m_data[index];
        if (newLength > m_length)
            while (index < newLength)
            {
                data[index] = 0;
                index++;
            }
                
    }

    delete[] m_data;

    m_data = data;
    m_length = newLength;
}
void IntegerArray::findElement(const int index) const                                       // поиск элемента по индексу
{
    if (index < 0 || index >= m_length)
        throw bad_range();
    std::cout << "\nThe element " << index << " was founded! It equals " << m_data[index] << std::endl;
}
void IntegerArray::insertBefore(int value, int index)
{
    if (index < 0 || index > m_length)
        throw bad_range();

    int* data = new int[m_length + 1];

    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];

    data[index] = value;

    for (int after{ index }; after < m_length; ++after)
        data[after + 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    ++m_length;
}
void IntegerArray::remove(int index)
{

    if (index < 0 || index >= m_length)
        throw bad_range();

    if (m_length == 1)
    {
        erase();
        return;
    }

    int* data{ new int[m_length - 1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];

    for (int after{ index + 1 }; after < m_length; ++after)
        data[after - 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    --m_length;
}
void IntegerArray::insertAtBeginning(int value) { insertBefore(value, 0); }
void IntegerArray::insertAtEnd(int value) { insertBefore(value, m_length); }
int IntegerArray::getLength() const { return m_length; }
void IntegerArray::copyContainerTo(IntegerArray& to)                                    // Копирование контейнера если их размеры равны
{
    if (this == &to)
        return;
    if (to.getLength() != this->getLength())
        throw bad_length();
    for (int i(0); i < to.getLength(); i++)
        to[i] = (*this)[i];
}
std::ostream& operator<<(std::ostream& os, IntegerArray& container)
{
    for (int i(0); i < container.getLength(); i++)
        os << container[i] << " ";
    return os;
}