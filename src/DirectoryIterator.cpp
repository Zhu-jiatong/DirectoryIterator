#include "DirectoryIterator.h"

DirectoryIterator::DirectoryIterator(const File &root)
	: _root(root), _entry(_root.openNextFile())
{
}

DirectoryIterator &DirectoryIterator::operator++()
{
	_entry = _root.openNextFile();
	return *this;
}

DirectoryIterator DirectoryIterator::operator++(int)
{
	DirectoryIterator tmp(*this);
	operator++();
	return tmp;
}

bool DirectoryIterator::operator==(const DirectoryIterator &other) const
{
	return _entry == other._entry;
}

bool DirectoryIterator::operator!=(const DirectoryIterator &other) const
{
	return !(*this == other);
}

DirectoryIterator::reference DirectoryIterator::operator*() const
{
	return _entry;
}

DirectoryIterator::pointer DirectoryIterator::operator->() const
{
	return &_entry;
}
