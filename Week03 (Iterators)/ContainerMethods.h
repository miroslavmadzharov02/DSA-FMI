#ifndef CONTAINERMETHODS__
#define CONTAINERMETHODS__

namespace ContainerMethods
{
	//function parameters aren't const because iterator isn't either :/

	template <typename func, typename container>
	void map(func f, container& vec);

	template <typename container>
	bool duplicates(container& vec);

	template <typename container>
	bool isSortedAscending(container& vec);

	template <typename container>
	bool isSortedDescending(container& vec);

	template <typename container>
	bool palindrome(container& vec);
};

#include "ContainerMethods.inl"
#endif 