#if !defined(_DirectoryIterator_h)
#define _DirectoryIterator_h

#include <Arduino.h>
#include <FS.h>

class DirectoryIterator
{
public:
	using iterator_category = std::input_iterator_tag;
	using value_type = const File;
	using difference_type = std::ptrdiff_t;
	using pointer = value_type *;
	using reference = value_type &;

	DirectoryIterator(const File &root);

	DirectoryIterator &operator++();
	DirectoryIterator operator++(int);
	bool operator==(const DirectoryIterator &other) const;
	bool operator!=(const DirectoryIterator &other) const;
	reference operator*() const;
	pointer operator->() const;

	DirectoryIterator begin() const { return *this; }
	DirectoryIterator end() const { return DirectoryIterator(File()); }

private:
	File _root;
	File _entry;
};

#endif // _DirectoryIterator_h
